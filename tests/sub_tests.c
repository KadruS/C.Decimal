#include "tests.h"

START_TEST(sub_1) {
  s21_decimal first = {0};
  s21_decimal second = {0};
  s21_decimal expectation = {0};
  s21_decimal reality = {0};
  first.bits[0] = 10;
  second.bits[0] = 3;
  expectation.bits[0] = 7;

  s21_sub(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(sub_2) {
  s21_decimal first = {0};
  s21_decimal second = {0};
  s21_decimal expectation = {0};
  s21_decimal reality = {0};
  first.bits[0] = 23;
  second.bits[0] = 43;
  expectation.bits[0] = 20;
  setSign(&expectation, 1);

  s21_sub(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(sub_3) {
  s21_decimal first = {0};
  s21_decimal second = {0};
  s21_decimal expectation = {0};
  s21_decimal reality = {0};
  first.bits[0] = 22;   //-22
  second.bits[0] = 43;  //-43
  setSign(&first, 1);
  setSign(&second, 1);
  expectation.bits[0] = 21;
  setSign(&expectation, 1);

  s21_sub(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(sub_4) {
  s21_decimal first = {0};
  s21_decimal second = {0};
  s21_decimal expectation = {0};
  s21_decimal reality = {0};
  first.bits[0] = 22;   //-22
  second.bits[0] = 43;  // 43
  setSign(&first, 1);
  expectation.bits[0] = 65;
  setSign(&expectation, 1);

  s21_sub(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(sub_5) {
  s21_decimal first = {0};
  s21_decimal second = {0};
  s21_decimal expectation = {0};
  s21_decimal reality = {0};
  first.bits[0] = 22;   // 22
  second.bits[0] = 43;  // -43
  setSign(&second, 1);
  expectation.bits[0] = 65;

  s21_sub(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(sub_6) {
  s21_decimal first = MAX_DECIMAL;
  s21_decimal second = {{MAX_BIT, 0, MAX_BIT, 0}};
  s21_decimal expectation = {{0, MAX_BIT, 0, 0}};
  s21_decimal reality = {0};

  s21_sub(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(sub_7) {
  s21_decimal first = MIN_DECIMAL;
  s21_decimal second = {{MAX_BIT, 0, MAX_BIT, 0}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_sub(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, TOO_LOW);
}
END_TEST

START_TEST(sub_8) {
  s21_decimal first = MAX_DECIMAL;
  s21_decimal second = {{MAX_BIT, 0, MAX_BIT, MINUS}};
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_sub(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, TOO_MUCH);
}
END_TEST

START_TEST(sub_9) {
  s21_decimal first = MAX_DECIMAL;
  s21_decimal second = MAX_DECIMAL;
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_sub(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(sub_10) {
  s21_decimal first = {{250, 0, 0, 1 << 16}};
  s21_decimal second = {{44, 0, 0, 0}};
  s21_decimal expectation = {{19, 0, 0, 1u << 31}};
  s21_decimal reality = {0};

  int result = s21_sub(first, second, &reality);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(s21_is_equal(expectation, reality), TRUE);
}
END_TEST

START_TEST(sub_11) {
  s21_decimal first = {{324423234, 0, 0, 8 << 16}};
  s21_decimal second = {{1231312367, 0, 0, 13 << 16}};
  s21_decimal expectation = {
      {0b01000111110001010001111101010001, 0b1110110000001, 0, 13 << 16}};
  s21_decimal reality = {0};

  int result = s21_sub(first, second, &reality);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(s21_is_equal(expectation, reality), TRUE);
}
END_TEST

START_TEST(sub_12) {
  s21_decimal first = {{324423234, 0, 0, 8 << 16 | 1u << 31}};
  s21_decimal second = {{1231312367, 0, 0, 13 << 16 | 1u << 31}};
  s21_decimal expectation = {{0b01000111110001010001111101010001,
                              0b1110110000001, 0, 13 << 16 | 1u << 31}};
  s21_decimal reality = {0};

  int result = s21_sub(first, second, &reality);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(s21_is_equal(expectation, reality), TRUE);
}
END_TEST

START_TEST(sub_13) {
  s21_decimal first = {{324423234, 0, 0, 8 << 16}};
  s21_decimal second = {{1231312367, 0, 0, 13 << 16 | 1u << 31}};
  s21_decimal expectation = {
      {0b11011010100011011100101100101111, 0b1110110000001, 0, 13 << 16}};
  s21_decimal reality = {0};

  int result = s21_sub(first, second, &reality);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(s21_is_equal(expectation, reality), TRUE);
}
END_TEST

START_TEST(sub_14) {
  s21_decimal first = MAX_DECIMAL;
  s21_decimal second = {{6, 0, 0, 1 << 16}};
  s21_decimal expectation = {{MAX_BIT - 1, MAX_BIT, MAX_BIT, 0}};
  s21_decimal reality = {0};

  int result = s21_sub(first, second, &reality);
  // printBits(expectation);
  // printBits(reality);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(s21_is_equal(expectation, reality), TRUE);
}
END_TEST

START_TEST(sub_15) {
  s21_decimal first = {{MAX_BIT, MAX_BIT, MAX_BIT, 0}};
  s21_decimal second = {{5, 0, 0, 1 << 16}};
  s21_decimal expectation = {{MAX_BIT, MAX_BIT, MAX_BIT, 0}};
  s21_decimal reality = {0};

  int result = s21_sub(first, second, &reality);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(s21_is_equal(expectation, reality), TRUE);
}
END_TEST

START_TEST(sub_16) {
  s21_decimal first = {{MAX_BIT, MAX_BIT, MAX_BIT, 0}};
  s21_decimal second = {{15, 0, 0, 1 << 16}};
  s21_decimal expectation = {{MAX_BIT - 2, MAX_BIT, MAX_BIT, 0}};
  s21_decimal reality = {0};

  int result = s21_sub(first, second, &reality);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(s21_is_equal(expectation, reality), TRUE);
}
END_TEST

Suite *sub_tests(void) {
  Suite *s = suite_create("\033[45m-=S21_sub=-\033[0m");
  TCase *tc = tcase_create("sub_tc");

  tcase_add_test(tc, sub_1);
  tcase_add_test(tc, sub_2);
  tcase_add_test(tc, sub_3);
  tcase_add_test(tc, sub_4);
  tcase_add_test(tc, sub_5);
  tcase_add_test(tc, sub_6);
  tcase_add_test(tc, sub_7);
  tcase_add_test(tc, sub_8);
  tcase_add_test(tc, sub_9);
  tcase_add_test(tc, sub_10);
  tcase_add_test(tc, sub_11);
  tcase_add_test(tc, sub_12);
  tcase_add_test(tc, sub_13);
  tcase_add_test(tc, sub_14);
  tcase_add_test(tc, sub_15);
  tcase_add_test(tc, sub_16);

  suite_add_tcase(s, tc);
  return s;
}