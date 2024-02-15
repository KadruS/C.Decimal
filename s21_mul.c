#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;
  int sign_1 = getSign(value_1), sign_2 = getSign(value_2);
  setSign(&value_1, 0);
  setSign(&value_2, 1);
  int exp_1 = getExp(value_1), exp_2 = getExp(value_2), exp = exp_1 + exp_2;

  s21_decimal zero = {0};
  resetDecimal(result);
  value_2.bits[3] = 0;

  if (s21_is_not_equal(value_1, zero) && s21_is_not_equal(value_2, zero)) {
    for (int j = 0; j < 3 && error == 0; j++) {
      for (int i = 0; i < 32 && error == 0; i++) {
        if (getBit32(value_1.bits[j], i)) {
          result->bits[3] = 0;
          error = s21_add(value_2, *result, result);
        }
        shiftLeft(&value_2);
      }
    }
    setExp(result, exp);

    if ((sign_1 ^ sign_2) == 1) {
      setBit128(result, 127, 1);
    }

    if (getSign(*result) && error == 1) {
      error = TOO_LOW;
    }

    if (error > 0) {
      resetDecimal(result);
    }
  }
  return error;
}
