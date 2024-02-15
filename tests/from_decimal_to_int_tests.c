#include "tests.h"

START_TEST(fdti_1) {
  s21_decimal dec = {0};
  dec.bits[0] = 10;
  int expectation = 10;
  int reality = 0;

  ck_assert_int_eq(0, s21_from_decimal_to_int(dec, &reality));
  ck_assert_int_eq(expectation, reality);
}
END_TEST

START_TEST(fdti_2) {
  s21_decimal dec = {0};
  dec.bits[0] = 0b10000000000000000000000000000000;
  setSign(&dec, 1);

  int expectation = -2147483648;
  int reality = 0;

  int result = s21_from_decimal_to_int(dec, &reality);
  ck_assert_int_eq(0, result);
  ck_assert_int_eq(expectation, reality);
}
END_TEST

START_TEST(fdti_3) {
  s21_decimal dec = {0};
  dec.bits[0] = 0b10000000000000000000000000000000;

  int expectation = 0;
  int reality = 0;

  ck_assert_int_eq(1, s21_from_decimal_to_int(dec, &reality));
  ck_assert_int_eq(expectation, reality);
}
END_TEST

START_TEST(fdti_4) {
  s21_decimal dec = {0};
  dec.bits[0] = 23647326;
  setSign(&dec, 1);

  int expectation = -23647326;
  int reality = 0;

  ck_assert_int_eq(0, s21_from_decimal_to_int(dec, &reality));
  ck_assert_int_eq(expectation, reality);
}
END_TEST

START_TEST(fdti_5) {
  s21_decimal dec = {0};
  dec.bits[0] = 99;
  setExp(&dec, 1);
  // setSign(&dec, 1);

  int expectation = 9;
  int reality = 0;

  ck_assert_int_eq(0, s21_from_decimal_to_int(dec, &reality));
  ck_assert_int_eq(expectation, reality);
}
END_TEST

START_TEST(fdti_6) {
  s21_decimal dec = {{19, 0, 0, 1 << 16}};
  int expectation = 1;
  int reality = 0;

  ck_assert_int_eq(0, s21_from_decimal_to_int(dec, &reality));
  ck_assert_int_eq(expectation, reality);
}
END_TEST

START_TEST(fdti_7) {
  s21_decimal dec = {{29, 0, 0, 1 << 16}};
  int expectation = 2;
  int reality = 0;

  ck_assert_int_eq(0, s21_from_decimal_to_int(dec, &reality));
  ck_assert_int_eq(expectation, reality);
}
END_TEST

START_TEST(fdti_8) {
  s21_decimal dec = {{213, 0, 0, 2 << 16}};
  int expectation = 2;
  int reality = 0;

  ck_assert_int_eq(0, s21_from_decimal_to_int(dec, &reality));
  ck_assert_int_eq(expectation, reality);
}
END_TEST

START_TEST(fdti_9) {
  s21_decimal dec = {{213, 0, 0, 1 << 16 | 1u << 31}};
  int expectation = -21;
  int reality = 0;

  ck_assert_int_eq(0, s21_from_decimal_to_int(dec, &reality));
  ck_assert_int_eq(expectation, reality);
}
END_TEST

START_TEST(fdti_10) {
  s21_decimal dec = {{213, 1, 0, 1u << 31}};
  int expectation = 0;
  int reality = 0;

  ck_assert_int_eq(1, s21_from_decimal_to_int(dec, &reality));
  ck_assert_int_eq(expectation, reality);
}
END_TEST

Suite *from_decimal_to_int_tests(void) {
  Suite *s = suite_create("\033[45m-=S21_fdti=-\033[0m");
  TCase *tc = tcase_create("fdti_tc");

  tcase_add_test(tc, fdti_1);
  tcase_add_test(tc, fdti_2);
  tcase_add_test(tc, fdti_3);
  tcase_add_test(tc, fdti_4);
  tcase_add_test(tc, fdti_5);
  tcase_add_test(tc, fdti_6);
  tcase_add_test(tc, fdti_7);
  tcase_add_test(tc, fdti_8);
  tcase_add_test(tc, fdti_9);
  tcase_add_test(tc, fdti_10);

  suite_add_tcase(s, tc);
  return s;
}
