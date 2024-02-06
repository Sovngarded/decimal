#include "s21_decimal.h"

int get_scale(s21_decimal s21_decimal){
//  s21_decimal decimal1 = {{0x00190000, 0, 0, 0}};
 int scale = s21_decimal.bits[0] & SCALEBITE;
//  int new = scale >>16;
 scale >>= 16;
 return scale;
//  printf("%d",scale);
}