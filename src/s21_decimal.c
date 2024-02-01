

#include <stdio.h>
#include "s21_decimal.h"
#include <math.h>

#define first 0x00000001



int s21_get_sign(s21_decimal number) {
        int sign = number.bits[SCALE] & MINUS;
        return sign;
    }

void s21_set_sign(s21_decimal *number, int sign) {
    if(sign == 1){
        number->bits[SCALE] |= MINUS;
    }
    if(sign == 0){
        number->bits[SCALE] &= ~MINUS;
    }
}

void s21_set_bit(int *number, int bit_position, int bit) {
    int mask = 1; 
    mask <<= bit_position;

    if(bit == 0) {
        mask = ~mask;
        *number &= mask;
    }

    if(bit == 1) {
        *number |= mask;
    }
}



// PURE SHITCODE  LOL

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
    // s21_big_decimal value_1_b = s21_decimal_to_big(value1);
    // s21_big_decimal value_2_b = s21_decimal_to_big(value2);
    // s21_big_decimal value_3_b = s21_decimal_to_big(result);
    int flag = 0;
    for(int i =0;i<7;i++){
    for(int j = 0; j<64;i++){

        if((value_1_b >>j & first) == 0 && (value_2_b>>j & first) == 0 && flag = 0) 
        {
            s21_set_bit(value_3_b,j,0); 
        }
        else if ((value_1_b >>j & first) == 0 && (value_2_b>>j & first) == 0 && flag = 1) 
        { 
            s21_set_bit(value_3_b,j,0); flag = 0;
        }



        if( (value_1_b >>j & first) == 1 && (value_2_b>>j & first) == 0 && flag = 0) || ((value_1_b & first) == 0 && (value_1_b & first) == 1 && flag = 0) 
        {
            s21_set_bit(value_3_b,j,1);
        }

        else if ((value_1_b >>j & first) == 1 && (value_2_b>>j & first) == 0 && flag = 1) || ((value_1_b & first) == 0 && (value_1_b & first) == 1 && flag = 1)
        {
           s21_set_bit(value_3_b,j,0); 
        }



        if((value_1_b >>j & first) == 1 && (value_2_b>>j & first) == 1) 
        {
            s21_set_bit(value_3_b,j,0); flag = 1;
        }
    

    }
    }
}




// --------------------- get scale -----------------------
int get_scale(s21_decimal s21_decimal){
//  s21_decimal decimal1 = {{0x00190000, 0, 0, 0}};
 int scale = s21_decimal.bits[0] & SCALEBITE;
//  int new = scale >>16;
 scale >>= 16;
 return scale;
//  printf("%d",scale);
}
// --------------------- set scale for decimal-----------------------

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