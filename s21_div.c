#include "s21_decimal.h"

int s21_div_with_remainder(s21_decimal value_1, s21_decimal value_2,
                           s21_decimal *result, s21_decimal *remainder) {
  int error = 0;
  resetDecimal(result);
  resetDecimal(remainder);
  s21_decimal value_2_changeble = value_2;
  s21_decimal pow_2 = {0};
  pow_2.bits[0] = 1;

  s21_decimal devider = {0};

  if (s21_is_less(value_1, value_2)) {
    *remainder = value_1;
  }

  while (s21_is_greater_or_equal(value_1, value_2)) {
    int q = 0;
    for (; s21_is_less_or_equal(value_2_changeble, value_1) &&
           !getBit128(value_2_changeble, 95);
         q++) {
      error = shiftLeft(&value_2_changeble);
    }

    while (q > 1) {
      error = shiftLeft(&pow_2);
      q--;
    }
    error = s21_add(*result, pow_2, result);
    error = s21_mul(value_2, pow_2, &devider);
    error = s21_sub(value_1, devider, &value_1);
    *remainder = value_1;

    memset(devider.bits, 0, sizeof(devider.bits));
    value_2_changeble = value_2;
    memset(pow_2.bits, 0, sizeof(pow_2.bits));
    pow_2.bits[0] = 1;
    q = 0;
  }
  return error;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  resetDecimal(result);
  int error = 0;
  s21_decimal max_dec_div_by_ten = MAX_DECIMAL;
  setExp(&max_dec_div_by_ten, 1);
  s21_decimal temp_result = {0};
  s21_decimal remainder = {0};
  int exp_1 = getExp(value_1), exp_2 = getExp(value_2),
      exp = abs(exp_1 - exp_2);
  int sign = (getSign(value_1) + getSign(value_2) == 1) ? 1 : 0;

  setSign(&value_1, 0);
  setSign(&value_2, 0);

  setExp(&value_1, 0);
  setExp(&value_2, 0);

  if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
    error = 3;
  }

  while (error == 0) {
    resetDecimal(&temp_result);
    resetDecimal(&remainder);
    error = s21_div_with_remainder(value_1, value_2, &temp_result, &remainder);
    error = s21_add(temp_result, *result, result);
    error = mulByTen(&remainder);
    value_1 = remainder;
    if ((remainder.bits[0] == 0 && remainder.bits[1] == 0 &&
         remainder.bits[2] == 0) ||
        exp > 27) {
      if (exp > 27) {
        resetDecimal(&temp_result);
        resetDecimal(&remainder);
        error =
            s21_div_with_remainder(value_1, value_2, &temp_result, &remainder);

        if ((getBit128(*result, 0) && temp_result.bits[0] > 4) ||
            (!getBit128(*result, 0) && temp_result.bits[0] > 5)) {
          result->bits[0] += 1;
        }
      }
      break;
    }
    result->bits[3] = 0;
    temp_result.bits[3] = 0;
    error = mulByTen(&temp_result);
    if (s21_is_less_or_equal(*result, max_dec_div_by_ten)) {
      error = mulByTen(result);
      ++exp;
    } else {
      resetDecimal(&temp_result);
      resetDecimal(&remainder);
      error =
          s21_div_with_remainder(value_1, value_2, &temp_result, &remainder);

      if ((getBit128(*result, 0) && temp_result.bits[0] > 4) ||
          (!getBit128(*result, 0) && temp_result.bits[0] > 5)) {
        result->bits[0] += 1;
      }
      break;
    }
  }
  if (exp_1 - exp_2 < 0) {
    exp -= abs(exp_1 - exp_2);
    exp -= abs(exp_1 - exp_2);
  }
  while (exp < 0 && error != 3) {
    error = mulByTen(result);
    exp++;
  }

  if (error == 0) {
    setSign(result, sign);
    setExp(result, exp);
  } else if (error == 1 && sign) {
    error = TOO_LOW;
    resetDecimal(result);
  } else {
    resetDecimal(result);
  }

  return error;
}
