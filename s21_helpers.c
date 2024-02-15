#include "s21_decimal.h"

int getBit128(s21_decimal decimal, int bit_index) {
  int number_of_bit = (bit_index < 32)                     ? 0
                      : (bit_index < 64 && bit_index > 31) ? 1
                      : (bit_index < 96 && bit_index > 63) ? 2
                                                           : 3;
  int result = (decimal.bits[number_of_bit] >> bit_index % 32) & 1;
  if (bit_index > 127 || bit_index < 0) {
    printf("Bit index range from 0 to 127!\n");
  }
  return result;
}
int getBit32(unsigned number, int bit_index) {
  int result = (number >> bit_index) & 1;
  if (bit_index > 31 || bit_index < 0) {
    printf("Bit index range from 0 to 31!\n");
  }
  return result;
}
int getSign(s21_decimal decimal) { return getBit128(decimal, 127); }

void printBits(s21_decimal decimal) {
  int bit;
  for (int i = 3; i >= 0; i--) {
    for (bit = sizeof(decimal.bits[i]) * 8 - 1; bit >= 0; bit--) {
      printf("%d", (decimal.bits[i] >> bit) & 1);
    }
  }
  printf("\n");
}

int setBit128(s21_decimal *decimal, int bit_index, int bit) {
  int result = 0;
  int number_of_bit = (bit_index < 32)                     ? 0
                      : (bit_index < 64 && bit_index > 31) ? 1
                      : (bit_index < 96 && bit_index > 63) ? 2
                                                           : 3;
  if (bit_index < 128 && bit_index >= 0) {
    if (bit == 1) {
      decimal->bits[number_of_bit] |= (1 << (bit_index % 32));
    } else if (bit == 0) {
      decimal->bits[number_of_bit] &= ~(1 << (bit_index % 32));
    } else {
      printf("Bit can be only 1 or 0!");
      result = 1;
    }
  } else {
    printf("Bit index out of range!");
    result = 1;
  }
  return result;
}
int setBit32(unsigned *number, int bit_index, int bit) {
  int result = 0;
  if (bit_index < 32 && bit_index >= 0) {
    if (bit == 1) {
      *number |= (1 << bit_index);
    } else if (bit == 0) {
      *number &= ~(1 << bit_index);
    } else {
      printf("Bit can be only 1 or 0!");
      result = 1;
    }
  } else {
    printf("Bit index out of range!");
    result = 1;
  }
  return result;
}
int setSign(s21_decimal *decimal, int bit) {
  return setBit128(decimal, 127, bit);
}

int setExp(s21_decimal *decimal, int exp) {
  int sign = getSign(*decimal);
  decimal->bits[3] = exp << 16;
  setSign(decimal, sign);
  return 0;
}
int getExp(s21_decimal decimal) {
  decimal.bits[3] <<= 1;
  decimal.bits[3] >>= 17;
  return decimal.bits[3];
}

int shiftLeft(s21_decimal *decimal) {
  int error = 0;
  int is_one = 0;
  for (int i = 2; i >= 0; i--) {
    if (getBit32(decimal->bits[i], 31) && !error) {
      error = (i == 2) ? 1 : 0;
      is_one = 1;
    }
    if (!error) {
      decimal->bits[i] <<= 1;
      if (i < 2) {
        setBit32(&decimal->bits[i + 1], 0, is_one);
        is_one = 0;
      }
    }
  }
  return error;
}

void resetDecimal(s21_decimal *decimal) {
  memset(decimal->bits, 0, sizeof(decimal->bits));
}

int mulByTen(s21_decimal *decimal) {
  int error = 0;
  s21_decimal buffer = *decimal;
  s21_decimal result = {0};
  s21_decimal temp = *decimal;
  error = shiftLeft(&temp);
  error = s21_add(result, temp, &result);

  error = shiftLeft(&temp);
  error = shiftLeft(&temp);
  error = s21_add(result, temp, &result);
  setExp(&result, getExp(*decimal));
  setSign(&result, getSign(*decimal));
  *decimal = result;

  if (error) {
    *decimal = buffer;
  }

  return error;
}

void normalizeDecimal(s21_decimal *value_1, s21_decimal *value_2) {
  int exp_1 = getExp(*value_1), exp_2 = getExp(*value_2),
      exp = abs(exp_1 - exp_2);
  s21_decimal ten = {{10, 0, 0, 0}};
  s21_decimal one = {{1, 0, 0, 0}};
  s21_decimal remainder_1 = {0};
  s21_decimal remainder_2 = {0};
  setExp(value_1, 0);
  setExp(value_2, 0);

  for (int i = 0; i < exp; i++) {
    if (exp_1 < exp_2) {
      int result = mulByTen(value_1);
      if (result) {
        resetDecimal(&remainder_2);
        s21_div_with_remainder(*value_2, ten, value_2, &remainder_2);
        exp_2--;
      } else {
        exp_1++;
      }
    } else if (exp_2 < exp_1) {
      int result = mulByTen(value_2);
      if (result) {
        resetDecimal(&remainder_1);
        s21_div_with_remainder(*value_1, ten, value_1, &remainder_1);
        exp_1--;
      } else {
        exp_2++;
      }
    }

    if ((!getBit128(*value_1, 0) && remainder_1.bits[0] > 5) ||
        (getBit128(*value_1, 0) && remainder_1.bits[0] > 4)) {
      s21_add(*value_1, one, value_1);
    } else if ((!getBit128(*value_2, 0) && remainder_2.bits[0] > 5) ||
               (getBit128(*value_2, 0) && remainder_2.bits[0] > 4)) {
      s21_add(*value_2, one, value_2);
    }
  }

  setExp(value_1, exp_1);
  setExp(value_2, exp_2);
}
