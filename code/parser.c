#include "parser.h"

int load_from_file(const char *filename, float **vertices, int *num_vertices,
                   unsigned **indices, int *num_indices) {
  int result = 1;
  FILE *file = fopen(filename, "r");
  if (file) {
    *num_vertices = 0;
    *num_indices = 0;

    setlocale(LC_NUMERIC, "en_US.UTF-8");
    MINMAX mm = first_reading(file, num_vertices);
    unsigned **matrix = matrix_alloc(num_vertices);
    POINT *points = (POINT *)calloc(*num_vertices, sizeof(POINT));
    if (points && matrix) {
      rewind(file);
      int vertex_count = 0;
      char str[256];
      while (fgets(str, sizeof(str), file)) {
        char *ptr_str = str;
        while (*ptr_str == ' ') ptr_str++;
        if (*ptr_str == 'v' && *(ptr_str + 1) == ' ')
          read_vertex(&points, ptr_str, mm, &vertex_count);
        if (*ptr_str == 'f' && *(ptr_str + 1) == ' ')
          read_surface(matrix, ptr_str, num_indices);
      }
      *indices = (unsigned *)calloc(*num_indices, sizeof(unsigned));
      if (*indices) {
        int segments_count = 0;
        for (int i = 0; i < *num_vertices; i++)
          for (unsigned j = 1; j < matrix[i][0]; j++)
            if (matrix[i][j]) {
              (*indices)[segments_count++] = i;
              (*indices)[segments_count++] = matrix[i][j] - 1;
            }

        *num_indices = segments_count;
        result = 0;
      }

      for (int i = 0; i < *num_vertices; i++) free(matrix[i]);
      free(matrix);
      matrix = NULL;

      *vertices = (float *)points;
    }
    fclose(file);
  }
  return result;
}

MINMAX first_reading(FILE *file, int *num_vertices) {
  char str[256];
  POINT p;
  MINMAX mm;

  while (fgets(str, sizeof(str), file)) {
    char *ptr_str = str;
    while (*ptr_str == ' ') ptr_str++;
    if (*ptr_str == 'v' && *(ptr_str + 1) == ' ') {
      if (sscanf(ptr_str, "v %f %f %f", &p.x, &p.y, &p.z) == 3) {
        if (*num_vertices == 0) {
          mm.min.x = mm.max.x = p.x;
          mm.min.y = mm.max.y = p.y;
          mm.min.z = mm.max.z = p.z;
        } else {
          if (p.x < mm.min.x) mm.min.x = p.x;
          if (p.x > mm.max.x) mm.max.x = p.x;
          if (p.y < mm.min.y) mm.min.y = p.y;
          if (p.y > mm.max.y) mm.max.y = p.y;
          if (p.z < mm.min.z) mm.min.z = p.z;
          if (p.z > mm.max.z) mm.max.z = p.z;
        }
        (*num_vertices)++;
      }
    }
  }

  mm.range = fmaxf(fmaxf(mm.max.x - mm.min.x, mm.max.y - mm.min.y),
                   mm.max.z - mm.min.z);

  return mm;
}

unsigned **matrix_alloc(int *num_vertices) {
  unsigned **matrix = (unsigned **)calloc(*num_vertices, sizeof(unsigned *));

  if (matrix) {
    for (int i = 0; i < *num_vertices && matrix; i++) {
      matrix[i] = (unsigned *)calloc(step, sizeof(unsigned));
      if (!matrix[i]) {
        for (int j = 0; j < i; j++) free(matrix[j]);
        free(matrix);
        matrix = NULL;
      }
      matrix[i][0] = step;
    }
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

void read_surface(unsigned **matrix, char *str, int *num_indices) {
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

      if (num) {
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
      }

    } else {
      l++;
    }
  }

  if (head != current) {
    if (head > current) {
      add_segment(&matrix[current - 1], head);
    } else {
      add_segment(&matrix[head - 1], current);
    }

    *num_indices += 2;
  }
}

void add_segment(unsigned **line, unsigned value) {
  int result = 1;
  unsigned *current_line = *line;

  for (unsigned i = 1; i < current_line[0] && result; i++) {
    if (!current_line[i] || current_line[i] == value) {
      current_line[i] = value;
      result = 0;
    }
  }

  if (result) {
    int old_size = current_line[0];
    int next_size = old_size + step;
    unsigned *line2 = (unsigned *)calloc(next_size, sizeof(unsigned));
    if (line2) {
      for (int i = 0; i < old_size; i++) line2[i] = current_line[i];
      line2[old_size] = value;
      line2[0] = next_size;
      *line = line2;
      free(current_line);
    }
  }
}