#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  resetDecimal(result);
  int error = 0;
  int sign_1 = getSign(value_1), sign_2 = getSign(value_2), sign_result = 0;

  if (sign_1 == 1 && sign_2 == 0) {
    setSign(&value_2, 1);
    error = s21_add(value_1, value_2, result);
  } else if (sign_1 == 0 && sign_2 == 1) {
    setSign(&value_2, 0);
    error = s21_add(value_1, value_2, result);
  } else {
    sign_result = sign_2;
    setSign(&value_2, 0);
    setSign(&value_1, 0);
    normalizeDecimal(&value_1, &value_2);

    if (s21_is_greater(value_1, value_2)) {
      int j = 0;
      for (int i = 0; i < 96; i++) {
        if (getBit128(value_1, i) && !getBit128(value_2, i)) {
          setBit128(result, i, 1);
        } else if (!getBit128(value_1, i) && getBit128(value_2, i)) {
          j = i + 1;
          for (; !getBit128(value_1, j) && j < 96; j++) {
            setBit128(&value_1, j, 1);
          }
          setBit128(&value_1, j, 0);
          setBit128(result, i, 1);
        } else {
          setBit128(result, i, 0);
        }
      }
    } else if (s21_is_less(value_1, value_2)) {
      sign_result = 1;
      s21_decimal temp = value_1;
      value_1 = value_2;
      value_2 = temp;

      int j = 0;
      for (int i = 0; i < 96; i++) {
        if (getBit128(value_1, i) && !getBit128(value_2, i)) {
          setBit128(result, i, 1);
        } else if (!getBit128(value_1, i) && getBit128(value_2, i)) {
          j = i + 1;
          for (; !getBit128(value_1, j) && j < 96; j++) {
            setBit128(&value_1, j, 1);
          }
          setBit128(&value_1, j, 0);
          setBit128(result, i, 1);
        } else {
          setBit128(result, i, 0);
        }
      }
    }
    setExp(result, getExp(value_1));
    setSign(result, sign_result);
  }
  return error;
}