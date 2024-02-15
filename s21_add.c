#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  resetDecimal(result);
  int sign_1 = getSign(value_1), sign_2 = getSign(value_2), sign_result = 0;

  if (sign_1 == 1 && sign_2 == 0) {
    setSign(&value_1, 0);
    error = s21_sub(value_2, value_1, result);
  } else if (sign_1 == 0 && sign_2 == 1) {
    setSign(&value_2, 0);
    error = s21_sub(value_1, value_2, result);
  } else {
    sign_result = sign_1;
    normalizeDecimal(&value_1, &value_2);

    int odin_v_ume = 0;
    for (int i = 0; i < 96; i++) {
      if (getBit128(value_1, i) && getBit128(value_2, i)) {
        setBit128(result, i, 0 + odin_v_ume);
        odin_v_ume = 1;
      } else if (getBit128(value_1, i) || getBit128(value_2, i)) {
        setBit128(result, i, 1 - odin_v_ume);
        odin_v_ume = odin_v_ume ? 1 : 0;
      } else {
        setBit128(result, i, odin_v_ume);
        odin_v_ume = 0;
      }
    }

    setExp(result, getExp(value_1));
    setSign(result, sign_result);
    if (sign_result && odin_v_ume) {
      odin_v_ume = 2;
    }
    error = odin_v_ume;
  }
  if (error) {
    resetDecimal(result);
  }

  return error;
}