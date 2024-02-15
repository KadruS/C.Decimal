#include "s21_decimal.h"

int s21_is_greater(s21_decimal val_1, s21_decimal val_2) {
  normalizeDecimal(&val_1, &val_2);
  int is_greater = 0;
  if (val_1.bits[0] == 0 && val_2.bits[0] == 0 && val_1.bits[1] == 0 &&
      val_2.bits[1] == 0 && val_1.bits[2] == 0 && val_2.bits[2] == 0) {
    is_greater = FALSE;
  } else if (!getSign(val_1) && getSign(val_2)) {
    is_greater = 1;
  } else if (!getSign(val_1) && !getSign(val_2)) {
    is_greater = val_1.bits[2] > val_2.bits[2]   ? 1
                 : val_1.bits[2] < val_2.bits[2] ? 0
                 : val_1.bits[1] > val_2.bits[1] ? 1
                 : val_1.bits[1] < val_2.bits[1] ? 0
                 : val_1.bits[0] > val_2.bits[0] ? 1
                                                 : 0;
  } else if (getSign(val_1) && getSign(val_2)) {
    is_greater = val_1.bits[2] < val_2.bits[2]   ? 1
                 : val_1.bits[2] > val_2.bits[2] ? 0
                 : val_1.bits[1] < val_2.bits[1] ? 1
                 : val_1.bits[1] > val_2.bits[1] ? 0
                 : val_1.bits[0] < val_2.bits[0] ? 1
                                                 : 0;
  }
  return is_greater;
}

int s21_is_equal(s21_decimal val_1, s21_decimal val_2) {
  int result = 1;
  if (val_1.bits[0] == 0 && val_2.bits[0] == 0 && val_1.bits[1] == 0 &&
      val_2.bits[1] == 0 && val_1.bits[2] == 0 && val_2.bits[2] == 0) {
    result = TRUE;
  } else {
    normalizeDecimal(&val_1, &val_2);
    result = val_1.bits[0] == val_2.bits[0] && val_1.bits[1] == val_2.bits[1] &&
             val_1.bits[2] == val_2.bits[2] && getSign(val_1) == getSign(val_2);
  }
  return result;
}

int s21_is_less(s21_decimal val_1, s21_decimal val_2) {
  return !s21_is_greater(val_1, val_2) && !s21_is_equal(val_1, val_2);
}

int s21_is_not_equal(s21_decimal val_1, s21_decimal val_2) {
  return !s21_is_equal(val_1, val_2);
}

int s21_is_greater_or_equal(s21_decimal val_1, s21_decimal val_2) {
  return s21_is_greater(val_1, val_2) || s21_is_equal(val_1, val_2);
}

int s21_is_less_or_equal(s21_decimal val_1, s21_decimal val_2) {
  return s21_is_less(val_1, val_2) || s21_is_equal(val_1, val_2);
}