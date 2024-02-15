#include "tests.h"

// START_TEST(is_greater_1) {
//   s21_decimal first = MAX_DECIMAL;
//   s21_decimal second = MAX_DECIMAL;
//   s21_decimal expectation = {{0, 0, 0, 0}};
//   s21_decimal reality = {0};

//   int result = s21_is_greater(first, second);

//   ck_assert_int_eq(result, OK);
// }
// END_TEST

START_TEST(mulByTen_1) {
  s21_decimal first = {{MAX_BIT, 0, 0, 0}};
  s21_decimal expectation = {
      {0b11111111111111111111111111110110, 0b1001, 0, 0}};

  int result = mulByTen(&first);

  ck_assert_int_eq(result, OK);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(first.bits[i], expectation.bits[i]);
  }
}
END_TEST

START_TEST(mulByTen_2) {
  s21_decimal first = {{MAX_BIT, MAX_BIT, 0, 0}};
  s21_decimal expectation = {{0b11111111111111111111111111110110,
                              0b11111111111111111111111111111111, 0b1001, 0}};

  int result = mulByTen(&first);

  ck_assert_int_eq(result, OK);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(first.bits[i], expectation.bits[i]);
  }
}
END_TEST

START_TEST(mulByTen_3) {
  s21_decimal first = {{MAX_BIT, MAX_BIT, MAX_BIT, 0}};
  s21_decimal expectation = MAX_DECIMAL;

  int result = mulByTen(&first);

  ck_assert_int_eq(result, TOO_MUCH);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(first.bits[i], expectation.bits[i]);
  }
}
END_TEST

START_TEST(mulByTen_4) {
  s21_decimal first = {{0b10011001100110011001100110011001,
                        0b10011001100110011001100110011001,
                        0b11001100110011001100110011001, 0}};
  s21_decimal expectation = {
      {0b11111111111111111111111111111010, MAX_BIT, MAX_BIT, 0}};

  int result = mulByTen(&first);

  ck_assert_int_eq(result, OK);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(first.bits[i], expectation.bits[i]);
  }
}
END_TEST

START_TEST(mulByTen_5) {
  s21_decimal first = {{0b10011001100110011001100110011010,
                        0b10011001100110011001100110011001,
                        0b11001100110011001100110011001, 0}};
  s21_decimal expectation = first;

  int result = mulByTen(&first);

  ck_assert_int_eq(result, TOO_MUCH);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(first.bits[i], expectation.bits[i]);
  }
}
END_TEST

START_TEST(normalizeDecimal_1) {
  unsigned exp = 1 << 16;
  s21_decimal first = {{23, 0, 0, exp}};
  s21_decimal second = {{44, 0, 0, 0}};
  s21_decimal expectation_1 = {{23, 0, 0, exp}};
  s21_decimal expectation_2 = {{440, 0, 0, exp}};

  normalizeDecimal(&first, &second);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(first.bits[i], expectation_1.bits[i]);
    ck_assert_int_eq(second.bits[i], expectation_2.bits[i]);
  }
}
END_TEST

START_TEST(normalizeDecimal_2) {
  unsigned exp = 13 << 16;
  s21_decimal first = {{23, 0, 0, 0}};
  s21_decimal second = {{43454, 0, 0, exp}};
  s21_decimal expectation_1 = {
      {0b00001100010011000110000000000000, 0b1101000100101111, 0, exp}};
  s21_decimal expectation_2 = {{43454, 0, 0, exp}};

  normalizeDecimal(&first, &second);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(first.bits[i], expectation_1.bits[i]);
    ck_assert_int_eq(second.bits[i], expectation_2.bits[i]);
  }
}
END_TEST

START_TEST(normalizeDecimal_3) {
  unsigned exp = 13 << 16;
  s21_decimal first = {{23, 0, 0, 0}};
  s21_decimal second = {{43454, 0, 0, exp}};
  s21_decimal expectation_1 = {
      {0b00001100010011000110000000000000, 0b1101000100101111, 0, exp}};
  s21_decimal expectation_2 = {{43454, 0, 0, exp}};

  normalizeDecimal(&first, &second);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(first.bits[i], expectation_1.bits[i]);
    ck_assert_int_eq(second.bits[i], expectation_2.bits[i]);
  }
}
END_TEST

START_TEST(normalizeDecimal_4) {
  unsigned exp = 13 << 16;
  s21_decimal first = {{23, 0, 0, exp}};
  s21_decimal second = {{MAX_BIT, MAX_BIT, MAX_BIT, 0}};
  s21_decimal expectation_1 = {{0, 0, 0, 0}};
  s21_decimal expectation_2 = {{MAX_BIT, MAX_BIT, MAX_BIT, 0}};

  normalizeDecimal(&first, &second);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(first.bits[i], expectation_1.bits[i]);
    ck_assert_int_eq(second.bits[i], expectation_2.bits[i]);
  }
}
END_TEST

START_TEST(normalizeDecimal_5) {
  unsigned exp = 13 << 16;
  s21_decimal first = {{MAX_BIT, MAX_BIT, MAX_BIT, exp}};
  s21_decimal second = {{MAX_BIT, MAX_BIT, MAX_BIT, 0}};
  s21_decimal expectation_1 = {
      {0b01101000010010010111011010000010, 0b111000010010111000010, 0, 0}};
  s21_decimal expectation_2 = {{MAX_BIT, MAX_BIT, MAX_BIT, 0}};

  normalizeDecimal(&first, &second);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(first.bits[i], expectation_1.bits[i]);
    ck_assert_int_eq(second.bits[i], expectation_2.bits[i]);
  }
}
END_TEST

Suite *helpers_tests(void) {
  Suite *s = suite_create("\033[45m-=HELPERS=-\033[0m");
  TCase *tc = tcase_create("helpers_tc");

  tcase_add_test(tc, mulByTen_1);
  tcase_add_test(tc, mulByTen_2);
  tcase_add_test(tc, mulByTen_3);
  tcase_add_test(tc, mulByTen_4);
  tcase_add_test(tc, mulByTen_5);
  tcase_add_test(tc, normalizeDecimal_1);
  tcase_add_test(tc, normalizeDecimal_2);
  tcase_add_test(tc, normalizeDecimal_3);
  tcase_add_test(tc, normalizeDecimal_4);
  tcase_add_test(tc, normalizeDecimal_5);

  suite_add_tcase(s, tc);
  return s;
}