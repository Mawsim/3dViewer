#include "affine.h"

#define M_PI 3.14159265358979323846

void move_X(float* vertices_v_arr, int vertices_v_count, float k) {
  for (int i = 0; i < vertices_v_count * 3; i += 3) {
    vertices_v_arr[i] += k;
  }
}

void move_Y(float* vertices_v_arr, int vertices_v_count, float k) {
  for (int i = 1; i < vertices_v_count * 3; i += 3) {
    vertices_v_arr[i] += k;
  }
}

void move_Z(float* vertices_v_arr, int vertices_v_count, float k) {
  for (int i = 2; i < vertices_v_count * 3; i += 3) {
    vertices_v_arr[i] += k;
  }
}

void scale_M(float* vertices_v_arr, int vertices_v_count, float k) {
  if (k != 0) {
    for (int i = 0; i < vertices_v_count * 3; i++) {
      vertices_v_arr[i] *= k;
    }
  }
}

void rotate_X(float* vertices_v_arr, int vertices_v_count, float angle) {
  angle = angle * M_PI / 180;
  for (int i = 0; i < vertices_v_count * 3; i += 3) {
    float Y = vertices_v_arr[i + 1];
    float Z = vertices_v_arr[i + 2];
    vertices_v_arr[i + 1] = Y * cos(angle) + Z * sin(angle);
    vertices_v_arr[i + 2] = -Y * sin(angle) + Z * cos(angle);
  }
}

void rotate_Y(float* vertices_v_arr, int vertices_v_count, float angle) {
  angle = angle * M_PI / 180;
  for (int i = 0; i < vertices_v_count * 3; i += 3) {
    float X = vertices_v_arr[i];
    float Z = vertices_v_arr[i + 2];
    vertices_v_arr[i] = X * cos(angle) + Z * sin(angle);
    vertices_v_arr[i + 2] = -X * sin(angle) + Z * cos(angle);
  }
}

void rotate_Z(float* vertices_v_arr, int vertices_v_count, float angle) {
  angle = angle * M_PI / 180;
  for (int i = 0; i < vertices_v_count * 3; i += 3) {
    float X = vertices_v_arr[i];
    float Y = vertices_v_arr[i + 1];
    vertices_v_arr[i] = X * cos(angle) + Y * sin(angle);
    vertices_v_arr[i + 1] = -X * sin(angle) + Y * cos(angle);
  }
}
