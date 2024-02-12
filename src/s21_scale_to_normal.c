#include "s21_decimal.h"
void point_to_normal(s21_big_decimal *dec1_work, s21_big_decimal *dec2_work) {
  if (dec1_work->scale < dec2_work->scale) {
    while (dec1_work->scale != dec2_work->scale && !left_shift(dec1_work))
      ;
  } else if (dec2_work->scale < dec1_work->scale) {
    while (dec1_work->scale != dec2_work->scale && !left_shift(dec2_work))
      ;
  }
}