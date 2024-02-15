#include "tests.h"

START_TEST(fftd_1) {
  s21_decimal val;
  s21_from_float_to_decimal(0.03F, &val);

  ck_assert_int_eq(val.bits[0], 3000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 524288);
  s21_from_float_to_decimal(127.1234F, &val);
  ck_assert_int_eq(val.bits[0], 1271234);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 262144);
}
END_TEST

START_TEST(fftd_2) {
  s21_decimal val;
  s21_from_float_to_decimal(22.14836E+03F, &val);
  ck_assert_int_eq(val.bits[0], 2214836);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 131072);
}
END_TEST

START_TEST(fftd_3) {
  s21_decimal val;
  s21_from_float_to_decimal(1.02E+09F, &val);
  // printf("%u\n", val.bits[0]);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(fftd_4) {
  s21_decimal val;
  float a = 1.0F / 0.0F;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(fftd_5) {
  s21_decimal val;
  float a = -1.0F / 0.0F;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(fftd_6) {
  s21_decimal val;
  float a = NAN;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(fftd_7) {
  s21_decimal val;
  s21_from_float_to_decimal(0.0F, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(fftd_8) {
  float f1 = 235345.343;
  s21_decimal reality = {0};
  s21_decimal expectation = {{2353453, 0, 0, 1 << 16}};

  s21_from_float_to_decimal(f1, &reality);

  // printBits(reality);
  // printBits(expectation);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(fftd_9) {
  float f1 = -235345.343;
  s21_decimal reality = {0};
  s21_decimal expectation = {{2353453, 0, 0, 1 << 16 | 1u << 31}};

  s21_from_float_to_decimal(f1, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(fftd_10) {
  float f1 = 1.0;
  s21_decimal reality = {0};
  s21_decimal expectation = {{1000000, 0, 0, 6 << 16}};

  s21_from_float_to_decimal(f1, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

Suite *from_float_to_decimal_tests(void) {
  Suite *s = suite_create("\033[45m-=S21_fftd=-\033[0m");
  TCase *tc = tcase_create("fftd_tc");

  tcase_add_test(tc, fftd_1);
  tcase_add_test(tc, fftd_2);
  tcase_add_test(tc, fftd_3);
  tcase_add_test(tc, fftd_4);
  tcase_add_test(tc, fftd_5);
  tcase_add_test(tc, fftd_6);
  tcase_add_test(tc, fftd_7);
  tcase_add_test(tc, fftd_8);
  tcase_add_test(tc, fftd_9);
  tcase_add_test(tc, fftd_10);

  suite_add_tcase(s, tc);
  return s;
}
