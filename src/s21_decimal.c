

#include <stdio.h>
#include "s21_decimal.h"
#include <math.h>

#define first 0x00000001




// --------------------- get scale -----------------------
int get_scale(s21_decimal s21_decimal){
//  s21_decimal decimal1 = {{0x00190000, 0, 0, 0}};
 int scale = s21_decimal.bits[0] & SCALEBITE;
//  int new = scale >>16;
 scale >>= 16;
 return scale;
//  printf("%d",scale);
}
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
int main(){
// --------------------- convert to big decimal -----------------------

s21_decimal decimal1 =  {{0x140000, 0x140000, 0x00000000, 0x140000}};
s21_big_decimal decimal2 = {{0,0,0,0,0,0,0}, 0};
for(int i = 0;i<3;i++){
    decimal2.bits[i] = decimal1.bits[i] & MAX4BITE;
}

decimal2.scale = get_scale(decimal1);



// for(int i =0 ; i<7;i++){
// for(int j = 0; j<64;j++){
//     if (decimal2.bits[i] & first) printf("1"); else printf("0"); if (j%8 == 0) printf("\n"); ///// check for correct work , but dunno if it's true
//     decimal2.bits[i] >>=1;
// }
// }



}
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