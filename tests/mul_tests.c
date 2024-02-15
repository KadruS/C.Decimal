#include "tests.h"

START_TEST(mul_1) {
  s21_decimal first = {{43, 0, 0, MINUS}};
  s21_decimal second = {{5, 0, 0, 0}};
  s21_decimal expectation = {{215, 0, 0, MINUS}};
  s21_decimal reality = {0};

  int result = s21_mul(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(mul_2) {
  s21_decimal first = {{43, 0, 0, MINUS}};
  s21_decimal second = {{14, 0, 0, MINUS}};
  s21_decimal expectation = {{602, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_mul(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(mul_3) {
  s21_decimal first = {{MAX_BIT, 0, 0, 0}};
  s21_decimal second = {{14, 0, 0, MINUS}};
  s21_decimal expectation = {
      {0b11111111111111111111111111110010, 0b1101, 0, MINUS}};
  s21_decimal reality = {0};

  int result = s21_mul(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(mul_4) {
  s21_decimal first = MAX_DECIMAL;
  s21_decimal second = {{4, 0, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_mul(first, second, &reality);

  ck_assert_int_eq(result, TOO_MUCH);
}
END_TEST

START_TEST(mul_5) {
  s21_decimal first = {{256700, 0, 0, 0}};
  setExp(&first, 2);
  s21_decimal second = {{39, 0, 0, 0}};
  s21_decimal expectation = {{10011300, 0, 0, 0}};
  setExp(&expectation, 2);
  s21_decimal reality = {0};

  int result = s21_mul(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(mul_6) {
  s21_decimal first = MIN_DECIMAL;
  s21_decimal second = {{4, 0, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_mul(first, second, &reality);

  ck_assert_int_eq(result, TOO_LOW);
}
END_TEST

START_TEST(mul_7) {
  s21_decimal first = {{52000, 0, 0, MINUS}};
  setExp(&first, 3);
  s21_decimal second = {{5, 0, 0, 0}};
  s21_decimal expectation = {{260000, 0, 0, MINUS}};
  setExp(&expectation, 3);
  s21_decimal reality = {0};

  int result = s21_mul(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(mul_8) {
  s21_decimal first = {{52000, 0, 0, MINUS}};
  setExp(&first, 3);
  s21_decimal second = {{0, 0, 0, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_mul(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(mul_9) {
  s21_decimal first = {{MAX_BIT, 0, 0, MINUS}};
  setExp(&first, 5);
  s21_decimal second = {{MAX_BIT, 0, 0, MINUS}};
  s21_decimal expectation = {{1, MAX_BIT - 1, 0, 0}};
  setExp(&expectation, 5);
  s21_decimal reality = {0};

  int result = s21_mul(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(mul_10) {
  s21_decimal first = {{MAX_BIT, 0, 0, MINUS}};
  setExp(&first, 28);
  s21_decimal second = {{MAX_BIT, 0, 0, MINUS}};
  setExp(&second, 1);
  s21_decimal expectation = {{1, MAX_BIT - 1, 0, 0}};
  setExp(&expectation, 29);  // ???
  s21_decimal reality = {0};

  int result = s21_mul(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

Suite *mul_tests(void) {
  Suite *s = suite_create("\033[45m-=S21_mul=-\033[0m");
  TCase *tc = tcase_create("mul_tc");

  tcase_add_test(tc, mul_1);
  tcase_add_test(tc, mul_2);
  tcase_add_test(tc, mul_3);
  tcase_add_test(tc, mul_4);
  tcase_add_test(tc, mul_5);
  tcase_add_test(tc, mul_6);
  tcase_add_test(tc, mul_7);
  tcase_add_test(tc, mul_8);
  tcase_add_test(tc, mul_9);
  tcase_add_test(tc, mul_10);

  suite_add_tcase(s, tc);
  return s;
}
