#ifndef DECIMAL_TESTS_H
#define DECIMAL_TESTS_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_decimal.h"

Suite *add_tests(void);
Suite *from_int_to_decimal_tests(void);
Suite *from_float_to_decimal_tests(void);
Suite *from_decimal_to_int_tests(void);
Suite *from_decimal_to_float_tests(void);
Suite *sub_tests(void);
Suite *mul_tests(void);
Suite *div_tests(void);
Suite *comparison_tests(void);
Suite *helpers_tests(void);
Suite *other_tests(void);

#endif  // DECIMAL_TESTS_H