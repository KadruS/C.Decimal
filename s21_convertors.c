#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  resetDecimal(dst);
  int error = 0;
  if (src != -2147483648) {
    dst->bits[0] = (src > 0) ? src : -1 * src;
    if ((src >> 31) & 1) {
      setBit128(dst, 31, 0);
      setBit128(dst, 127, 1);
    }
  } else {
    dst->bits[0] = 0b10000000000000000000000000000000;
    setBit128(dst, 127, 1);
  }
  return error;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = 0;
  *dst = 0;
  if (dst == NULL) {
    error = 1;
  } else {
    int sign = 1;
    long double result = 0, two = 1;
    int exp = getExp(src);
    if (getSign(src)) sign = -1;
    for (int i = 0; i < 96; i++) {
      if (getBit128(src, i)) {
        result += two;
      }
      two *= 2;
    }
    for (int i = 0; i < exp; i++) {
      result /= 10;
    }
    *dst = sign * result;
  }
  return error;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  s21_decimal ten = {0};
  s21_decimal remainder = {0};
  ten.bits[0] = 10;
  int error = 0;
  int exp = getExp(src);
  int sign = getSign(src);

  setExp(&src, 0);
  setSign(&src, 0);
  while (exp > 0) {
    s21_div_with_remainder(src, ten, &src, &remainder);
    exp--;
  }
  if (src.bits[2] != 0 || src.bits[1] != 0) {
    error = 1;
  } else {
    error = ((src.bits[0] > 2147483648) || (src.bits[0] == 2147483648 && !sign))
                ? 1
                : 0;
    if (src.bits[0] == 2147483648 && sign) {
      *dst = -2147483648;
    } else if (!error) {
      *dst = sign ? (src.bits[0] * -1) : src.bits[0];
    }
  }
  return error;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  resetDecimal(dst);
  char buffer[110] = {0};
  int integ = 0, dec = 0, scale = 0;
  int sign = 0;

  snprintf(buffer, sizeof(buffer), "%.6e", src);
  sscanf(buffer, "%d.%de%d", &integ, &dec, &scale);

  int error =
      (src == 1.0F / 0.0F || src == -1.0F / 0.0F || buffer[0] == 'n') ? 1 : 0;

  if (integ < 0) {
    integ *= -1;
    sign = 1;
  }
  for (int i = 0; i < 6; i++) {
    integ *= 10;
  }
  scale = 6 - scale;
  integ += dec;
  dst->bits[0] = integ;

  while (scale < 0) {
    mulByTen(dst);
    scale += 1;
  }

  if (dst->bits[0] != 0) {
    dst->bits[3] = scale << 16 | sign << 31;
  }
  return error;
}
