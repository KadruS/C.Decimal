#include "tests.h"

START_TEST(div_1) {
  s21_decimal first = {{45, 0, 0, 0}};
  s21_decimal second = {{5, 0, 0, 0}};
  s21_decimal expectation = {{9, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(div_2) {
  s21_decimal first = {{45, 0, 0, 0}};
  s21_decimal second = {{5, 0, 0, MINUS}};
  s21_decimal expectation = {{9, 0, 0, MINUS}};
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(div_3) {
  s21_decimal first = {{MAX_BIT, 0, 0, 0}};
  s21_decimal second = {{5, 0, 0, 0}};
  s21_decimal expectation = {{858993459, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(div_4) {
  s21_decimal first = {{MAX_BIT, 0, 0, 0}};
  s21_decimal second = {{6, 0, 0, MINUS}};
  s21_decimal expectation = {{0b10101010101010101010101010101001, 1, 0, MINUS}};
  setExp(&expectation, 1);
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(div_5) {
  s21_decimal first = {{MAX_BIT, 0, 0, MINUS}};
  s21_decimal second = {{7, 0, 0, 0}};
  s21_decimal expectation = {{0b00010110011010110110110110110111,
                              0b01101100011110000001011100011110,
                              0b11000110010000010000110101110011, MINUS}};
  setExp(&expectation, 20);
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);
  //   printf("%d\n", getExp(reality));
  // printBits(expectation);
  // printBits(reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(div_6) {
  s21_decimal first = MAX_DECIMAL;
  s21_decimal second = {{7, 0, 0, 0}};
  s21_decimal expectation = {{0b01001001001001001001001001001001,
                              0b10010010010010010010010010010010,
                              0b100100100100100100100100100100, 0}};
  //   setExp(&expectation, 1);
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(div_7) {
  s21_decimal first = MAX_DECIMAL;
  s21_decimal second = MAX_DECIMAL;
  s21_decimal expectation = {{1, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST
// EXPS
START_TEST(div_8) {
  s21_decimal first = {{55000, 0, 0, MINUS}};
  s21_decimal second = {{5, 0, 0, 0}};
  setExp(&first, 3);
  s21_decimal expectation = {{11000, 0, 0, MINUS}};
  setExp(&expectation, 3);
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(div_9) {
  s21_decimal first = {{55000, 0, 0, MINUS}};
  s21_decimal second = {{5, 0, 0, MINUS}};
  setExp(&first, 10);
  setExp(&second, 5);
  s21_decimal expectation = {{11000, 0, 0, 0}};
  setExp(&expectation, 5);
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(div_10) {
  s21_decimal first = {{55000, 0, 0, MINUS}};
  s21_decimal second = {{5, 0, 0, MINUS}};
  setExp(&first, 10);
  setExp(&second, 11);
  s21_decimal expectation = {{110000, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);
  // printBits(expectation);
  // printBits(reality);
  // printf("%d\n", getExp(reality));

  ck_assert_int_eq(result, OK);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(div_11) {
  s21_decimal first = MAX_DECIMAL;
  s21_decimal second = {{1, 0, 0, 0}};
  setExp(&second, 1);
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);
  // printBits(expectation);
  // printBits(reality);

  ck_assert_int_eq(result, TOO_MUCH);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(div_12) {
  s21_decimal first = MIN_DECIMAL;
  s21_decimal second = {{1, 0, 0, 0}};
  setExp(&second, 1);
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);
  // printBits(expectation);
  // printBits(reality);

  ck_assert_int_eq(result, TOO_LOW);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(div_13) {
  s21_decimal first = MIN_DECIMAL;
  s21_decimal second = {{0, 0, 0, 0}};
  setExp(&second, 1);
  s21_decimal expectation = {{0, 0, 0, 0}};
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);
  // printBits(expectation);
  // printBits(reality);

  ck_assert_int_eq(result, DIV_ZERO);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(div_14) {
  s21_decimal first = {{44, 0, 0, 0}};
  s21_decimal second = {{880, 0, 0, 0}};
  s21_decimal expectation = {{5, 0, 0, 0}};
  setExp(&expectation, 2);
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST
// BANK ROUND
START_TEST(div_15) {
  s21_decimal first = {{MAX_BIT, MAX_BIT - 1, 0, 0}};
  s21_decimal second = {{46, 0, 0, 0}};
  s21_decimal expectation = {{0b11000001001101010001000100111000,
                              0b11111000110111000000011000010101,
                              0b10000001100100110100011111010010, 0}};
  setExp(&expectation, 11);
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(div_16) {
  s21_decimal first = {{123456, 0, 0, 0}};
  s21_decimal second = {{789, 0, 0, 0}};
  s21_decimal expectation = {{0b11010111000111100010110011000110,
                              0b01100111110001111001100001000010,
                              0b110010100011110000010010001000, 26 << 16}};
  // setExp(&expectation, 11);
  s21_decimal reality = {0};

  int result = s21_div(first, second, &reality);
  // printBits(expectation);
  // printBits(reality);
  // printf("%d\n", getExp(reality));
  // 15 647 148 288 973 384 030 418 250 950.5703
  ck_assert_int_eq(result, OK);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expectation.bits[i], reality.bits[i]);
  }
}
END_TEST

START_TEST(div_17) {
  unsigned int step_1 = 0 << 16;
  unsigned int step_2 = 5 << 16;

  s21_decimal value1 = {{4294967291, 4294967291, 4294967291, step_1}};
  s21_decimal value2 = {{2, 0, 0, step_2}};
  s21_decimal result = {{0, 0, 0, 0}};

  s21_decimal true_result = {{0, 0, 0, 0}};
  // real 229416403305712660714.217327377005241569724574572696
  //     22941640330571266071421732738
  // printBits(result);
  // printBits(true_result);
  // printf("%d\n", getExp(result));

  int status = s21_div(value1, value2, &result);

  ck_assert_int_eq(status, TOO_MUCH);
  ck_assert_int_eq(result.bits[3], true_result.bits[3]);
  ck_assert_int_eq(result.bits[2], true_result.bits[2]);
  ck_assert_int_eq(result.bits[1], true_result.bits[1]);
  ck_assert_int_eq(result.bits[0], true_result.bits[0]);
}
END_TEST

START_TEST(div_18) {
  unsigned int step_1 = 5 << 16;   // ;
  unsigned int step_2 = 10 << 16;  // ;
  s21_decimal value_1 = {
      {MAX_BIT, MAX_BIT, 4294967293, step_1}};  // 79228162477370849446124847103
  s21_decimal value_2 = {{345346546, 0, 0, step_2}};
  s21_decimal result = {{0, 0, 0, 0}};
  int status = s21_div(value_1, value_2, &result);
  s21_decimal true_result = {{0x2F3B4782, 0x56DDC86E, 0x4A20E14E, 3 << 16}};

  // result 22941640330571266071421732738
  //        229416403305712660714.217327377005241569724574572696
  //  printf("%d %d\n", getExp(result), getExp(true_result));

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[3], true_result.bits[3]);
  ck_assert_int_eq(result.bits[2], true_result.bits[2]);
  ck_assert_int_eq(result.bits[1], true_result.bits[1]);
  ck_assert_int_eq(result.bits[0], true_result.bits[0]);
}
END_TEST

START_TEST(div_19) {
  unsigned int step_1 = 0;  // ;
  unsigned int step_2 = 0;  // ;
  s21_decimal value_1 = {{4294967295, 4294967295, 4294967293,
                          step_1}};  // 79228162477370849446124847103
  s21_decimal value_2 = {{345346546, 0, 0, step_2}};
  s21_decimal result = {{0, 0, 0, 0}};
  int status = s21_div(value_1, value_2, &result);
  s21_decimal true_result = {{0x2F3B4782, 0x56DDC86E, 0x4A20E14E, 8 << 16}};
  // //real 229416403305712660714.217327377005241569724574572696
  // //     22941640330571266071421732738
  // printBits(result);
  // printBits(true_result);
  // printf("%d\n", getExp(result));

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(result.bits[3], true_result.bits[3]);
  ck_assert_int_eq(result.bits[2], true_result.bits[2]);
  ck_assert_int_eq(result.bits[1], true_result.bits[1]);
  ck_assert_int_eq(result.bits[0], true_result.bits[0]);
}
END_TEST

START_TEST(div_20) {
  unsigned int step_1 = 5 << 16;   // ;
  unsigned int step_2 = 10 << 16;  // ;
  s21_decimal value_1 = {
      {MAX_BIT, MAX_BIT, 4294967293, step_1}};  // 79228162477370849446124847103
  s21_decimal value_2 = {{345346546, 0, 0, step_2}};
  s21_decimal result = {{0, 0, 0, 0}};
  int status = s21_div(value_1, value_2, &result);
  s21_decimal true_result = {{0x2F3B4782, 0x56DDC86E, 0x4A20E14E, 3 << 16}};

  // result 22941640330571266071421732738
  //        229416403305712660714.217327377005241569724574572696
  //  printf("%d %d\n", getExp(result), getExp(true_result));

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[3], true_result.bits[3]);
  ck_assert_int_eq(result.bits[2], true_result.bits[2]);
  ck_assert_int_eq(result.bits[1], true_result.bits[1]);
  ck_assert_int_eq(result.bits[0], true_result.bits[0]);
}
END_TEST

Suite *div_tests(void) {
  Suite *s = suite_create("\033[45m-=S21_div=-\033[0m");
  TCase *tc = tcase_create("div_tc");

  tcase_add_test(tc, div_1);
  tcase_add_test(tc, div_2);
  tcase_add_test(tc, div_3);
  tcase_add_test(tc, div_4);
  tcase_add_test(tc, div_5);
  tcase_add_test(tc, div_6);
  tcase_add_test(tc, div_7);
  tcase_add_test(tc, div_8);
  tcase_add_test(tc, div_9);
  tcase_add_test(tc, div_10);
  tcase_add_test(tc, div_11);
  tcase_add_test(tc, div_12);
  tcase_add_test(tc, div_13);
  tcase_add_test(tc, div_14);
  tcase_add_test(tc, div_15);
  tcase_add_test(tc, div_16);
  tcase_add_test(tc, div_17);
  tcase_add_test(tc, div_18);
  tcase_add_test(tc, div_19);
  tcase_add_test(tc, div_20);

  suite_add_tcase(s, tc);
  return s;
}