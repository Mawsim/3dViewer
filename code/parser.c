#include "parser.h"

int load_from_file(const char *filename, float **vertices, int *num_vertices,
                   unsigned **indices, int *num_indices) {
  int result = 1;
  FILE *file = fopen(filename, "r");
  if (file) {
    *num_vertices = 0;
    *num_indices = 0;
    setlocale(LC_NUMERIC, "C"); // Важное исправление!

    MINMAX mm = first_reading(file, num_vertices);
    if (*num_vertices == 0) {
      fclose(file);
      return 1;
    }

    unsigned **matrix = matrix_alloc(num_vertices);
    POINT *points = (POINT *)calloc(*num_vertices, sizeof(POINT));
    if (points && matrix) {
      rewind(file);
      int vertex_count = 0;
      char str[256];
      while (fgets(str, sizeof(str), file)) {
        char *ptr_str = str;
        while (*ptr_str == ' ') ptr_str++;
        if (*ptr_str == 'v' && *(ptr_str + 1) == ' ') {
          read_vertex(&points, ptr_str, mm, &vertex_count);
        }
        if (*ptr_str == 'f' && *(ptr_str + 1) == ' ') {
          read_surface(matrix, ptr_str, num_indices, *num_vertices);
        }
      }

      *indices = (unsigned *)calloc(*num_indices, sizeof(unsigned));
      if (*indices) {
        int segments_count = 0;
        for (int i = 0; i < *num_vertices; i++) {
          for (unsigned j = 1; j < matrix[i][0]; j++) {
            if (matrix[i][j]) {
              (*indices)[segments_count++] = i;
              (*indices)[segments_count++] = matrix[i][j] - 1;
            }
          }
        }
        *num_indices = segments_count;
        result = 0;
      }

      for (int i = 0; i < *num_vertices; i++) free(matrix[i]);
      free(matrix);
      *vertices = (float *)points;
    }
    fclose(file);
  }
  return result;
}



MINMAX first_reading(FILE *file, int *num_vertices) {
  char str[256];
  POINT p;
  MINMAX mm = {0};
  *num_vertices = 0;
  int is_first_vertex = 1;

  while (fgets(str, sizeof(str), file)) {
    char *ptr_str = str;
    while (*ptr_str == ' ' || *ptr_str == '\t') ptr_str++;
    if (strncmp(ptr_str, "v ", 2) == 0) {
      if (sscanf(ptr_str + 2, "%f %f %f", &p.x, &p.y, &p.z) == 3) {
        if (is_first_vertex) {
          mm.min.x = mm.max.x = p.x;
          mm.min.y = mm.max.y = p.y;
          mm.min.z = mm.max.z = p.z;
          is_first_vertex = 0;
        } else {
          mm.min.x = fminf(mm.min.x, p.x);
          mm.max.x = fmaxf(mm.max.x, p.x);
          mm.min.y = fminf(mm.min.y, p.y);
          mm.max.y = fmaxf(mm.max.y, p.y);
          mm.min.z = fminf(mm.min.z, p.z);
          mm.max.z = fmaxf(mm.max.z, p.z);
        }
        (*num_vertices)++;
      }
    }
  }

  if (*num_vertices > 0) {
    mm.range = fmaxf(fmaxf(mm.max.x - mm.min.x, mm.max.y - mm.min.y),
                     mm.max.z - mm.min.z);
  } else {
    mm.range = 0.0f;
  }

  return mm;
}




unsigned **matrix_alloc(int *num_vertices) {
  if (*num_vertices <= 0) {
      return NULL;
  }

  unsigned **matrix = (unsigned **)calloc(*num_vertices, sizeof(unsigned *));
  if (!matrix) {
      return NULL;
  }

  for (int i = 0; i < *num_vertices; i++) {
      matrix[i] = (unsigned *)calloc(step, sizeof(unsigned));
      if (!matrix[i]) {
          for (int j = 0; j < i; j++) {
              free(matrix[j]);
          }
          free(matrix);
          return NULL;
      }
      matrix[i][0] = step; // Размер строки
  }

  return matrix;
}


void read_vertex(POINT **points, char *str, MINMAX mm, int *vertex_count) {
  POINT p;
  if (sscanf(str, "v %f %f %f", &p.x, &p.y, &p.z) == 3) {
    if (mm.range != 0.0f) {
      p.x = 2.0f * (p.x - mm.min.x) / mm.range - 1.0f;
      p.y = 2.0f * (p.y - mm.min.y) / mm.range - 1.0f;
      p.z = 2.0f * (p.z - mm.min.z) / mm.range - 1.0f;
    }

    (*points)[*vertex_count] = p;
    (*vertex_count)++;
  }
}

void read_surface(unsigned **matrix, char *str, int *num_indices, int num_vertices) { // Добавлен аргумент num_vertices
  int len = strlen(str);
  unsigned head = 0, current = 0;
  for (int l = 0; l < len - 1;) {
      if (str[l] == ' ' && str[l + 1] != ' ') {
          l++;
          unsigned num = 0;
          while (str[l] >= '0' && str[l] <= '9') {
              num *= 10;
              num += str[l] - '0';
              l++;
          }

          if ((int)num > num_vertices || num == 0) { // Проверка индекса
              fprintf(stderr, "Invalid vertex index: %u\n", num);
              continue;
          }

          if (!head) head = num;
          if (current) {
              if (num > current) {
                  add_segment(&matrix[current - 1], num);
              } else {
                  add_segment(&matrix[num - 1], current);
              }
              *num_indices += 2;
          }
          current = num;
      } else {
          l++;
      }
  }

  if (head != current && head != 0 && current != 0) {
      if (head > current) {
          add_segment(&matrix[current - 1], head);
      } else {
          add_segment(&matrix[head - 1], current);
      }
      *num_indices += 2;
  }
}

void add_segment(unsigned **line, unsigned value) {
  if (!line || !*line) { // Проверка входных параметров
      fprintf(stderr, "Error: Invalid line pointer\n");
      return;
  }

  unsigned *current_line = *line;
  if (!current_line || current_line[0] == 0) { // Проверка текущей строки
      fprintf(stderr, "Error: Invalid current_line\n");
      return;
  }

  int result = 1;
  for (unsigned i = 1; i < current_line[0] && result; i++) {
      if (i >= current_line[0]) { // Защита от переполнения
          break;
      }
      if (!current_line[i] || current_line[i] == value) {
          current_line[i] = value;
          result = 0;
      }
  }

  if (result) {
      int old_size = current_line[0];
      int next_size = old_size + step;
      unsigned *line2 = (unsigned *)calloc(next_size, sizeof(unsigned));
      if (!line2) {
          fprintf(stderr, "Memory allocation failed\n");
          return;
      }
      for (int i = 0; i < old_size; i++) {
          line2[i] = current_line[i];
      }
      line2[old_size] = value;
      line2[0] = next_size;
      *line = line2;
      free(current_line);
  }
}

