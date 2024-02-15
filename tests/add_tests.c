#include "tests.h"

START_TEST(add_1) {
  s21_decimal first = {{10, 0, 0, 0}};
  s21_decimal second = {{3, 0, 0, 0}};
  s21_decimal expectation = {{13, 0, 0, 0}};
  s21_decimal reality = {0};

  s21_add(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(add_2) {
  s21_decimal first = {{23, 0, 0, 0}};
  s21_decimal second = {{43, 0, 0, 0}};
  s21_decimal expectation = {{66, 0, 0, 0}};
  s21_decimal reality = {0};

  s21_add(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(add_3) {
  s21_decimal first = {{23, 0, 0, MINUS}};
  s21_decimal second = {{43, 0, 0, MINUS}};
  s21_decimal expectation = {{66, 0, 0, MINUS}};
  s21_decimal reality = {0};

  s21_add(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(add_4) {
  s21_decimal first = {{23, 0, 0, MINUS}};
  s21_decimal second = {{43, 0, 0, 0}};
  s21_decimal expectation = {{20, 0, 0, 0}};
  s21_decimal reality = {0};

  s21_add(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(add_5) {
  s21_decimal first = {{23, 0, 0, 0}};
  s21_decimal second = {{43, 0, 0, MINUS}};
  s21_decimal expectation = {{20, 0, 0, MINUS}};
  s21_decimal reality = {0};

  s21_add(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(add_6) {
  s21_decimal first = MAX_DECIMAL;
  s21_decimal second = {{MAX_BIT, 0, MAX_BIT, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_add(first, second, &reality);

  ck_assert_int_eq(result, TOO_MUCH);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(add_7) {
  s21_decimal first = MIN_DECIMAL;
  s21_decimal second = {{MAX_BIT, 0, MAX_BIT, 0}};
  s21_decimal expectation = {{0, MAX_BIT, 0, MINUS}};
  s21_decimal reality = {0};

  int result = s21_add(first, second, &reality);

  ck_assert_int_eq(result, OK);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(add_8) {
  s21_decimal first = MAX_DECIMAL;
  s21_decimal second = {{MAX_BIT, 0, MAX_BIT, MINUS}};
  s21_decimal expectation = {{0, MAX_BIT, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_add(first, second, &reality);

  ck_assert_int_eq(result, OK);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(add_9) {
  s21_decimal first = MAX_DECIMAL;
  s21_decimal second = MIN_DECIMAL;
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_add(first, second, &reality);

  ck_assert_int_eq(result, OK);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(add_10) {
  s21_decimal first = {{250, 0, 0, 1u << 16}};
  s21_decimal second = {{44, 0, 0, 0}};
  s21_decimal expectation = {{69, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_add(first, second, &reality);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(s21_is_equal(expectation, reality), TRUE);
}
END_TEST

START_TEST(add_11) {
  s21_decimal first = {{324423234, 0, 0, 8 << 16}};
  s21_decimal second = {{1231312367, 0, 0, 13 << 16}};
  s21_decimal expectation = {
      {0b11011010100011011100101100101111, 0b1110110000001, 0, 13 << 16}};
  s21_decimal reality = {0};

  int result = s21_add(first, second, &reality);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(s21_is_equal(expectation, reality), TRUE);
}
END_TEST

START_TEST(add_12) {
  s21_decimal first = {{324423234, 0, 0, 8 << 16 | 1u << 31}};
  s21_decimal second = {{1231312367, 0, 0, 13 << 16 | 1u << 31}};
  s21_decimal expectation = {{0b11011010100011011100101100101111,
                              0b1110110000001, 0, 13 << 16 | 1u << 31}};
  s21_decimal reality = {0};

  int result = s21_add(first, second, &reality);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(s21_is_equal(expectation, reality), TRUE);
}
END_TEST

START_TEST(add_13) {
  s21_decimal first = {{324423234, 0, 0, 8 << 16}};
  s21_decimal second = {{1231312367, 0, 0, 13 << 16 | 1u << 31}};
  s21_decimal expectation = {
      {0b01000111110001010001111101010001, 0b1110110000001, 0, 13 << 16}};
  s21_decimal reality = {0};

  int result = s21_add(first, second, &reality);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(s21_is_equal(expectation, reality), TRUE);
}
END_TEST

START_TEST(add_14) {
  s21_decimal first = {{MAX_BIT - 1, MAX_BIT, MAX_BIT, 0}};
  s21_decimal second = {{6, 0, 0, 1u << 16}};
  s21_decimal expectation = MAX_DECIMAL;
  s21_decimal reality = {0};

  int result = s21_add(first, second, &reality);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(s21_is_equal(expectation, reality), TRUE);
}
END_TEST

// bankovskoe
START_TEST(add_15) {
  s21_decimal first = {{MAX_BIT - 1, MAX_BIT, MAX_BIT, 0}};
  s21_decimal second = {{5, 0, 0, 1u << 16}};
  s21_decimal expectation = {{MAX_BIT - 1, MAX_BIT, MAX_BIT, 0}};
  s21_decimal reality = {0};

  int result = s21_add(first, second, &reality);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(s21_is_equal(expectation, reality), TRUE);
}
END_TEST

START_TEST(add_16) {
  s21_decimal first = {{MAX_BIT - 2, MAX_BIT, MAX_BIT, 0}};
  s21_decimal second = {{15, 0, 0, 1u << 16}};
  s21_decimal expectation = {{MAX_BIT, MAX_BIT, MAX_BIT, 0}};
  s21_decimal reality = {0};

  int result = s21_add(first, second, &reality);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(s21_is_equal(expectation, reality), TRUE);
}
END_TEST

Suite *add_tests(void) {
  Suite *s = suite_create("\033[45m-=S21_add=-\033[0m");
  TCase *tc = tcase_create("add_tc");

  tcase_add_test(tc, add_1);
  tcase_add_test(tc, add_2);
  tcase_add_test(tc, add_3);
  tcase_add_test(tc, add_4);
  tcase_add_test(tc, add_5);
  tcase_add_test(tc, add_6);
  tcase_add_test(tc, add_7);
  tcase_add_test(tc, add_8);
  tcase_add_test(tc, add_9);
  tcase_add_test(tc, add_10);
  tcase_add_test(tc, add_11);
  tcase_add_test(tc, add_12);
  tcase_add_test(tc, add_13);
  tcase_add_test(tc, add_14);
  tcase_add_test(tc, add_15);
  tcase_add_test(tc, add_16);

  suite_add_tcase(s, tc);
  return s;
}