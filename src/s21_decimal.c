

#include <stdio.h>
#include "s21_decimal.h"
#include <math.h>

#define first 0x00000001





int main(){

// --------------------- get scale -----------------------
//  s21_decimal decimal1 = {{0x00190000, 0, 0, 0}};
//  int scale = decimal1.bits[0] & SCALEBITE;
// //  int new = scale >>16;
//  scale >>= 16;
//  printf("%d",scale);

// --------------------- set scale -----------------------

// s21_decimal decimal1 =  {{0x00000000, 0x00000000, 0x00000000, 0x140000}};
// int scale = decimal1.bits[3] & SCALEBITE;
// printf("%d", scale >> 16); 
// int new_scale = 0x001C;
// decimal1.bits[3] &= MINUS;
// decimal1.bits[3] |= ((new_scale<<16) & SCALEBITE);
// scale = decimal1.bits[3] & SCALEBITE;
// printf("\n%d", scale >> 16); 
// // printf("%d", new_scale); 

// --------------------- convert to big decimal -----------------------

// s21_decimal decimal1 =  {{0x00000000, 0x00000000, 0x00000000, 0x140000}};
// s21_big_decimal decimal2 = {{0,0,0,0,0,0,0,0,0}};


// --------------------- decimal to int -----------------------
// s21_decimal decimal1 = {{0002, 0002, 0, 0x140000}};
// long long int sum = 0;
// long double m = 0.0;
// for(int i = 0; i<3;i++){
//     for(int j = 0;j<31;j++){
//         if(decimal1.bits[i]>>j & first == 1) sum += powl(2.0,m);          ///// NE RABOTAET SLOJNO :(
//         m++;
//     }

// // }

// }

// printf("%d",sum);

// }