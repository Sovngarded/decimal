

#include <stdio.h>
#include "s21_decimal.h"








int main(){
 s21_decimal decimal1 = {{0x00FF0000, 0, 0, 0}};
 int scale = decimal1.bits[4] & SCALEBITE;
 printf("%d",scale);
}