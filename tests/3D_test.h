#ifndef SRC_TESTS_3D_TEST_H
#define SRC_TESTS_3D_TEST_H

#include <check.h>
#include <stdbool.h>

#include "../code/affine.h"
#include "../code/parser.h"

#define EPSILON 1e-7

bool float_arrays_equal(const float *a, const float *b, int len, float epsilon);
bool unsigned_arrays_equal(const unsigned *a, unsigned *b, int len);

Suite *suite_3D_parser();
Suite *suite_3D_affine();

#endif  // SRC_TESTS_3D_TEST_H
