#include "tests.h"

START_TEST(fdtf_1) {
  float reality = 0;
  float expectation = 22.345;
  s21_decimal decimal = {{0b101011101001001, 0, 0, 0}};
  setExp(&decimal, 3);

  s21_from_decimal_to_float(decimal, &reality);
  ck_assert_float_eq(reality, expectation);
}
END_TEST

START_TEST(fdtf_2) {
  s21_decimal number;
  // decimal: -0.8
  // float: -0.8
  // int: -1085485875
  number.bits[0] = 0b00000000000000000000000000001000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000010000000000000000;
  int result_int = -1085485875;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(fdtf_3) {
  s21_decimal number;
  // decimal: 0
  // float: 0
  // int: 0
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 0;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(fdtf_4) {
  s21_decimal number;
  // decimal: 1
  // float: 1
  // int: 1065353216
  number.bits[0] = 0b00000000000000000000000000000001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1065353216;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(fdtf_5) {
  s21_decimal number;
  // decimal: 0.0
  // float: 0
  // int: -2147483648
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000010000000000000000;
  int result_int = -2147483648;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(fdtf_6) {
  s21_decimal number;
  // decimal: -1.75
  // float: -1.75
  // int: -1075838976
  number.bits[0] = 0b00000000000000000000000010101111;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000100000000000000000;
  int result_int = -1075838976;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(fdtf_7) {
  s21_decimal number;
  // decimal: 6521
  // float: 6521
  // int: 1170982912
  number.bits[0] = 0b00000000000000000001100101111001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1170982912;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(fdtf_8) {
  s21_decimal number;
  // decimal: 4
  // float: 4
  // int: 1082130432
  number.bits[0] = 0b00000000000000000000000000000100;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1082130432;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(fdtf_9) {
  s21_decimal number;
  // decimal: 65658654
  // float: 6.565866E+07
  // int: 1283094472
  number.bits[0] = 0b00000011111010011101111100011110;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1283094472;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(fdtf_10) {
  s21_decimal number;
  // decimal: -364748
  // float: -364748
  // int: -927852160
  number.bits[0] = 0b00000000000001011001000011001100;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -927852160;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(fdtf_11) {
  s21_decimal number;
  // decimal: 0.003
  // float: 0.003
  // int: 994352038
  number.bits[0] = 0b00000000000000000000000000000011;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000110000000000000000;
  int result_int = 994352038;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(fdtf_12) {
  s21_decimal number;
  // decimal: -9878798789
  // float: -9.878798E+09
  // int: -804047712
  number.bits[0] = 0b01001100110100101000000111000101;
  number.bits[1] = 0b00000000000000000000000000000010;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -804047712;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(fdtf_13) {
  s21_decimal number;
  // decimal: 9959999999999999999
  // float: 9.96E+18
  // int: 1594505479
  number.bits[0] = 0b11001010111000111111111111111111;
  number.bits[1] = 0b10001010001110010000011100111010;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1594505479;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

Suite *from_decimal_to_float_tests(void) {
  Suite *s = suite_create("\033[45m-=S21_fdtf=-\033[0m");
  TCase *tc = tcase_create("fdtf_tc");

  tcase_add_test(tc, fdtf_1);
  tcase_add_test(tc, fdtf_2);
  tcase_add_test(tc, fdtf_3);
  tcase_add_test(tc, fdtf_4);
  tcase_add_test(tc, fdtf_5);
  tcase_add_test(tc, fdtf_6);
  tcase_add_test(tc, fdtf_7);
  tcase_add_test(tc, fdtf_8);
  tcase_add_test(tc, fdtf_9);
  tcase_add_test(tc, fdtf_10);
  tcase_add_test(tc, fdtf_11);
  tcase_add_test(tc, fdtf_12);
  tcase_add_test(tc, fdtf_13);

  suite_add_tcase(s, tc);
  return s;
}
