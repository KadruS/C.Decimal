#include "tests.h"

START_TEST(s21_round_1) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 5;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;

  origin.bits[0] = 1;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 34;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;

  origin.bits[0] = 3;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;

  origin.bits[0] = 0;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 24363463;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b10000000000001110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;

  origin.bits[0] = 2;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000000000000000000000000;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_5) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 65234631;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b00000000000001010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;

  origin.bits[0] = 652;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_6) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 497623323;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b00000000000010000000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;

  origin.bits[0] = 5;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_7) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0b10000111010110110010011111110011;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0;
  src.bits[3] = 0b00000000000000100000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;

  origin.bits[0] = 0b00000011111010011101111100011111;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_8) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 364748110;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b10000000000000110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;

  origin.bits[0] = 364748;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000000000000000000000000;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_9) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0b01101000011010011010001100101111;
  src.bits[1] = 0b00000000000000000001001000010011;
  src.bits[2] = 0;
  src.bits[3] = 0b00000000000011010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;

  origin.bits[0] = 2;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_10) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0b00010110010010101110101011000000;
  src.bits[1] = 0b00000000000000000000100011111100;
  src.bits[2] = 0;
  src.bits[3] = 0b10000000000010110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;

  origin.bits[0] = 0b00000000000000000000000001100011;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000000000000000000000000;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_11) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0b10110010001111111111110010001001;
  src.bits[1] = 0b00011001111000001100100110111010;
  src.bits[2] = 0b00000000000000000000001000011110;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;

  origin.bits[0] = 0b11011110100111111111111110100111;
  origin.bits[1] = 0b00110101110010011010110111000101;
  origin.bits[2] = 0b00000000000000000000000000110110;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_12) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b10000000000011100000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;

  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000000000000000000000000;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_13) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b00000000000011100000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;

  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_14) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0b01001110111001000011100101110110;
  src.bits[1] = 0b01001011001101011010000111011001;
  src.bits[2] = 0b00011001101110010111010010111111;
  src.bits[3] = 0b00000000000011110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;

  origin.bits[0] = 0b10100100000111100100000000101110;
  origin.bits[1] = 0b00000000000000000000011100111101;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_15) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b00000000000101010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;

  origin.bits[0] = 12345678;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_1) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 50;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;

  origin.bits[0] = 5;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 34;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;

  origin.bits[0] = 3;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;

  origin.bits[0] = 0;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_4) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 24363463;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b10000000000001110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;

  origin.bits[0] = 3;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000000000000000000000000;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_5) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 45;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b10000000000000100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000000000000000000000000;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_6) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 65234631;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b00000000000001010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;

  origin.bits[0] = 652;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_7) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 497623323;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b00000000000010000000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;

  origin.bits[0] = 4;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_8) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0b10000111010110110010011111110011;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0;
  src.bits[3] = 0b00000000000000100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;

  origin.bits[0] = 65658654;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_9) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 364748110;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b10000000000000110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;

  origin.bits[0] = 364749;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000000000000000000000000;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_10) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0b01101000011010011010001100101111;
  src.bits[1] = 0b00000000000000000001001000010011;
  src.bits[2] = 0;
  src.bits[3] = 0b00000000000011010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;

  origin.bits[0] = 1;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_11) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0b00010110010010101110101011000000;
  src.bits[1] = 0b00000000000000000000100011111100;
  src.bits[2] = 0;
  src.bits[3] = 0b10000000000010110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;

  origin.bits[0] = 0b00000000000000000000000001100011;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000000000000000000000000;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_12) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0b10110010001111111111110010001001;
  src.bits[1] = 0b00011001111000001100100110111010;
  src.bits[2] = 0b00000000000000000000001000011110;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;

  origin.bits[0] = 0b11011110100111111111111110100111;
  origin.bits[1] = 0b00110101110010011010110111000101;
  origin.bits[2] = 0b00000000000000000000000000110110;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_13) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b10000000000011100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;

  origin.bits[0] = 0b10000110011101001011101110010010;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000000000000000000000000;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_14) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b00000000000011100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;

  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_15) {
  s21_decimal src = {0}, origin = {0}, result = {0};

  src.bits[0] = 0b01001110111001000011100101110110;
  src.bits[1] = 0b01001011001101011010000111011001;
  src.bits[2] = 0b00011001101110010111010010111111;
  src.bits[3] = 0b00000000000011110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;

  origin.bits[0] = 0b10100100000111100100000000101101;
  origin.bits[1] = 0b00000000000000000000011100111101;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_1) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 21234;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000001000000000000000000;

  origin.bits[0] = 21234;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000001000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_2) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 457000001;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000001100000000000000000;

  origin.bits[0] = 457000001;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000001100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_3) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 2000;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000110000000000000000;

  origin.bits[0] = 2000;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000000110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_4) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 0;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000110110000000000000000;

  origin.bits[0] = 0;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b00000000000110110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_5) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 3;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;

  origin.bits[0] = 3;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_6) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 2222212;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000001100000000000000000;

  origin.bits[0] = 2222212;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000001100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_7) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000100010000000000000000;

  origin.bits[0] = 0b00000111100011111010001111101000;
  origin.bits[1] = 0b00000011000101010111110100000001;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000100010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_8) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 0b11011111010000111010111001110101;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000010010000000000000000;

  origin.bits[0] = 0b11011111010000111010111001110101;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000010010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_9) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000001100000000000000000;

  origin.bits[0] = 0b00000000001000011110100010000100;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000001100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_10) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;

  origin.bits[0] = 0b00000000000001011001000011001100;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_1) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 21234;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000001000000000000000000;

  origin.bits[0] = 2;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 457000001;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000001100000000000000000;

  origin.bits[0] = 457;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_3) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 2000;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000110000000000000000;

  origin.bits[0] = 2;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_4) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 3;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;

  origin.bits[0] = 3;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_5) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 2222212;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000001100000000000000000;

  origin.bits[0] = 2;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_6) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000100010000000000000000;

  origin.bits[0] = 2;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_7) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 3745754741;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000010010000000000000000;

  origin.bits[0] = 3;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_8) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 2222212;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000001100000000000000000;

  origin.bits[0] = 2;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_9) {
  s21_decimal src1 = {0}, origin = {0}, result = {0};

  src1.bits[0] = 364748;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;

  origin.bits[0] = 364748;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(check, check_origin);
}
END_TEST

Suite *other_tests(void) {
  Suite *s = suite_create("\033[45m-=OTHERS=-\033[0m");
  TCase *tc = tcase_create("other_tc");

  tcase_add_test(tc, s21_negate_1);
  tcase_add_test(tc, s21_negate_2);
  tcase_add_test(tc, s21_negate_3);
  tcase_add_test(tc, s21_negate_4);
  tcase_add_test(tc, s21_negate_5);
  tcase_add_test(tc, s21_negate_6);
  tcase_add_test(tc, s21_negate_7);
  tcase_add_test(tc, s21_negate_8);
  tcase_add_test(tc, s21_negate_9);

  tcase_add_test(tc, s21_round_1);
  tcase_add_test(tc, s21_round_2);
  tcase_add_test(tc, s21_round_3);
  tcase_add_test(tc, s21_round_4);
  tcase_add_test(tc, s21_round_5);
  tcase_add_test(tc, s21_round_6);
  tcase_add_test(tc, s21_round_7);
  tcase_add_test(tc, s21_round_8);
  tcase_add_test(tc, s21_round_9);
  tcase_add_test(tc, s21_round_10);
  tcase_add_test(tc, s21_round_11);
  tcase_add_test(tc, s21_round_12);
  tcase_add_test(tc, s21_round_13);
  tcase_add_test(tc, s21_round_14);
  tcase_add_test(tc, s21_round_15);

  tcase_add_test(tc, s21_floor_1);
  tcase_add_test(tc, s21_floor_2);
  tcase_add_test(tc, s21_floor_3);
  tcase_add_test(tc, s21_floor_4);
  tcase_add_test(tc, s21_floor_5);
  tcase_add_test(tc, s21_floor_6);
  tcase_add_test(tc, s21_floor_7);
  tcase_add_test(tc, s21_floor_8);
  tcase_add_test(tc, s21_floor_9);
  tcase_add_test(tc, s21_floor_10);
  tcase_add_test(tc, s21_floor_11);
  tcase_add_test(tc, s21_floor_12);
  tcase_add_test(tc, s21_floor_13);
  tcase_add_test(tc, s21_floor_14);
  tcase_add_test(tc, s21_floor_15);

  tcase_add_test(tc, s21_truncate_1);
  tcase_add_test(tc, s21_truncate_2);
  tcase_add_test(tc, s21_truncate_3);
  tcase_add_test(tc, s21_truncate_4);
  tcase_add_test(tc, s21_truncate_5);
  tcase_add_test(tc, s21_truncate_6);
  tcase_add_test(tc, s21_truncate_7);
  tcase_add_test(tc, s21_truncate_8);
  tcase_add_test(tc, s21_truncate_9);

  suite_add_tcase(s, tc);
  return s;
}
