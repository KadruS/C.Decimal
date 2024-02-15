#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIT 0b11111111111111111111111111111111
#define MINUS 0b10000000000000000000000000000000
#define MAX_DECIMAL                  \
  {                                  \
    { MAX_BIT, MAX_BIT, MAX_BIT, 0 } \
  }
#define MIN_DECIMAL                      \
  {                                      \
    { MAX_BIT, MAX_BIT, MAX_BIT, MINUS } \
  }

enum arithmetic_errors { OK, TOO_MUCH, TOO_LOW, DIV_ZERO };
enum comparision { FALSE, TRUE };

typedef struct {
  unsigned bits[4];
} s21_decimal;

int getBit128(s21_decimal decimal, int bit_index);
int getBit32(unsigned number, int bit_index);
int setBit128(s21_decimal *decimal, int bit_index, int bit);
int setBit32(unsigned *number, int bit_index, int bit);

int getSign(s21_decimal decimal);
int setSign(s21_decimal *decimal, int bit);

int getExp(s21_decimal decimal);
int setExp(s21_decimal *decimal, int exp);

void printBits(s21_decimal decimal);
int shiftLeft(s21_decimal *decimal);
void resetDecimal(s21_decimal *decimal);
void normalizeDecimal(s21_decimal *value_1, s21_decimal *value_2);
int mulByTen(s21_decimal *decimal);

int s21_is_greater(s21_decimal val_1, s21_decimal val_2);
int s21_is_less(s21_decimal val_1, s21_decimal val_2);
int s21_is_equal(s21_decimal val_1, s21_decimal val_2);
int s21_is_not_equal(s21_decimal val_1, s21_decimal val_2);
int s21_is_greater_or_equal(s21_decimal val_1, s21_decimal val_2);
int s21_is_less_or_equal(s21_decimal val_1, s21_decimal val_2);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div_with_remainder(s21_decimal value_1, s21_decimal value_2,
                           s21_decimal *result, s21_decimal *remainder);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_negate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
