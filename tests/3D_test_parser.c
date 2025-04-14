#include "3D_test.h"

#define ACTUAL load_from_file
#define SUITE_LABEL "suite_3D_parser"
#define SUITE_NAME *suite_3D_parser()

START_TEST(test) {
  const char *filename = "tests/cube_test.obj";
  float *vertices = NULL;
  int num_vertices = 0;
  unsigned *indices = NULL;
  int num_indices = 0;

  int result =
      ACTUAL(filename, &vertices, &num_vertices, &indices, &num_indices);

  float expected_vertices[] = {
      1.0,  1.0, -1.0, 1.0,  -1.0, -1.0, 1.0,  1.0, 1.0, 1.0,  -1.0, 1.0,
      -1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0,
      0.5,  0.5, -0.5, 0.5,  -0.5, -0.5, 0.5,  0.5, 0.5, 0.5,  -0.5, 0.5};

  unsigned expected_indices[] = {
      0, 2, 0, 4, 0, 3, 0, 1, 0, 10, 0, 5, 0, 6, 0, 7, 0, 8, 0, 9, 1, 7, 1, 5,
      1, 3, 1, 4, 2, 4, 2, 7, 2, 3,  2, 6, 3, 7, 4, 5, 4, 6, 5, 6, 5, 7, 6, 7};

  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(num_vertices, 12);
  ck_assert_int_eq(num_indices, 48);
  ck_assert(float_arrays_equal(vertices, expected_vertices, num_vertices * 3,
                               EPSILON));
  ck_assert(unsigned_arrays_equal(indices, expected_indices, num_indices));

  if (vertices) {
    free(vertices);
    vertices = NULL;
  }

  if (indices) {
    free(indices);
    indices = NULL;
  }
}
END_TEST

Suite SUITE_NAME {
  Suite *suite = suite_create(SUITE_LABEL);
  TCase *tcase = tcase_create("case");

  tcase_add_test(tcase, test);

  suite_add_tcase(suite, tcase);

  return suite;
}
