#include "tests.h"

int main(void) {
  int failed = 0;
  Suite *s21_decimal_test[] = {from_int_to_decimal_tests(),
                               from_decimal_to_int_tests(),
                               from_float_to_decimal_tests(),
                               from_decimal_to_float_tests(),
                               helpers_tests(),
                               comparison_tests(),
                               div_tests(),
                               sub_tests(),
                               add_tests(),
                               mul_tests(),
                               other_tests(),
                               NULL};

  for (int i = 0; s21_decimal_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_decimal_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}