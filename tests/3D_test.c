#include "3D_test.h"

bool unsigned_arrays_equal(const unsigned *a, unsigned *b, int len) {
  for (int i = 0; i < len; i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

bool float_arrays_equal(const float *a, const float *b, int len,
                        float epsilon) {
  for (int i = 0; i < len; i++) {
    if (fabs(a[i] - b[i]) > epsilon) {
      return false;
    }
  }
  return true;
}

void run_suite(Suite *suite) {
  SRunner *sr = srunner_create(suite);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);  // CK_MINIMAL CK_NORMAL CK_VERBOSE

  srunner_free(sr);
}

void run_tests() {
  Suite *suites_core[] = {suite_3D_parser(),  // 1
                          suite_3D_affine(),  // 2
                          NULL};

  for (Suite **cur = suites_core; *cur != NULL; cur++) {
    printf(
        "\n===================================================================="
        "=============\n");
    run_suite(*cur);
    printf(
        "\n===================================================================="
        "=============\n");
  }
}

int main() {
  run_tests();
  return 0;
}
