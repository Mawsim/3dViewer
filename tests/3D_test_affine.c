#include "3D_test.h"

#define SUITE_LABEL "suite_3D_affine"
#define SUITE_NAME *suite_3D_affine()

START_TEST(test_move_X) {
  int num_vertices = 3;
  float vertices[] = {1.0, 1.0, -1.0, 1.0, -1.0, -1.0, 0.5, -0.5, 0.5};

  move_X(vertices, num_vertices, 2.3f);

  float expected_vertices[] = {3.3, 1.0, -1.0, 3.3, -1.0, -1.0, 2.8, -0.5, 0.5};

  ck_assert(float_arrays_equal(vertices, expected_vertices, num_vertices * 3,
                               EPSILON));
}
END_TEST

START_TEST(test_move_Y) {
  int num_vertices = 3;
  float vertices[] = {1.0, 1.0, -1.0, 1.0, -1.0, -1.0, 0.5, -0.5, 0.5};

  move_Y(vertices, num_vertices, 2.3f);

  float expected_vertices[] = {1.0, 3.3, -1.0, 1.0, 1.3, -1.0, 0.5, 1.8, 0.5};

  ck_assert(float_arrays_equal(vertices, expected_vertices, num_vertices * 3,
                               EPSILON));
}
END_TEST

START_TEST(test_move_Z) {
  int num_vertices = 3;
  float vertices[] = {1.0, 1.0, -1.0, 1.0, -1.0, -1.0, 0.5, -0.5, 0.5};

  move_Z(vertices, num_vertices, 2.3f);

  float expected_vertices[] = {1.0, 1.0, 1.3, 1.0, -1.0, 1.3, 0.5, -0.5, 2.8};

  ck_assert(float_arrays_equal(vertices, expected_vertices, num_vertices * 3,
                               EPSILON));
}
END_TEST

START_TEST(test_scale_M) {
  int num_vertices = 3;
  float vertices[] = {1.0, 1.0, -1.0, 1.0, -1.0, -1.0, 0.5, -0.5, 0.5};

  scale_M(vertices, num_vertices, 2.3f);

  float expected_vertices[] = {2.3,  2.3,  -2.3,  2.3, -2.3,
                               -2.3, 1.15, -1.15, 1.15};

  ck_assert(float_arrays_equal(vertices, expected_vertices, num_vertices * 3,
                               EPSILON));
}
END_TEST

START_TEST(test_rotate_X) {
  int num_vertices = 3;
  float vertices[] = {1.0, 1.0, -1.0, 1.0, -1.0, -1.0, 0.5, -0.5, 0.5};

  rotate_X(vertices, num_vertices, 12.0f);

  float expected_vertices[] = {1.0, 0.7702359,  -1.1860592,
                               1.0, -1.1860592, -0.7702359,
                               0.5, -0.3851179, 0.5930296};

  ck_assert(float_arrays_equal(vertices, expected_vertices, num_vertices * 3,
                               EPSILON));
}
END_TEST

START_TEST(test_rotate_Y) {
  int num_vertices = 3;
  float vertices[] = {1.0, 1.0, -1.0, 1.0, -1.0, -1.0, 0.5, -0.5, 0.5};

  rotate_Y(vertices, num_vertices, 12.0f);

  float expected_vertices[] = {0.7702359, 1.0,  -1.1860592,
                               0.7702359, -1.0, -1.1860592,
                               0.5930296, -0.5, 0.3851179};

  ck_assert(float_arrays_equal(vertices, expected_vertices, num_vertices * 3,
                               EPSILON));
}
END_TEST

START_TEST(test_rotate_Z) {
  int num_vertices = 3;
  float vertices[] = {1.0, 1.0, -1.0, 1.0, -1.0, -1.0, 0.5, -0.5, 0.5};

  rotate_Z(vertices, num_vertices, 12.0f);

  float expected_vertices[] = {1.1860592, 0.7702359,  -1.0,
                               0.7702359, -1.1860592, -1.0,
                               0.3851179, -0.5930296, 0.5};

  ck_assert(float_arrays_equal(vertices, expected_vertices, num_vertices * 3,
                               EPSILON));
}
END_TEST

Suite SUITE_NAME {
  Suite *suite = suite_create(SUITE_LABEL);
  TCase *tcase = tcase_create("case");

  tcase_add_test(tcase, test_move_X);
  tcase_add_test(tcase, test_move_Y);
  tcase_add_test(tcase, test_move_Z);
  tcase_add_test(tcase, test_scale_M);
  tcase_add_test(tcase, test_rotate_X);
  tcase_add_test(tcase, test_rotate_Y);
  tcase_add_test(tcase, test_rotate_Z);

  suite_add_tcase(suite, tcase);

  return suite;
}
