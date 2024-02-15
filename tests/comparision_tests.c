#include "tests.h"

START_TEST(is_greater_1) {
  unsigned exp = 1 << 16;
  s21_decimal first = {{25, 0, 0, exp}};
  s21_decimal second = {{25, 0, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_greater(first, second);

  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(is_greater_2) {
  unsigned exp = 1 << 16;
  s21_decimal first = {{25, 0, 0, 0}};
  s21_decimal second = {{25, 0, 0, exp}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_greater(first, second);

  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_greater_3) {
  s21_decimal first = {{1234, 5463, 1, 0}};
  s21_decimal second = {{1234, 5463, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_greater(first, second);

  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_greater_4) {
  s21_decimal first = {{25, 345, 0, 1u << 31}};
  s21_decimal second = {{25, 0, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_greater(first, second);

  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(is_greater_5) {
  s21_decimal first = {{3214, 314214, 1234, 1u << 31}};
  s21_decimal second = {{3214, 3214, 1, 1u << 31}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_greater(first, second);

  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(is_equal_1) {
  unsigned exp = 1 << 16;
  s21_decimal first = {{250, 0, 0, exp}};
  s21_decimal second = {{25, 0, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_equal(first, second);

  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_equal_2) {
  unsigned exp = 1 << 16;
  s21_decimal first = MAX_DECIMAL;
  s21_decimal second = {{MAX_BIT, MAX_BIT, MAX_BIT, exp}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_equal(first, second);

  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(is_equal_3) {
  s21_decimal first = {{2435, 42354, 6543734, 4 << 16}};
  s21_decimal second = {{2435, 42354, 6543734, 4 << 16}};
  ck_assert_int_eq(s21_is_equal(first, second), TRUE);
}
END_TEST

START_TEST(is_equal_4) {
  s21_decimal first = {{2435, 42354, 6543734, 1u << 31 | 1 << 16}};
  s21_decimal second = {{2435, 42354, 6543734, 1 << 16}};
  ck_assert_int_eq(s21_is_equal(first, second), FALSE);
}
END_TEST

START_TEST(is_equal_5) {
  s21_decimal first = {{23546, 132412, 87613450, 10 << 16 | 1u << 31}};
  s21_decimal second = {{23546, 132412, 8761345, 10 << 16 | 1u << 31}};
  ck_assert_int_eq(s21_is_equal(first, second), FALSE);
}
END_TEST

START_TEST(is_equal_6) {
  s21_decimal first = {{23546, 0, 0, 4 << 16 | 1u << 31}};
  s21_decimal second = {{235460, 0, 0, 5 << 16 | 1u << 31}};
  ck_assert_int_eq(s21_is_equal(first, second), TRUE);
}
END_TEST

START_TEST(is_not_equal_1) {
  unsigned exp = 1 << 16;
  s21_decimal first = {{250, 0, 0, exp}};
  s21_decimal second = {{25, 0, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_not_equal(first, second);

  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(is_not_equal_2) {
  unsigned exp = 1 << 16;
  s21_decimal first = MAX_DECIMAL;
  s21_decimal second = {{MAX_BIT, MAX_BIT, MAX_BIT, exp}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_not_equal(first, second);

  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_not_equal_3) {
  s21_decimal first = {{2435, 42354, 6543734, 4 << 16}};
  s21_decimal second = {{2435, 42354, 6543734, 4 << 16}};
  ck_assert_int_eq(s21_is_not_equal(first, second), FALSE);
}
END_TEST

START_TEST(is_not_equal_4) {
  s21_decimal first = {{2435, 42354, 6543734, 1u << 31 | 1 << 16}};
  s21_decimal second = {{2435, 42354, 6543734, 1 << 16}};
  ck_assert_int_eq(s21_is_not_equal(first, second), TRUE);
}
END_TEST

START_TEST(is_not_equal_5) {
  s21_decimal first = {{23546, 132412, 87613450, 10 << 16 | 1u << 31}};
  s21_decimal second = {{23546, 132412, 8761345, 10 << 16 | 1u << 31}};
  ck_assert_int_eq(s21_is_not_equal(first, second), TRUE);
}
END_TEST

START_TEST(is_not_equal_6) {
  s21_decimal first = {{23546, 0, 0, 4 << 16 | 1u << 31}};
  s21_decimal second = {{235460, 0, 0, 5 << 16 | 1u << 31}};
  ck_assert_int_eq(s21_is_not_equal(first, second), FALSE);
}
END_TEST

START_TEST(is_less_1) {
  unsigned exp = 1 << 16;
  s21_decimal first = {{25, 0, 0, exp}};
  s21_decimal second = {{25, 0, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_less(first, second);

  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_less_2) {
  unsigned exp = 1 << 16;
  s21_decimal first = {{25, 0, 0, 0}};
  s21_decimal second = {{25, 0, 0, exp}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_less(first, second);

  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(is_less_3) {
  s21_decimal first = {{1234, 5463, 1, 0}};
  s21_decimal second = {{1234, 5463, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_less(first, second);

  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(is_less_4) {
  s21_decimal first = {{25, 345, 0, 1u << 31}};
  s21_decimal second = {{25, 0, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_less(first, second);

  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_less_5) {
  s21_decimal first = {{3214, 314214, 1234, 1u << 31}};
  s21_decimal second = {{3214, 3214, 1, 1u << 31}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_less(first, second);

  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_less_or_equal_1) {
  unsigned exp = 1 << 16;
  s21_decimal first = {{25, 0, 0, exp}};
  s21_decimal second = {{25, 0, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_less_or_equal(first, second);

  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_less_or_equal_2) {
  unsigned exp = 1 << 16;
  s21_decimal first = {{25, 0, 0, 0}};
  s21_decimal second = {{25, 0, 0, exp}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_less_or_equal(first, second);

  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(is_less_or_equal_3) {
  s21_decimal first = {{1234, 5463, 0, 0}};
  s21_decimal second = {{1234, 5463, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_less_or_equal(first, second);

  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_less_or_equal_4) {
  s21_decimal first = {{25, 345, 0, 1u << 31}};
  s21_decimal second = {{25, 0, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_less_or_equal(first, second);

  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_less_or_equal_5) {
  s21_decimal first = {{3214, 314214, 1234, 1u << 31}};
  s21_decimal second = {{3214, 314214, 1234, 1u << 31}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_less_or_equal(first, second);

  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_greater_or_equal_1) {
  unsigned exp = 1 << 16;
  s21_decimal first = {{25, 0, 0, exp}};
  s21_decimal second = {{25, 0, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_greater_or_equal(first, second);

  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(is_greater_or_equal_2) {
  s21_decimal first = {{25, 0, 0, 0}};
  s21_decimal second = {{25, 0, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_greater_or_equal(first, second);

  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_greater_or_equal_3) {
  s21_decimal first = {{1234, 5463, 0, 0}};
  s21_decimal second = {{1234, 5463, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_greater_or_equal(first, second);

  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(is_greater_or_equal_4) {
  s21_decimal first = {{25, 345, 0, 1u << 31}};
  s21_decimal second = {{25, 0, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_greater_or_equal(first, second);

  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(is_greater_or_equal_5) {
  s21_decimal first = {{3214, 314214, 1234, 1u << 31}};
  s21_decimal second = {{3214, 3214, 1, 1u << 31}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_is_greater_or_equal(first, second);

  ck_assert_int_eq(result, FALSE);
}
END_TEST

Suite *comparison_tests(void) {
  Suite *s = suite_create("\033[45m-=COMPARISION=-\033[0m");
  TCase *tc = tcase_create("comparison_tc");

  tcase_add_test(tc, is_greater_1);
  tcase_add_test(tc, is_greater_2);
  tcase_add_test(tc, is_greater_3);
  tcase_add_test(tc, is_greater_4);
  tcase_add_test(tc, is_greater_5);
  tcase_add_test(tc, is_equal_1);
  tcase_add_test(tc, is_equal_2);
  tcase_add_test(tc, is_equal_3);
  tcase_add_test(tc, is_equal_4);
  tcase_add_test(tc, is_equal_5);
  tcase_add_test(tc, is_equal_6);
  tcase_add_test(tc, is_not_equal_1);
  tcase_add_test(tc, is_not_equal_2);
  tcase_add_test(tc, is_not_equal_3);
  tcase_add_test(tc, is_not_equal_4);
  tcase_add_test(tc, is_not_equal_5);
  tcase_add_test(tc, is_not_equal_6);
  tcase_add_test(tc, is_less_1);
  tcase_add_test(tc, is_less_2);
  tcase_add_test(tc, is_less_3);
  tcase_add_test(tc, is_less_4);
  tcase_add_test(tc, is_less_5);
  tcase_add_test(tc, is_less_or_equal_1);
  tcase_add_test(tc, is_less_or_equal_2);
  tcase_add_test(tc, is_less_or_equal_3);
  tcase_add_test(tc, is_less_or_equal_4);
  tcase_add_test(tc, is_less_or_equal_5);
  tcase_add_test(tc, is_greater_or_equal_1);
  tcase_add_test(tc, is_greater_or_equal_2);
  tcase_add_test(tc, is_greater_or_equal_3);
  tcase_add_test(tc, is_greater_or_equal_4);
  tcase_add_test(tc, is_greater_or_equal_5);

  suite_add_tcase(s, tc);
  return s;
}