#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  setSign(result, !getSign(value));
  return 0;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int error = 0;
  int exp = getExp(value);
  int sign = getSign(value);
  s21_decimal ten = {{10, 0, 0, 0}};
  s21_decimal one = {{1, 0, 0, 0}};
  s21_decimal remainder = {0};

  setExp(&value, 0);
  setSign(&value, 0);

  while (exp > 0) {
    s21_div_with_remainder(value, ten, &value, &remainder);
    exp--;
  }

  if (sign && remainder.bits[0] != 0) {
    error = s21_add(value, one, &value);
  }

  *result = value;
  setSign(result, sign);
  error = error == 0 ? 0 : 1;
  return error;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int error = 0;
  int exp = getExp(value);
  int sign = getSign(value);
  s21_decimal ten = {{10, 0, 0, 0}};
  s21_decimal one = {{1, 0, 0, 0}};
  s21_decimal remainder = {0};

  setExp(&value, 0);
  setSign(&value, 0);

  while (exp > 0) {
    s21_div_with_remainder(value, ten, &value, &remainder);
    exp--;
  }

  if (remainder.bits[0] >= 5) {
    error = s21_add(value, one, &value);
  }

  *result = value;
  setSign(result, sign);
  error = error == 0 ? 0 : 1;
  return error;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  int exp = getExp(value);
  int sign = getSign(value);
  s21_decimal ten = {{10, 0, 0, 0}};
  s21_decimal remainder = {0};

  setExp(&value, 0);
  setSign(&value, 0);

  while (exp > 0) {
    s21_div_with_remainder(value, ten, &value, &remainder);
    exp--;
  }

  *result = value;
  setSign(result, sign);
  error = error == 0 ? 0 : 1;
  return error;
}