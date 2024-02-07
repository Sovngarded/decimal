

#include <stdio.h>
#include "s21_decimal.h"
#include <math.h>
#include <stdlib.h>
#define first 0x00000001
#define FALSE 0
#define TRUE 1


int s21_get_sign(s21_decimal number) {
        int sign = number.bits[SCALE] & MINUS;
        return sign;
    }

// void s21_set_sign(s21_decimal *number, int sign) {
//     if(sign == 1){
//         number->bits[SCALE] |= MINUS;
//     }
//     if(sign == 0){
//         number->bits[SCALE] &= ~MINUS;
//     }
// }

// void s21_set_bit(int *number, int bit_position, int bit) {
//     int mask = 1; 
//     mask <<= bit_position;

//     if(bit == 0) {
//         mask = ~mask;
//         *number &= mask;
//     }

//     if(bit == 1) {
//         *number |= mask;
//     }
// }

int get_scale(s21_decimal s21_decimal){
//  s21_decimal decimal1 = {{0x00190000, 0, 0, 0}};
 int scale = s21_decimal.bits[SCALE] & SCALEBITE;
//  int new = scale >>16;
 scale >>= 16;
 printf("get scale = %d",scale);
 return scale;
//  printf("%d",scale);
}

int is_zero(s21_decimal number) {
    int result = FALSE;
    if(number.bits[LOW] == 0 && number.bits[MID] == 0 && number.bits[HIGH] == 0) {
        result = TRUE;
    }
    return result;
}

int is_overflow(s21_big_decimal big_number) {
    int result = FALSE;
    int overflow = 0;
    for(int i = 0; i < 7; i++) {
        big_number.bits[i] += overflow;
        overflow = big_number.bits[i] >> 32;
        big_number.bits[i] &= MAX4BITE;
    }
    if(overflow != 0) {
        result = TRUE;
    }
    return result;
}

int is_overflow_pointer(s21_big_decimal* big_number) {
    int result = FALSE;
    int overflow = 0;
    for(int i = 0; i < 7; i++) {
        big_number->bits[i] += overflow;
        overflow = big_number->bits[i] >> 32;
        big_number->bits[i] &= MAX4BITE;
    }
    if(overflow != 0) {
        result = TRUE;
    }
    return result;
}

s21_big_decimal left_shift(s21_big_decimal big_number) {
     s21_big_decimal copy_num = big_number;
    for(int i = 0; i < 7; i++) {
        copy_num.bits[i] *= 10;
    }
    printf("\nbits = %LU\n", copy_num.bits[0]);

    if(is_overflow(copy_num) != TRUE) {
        big_number.scale++;
        big_number = copy_num;
        printf("\nbits bin num = %LU\n", big_number.bits[0]);

        return big_number; // ???

    }
    printf("OVERFLOW");
    return big_number; // ???
}

int right_shift(s21_big_decimal* big_number) {
    long int remainder = 0;
    for(int i = 6; i < 0; i--) {
        big_number->bits[i] += (remainder << 32);
        remainder = big_number->bits[1] % 10;
        big_number->bits[i] /= 10;
    }
    big_number->scale--;
    return remainder;
}


s21_big_decimal right_shift_normal(s21_big_decimal big_number) {
    long int remainder = 0;
    for(int i = 6; i < 0; i--) {
        big_number.bits[i] += (remainder << 32);
        remainder = big_number.bits[1] % 10;
        big_number.bits[i] /= 10;
    }
    big_number.scale--;
    return big_number;
}


int normalize_scale(s21_decimal value_1,s21_decimal value_2){
    int result = 0;
    int scale_1 = get_scale(value_1); int scale_2 = get_scale(value_2);
    
    if(scale_1 > 28 || scale_2 > 28) result = 28;
    else if(scale_1 > scale_2 && scale_1 <= 28) result = scale_1;
    // if(scale_1 > scale_2 && scale_1 > 28) result = 28;
    else if(scale_1 < scale_2 && scale_2 <= 28) result = scale_2;
    // if(scale_1 < scale_2 && scale_2 > 28) result = 28;
    printf("normalize scale = %d\n", result);
    return result;
}

s21_big_decimal convert_to_big_decimal(s21_decimal value){
    s21_big_decimal result;
    for(int i = 0; i < 4;i++){
    result.bits[i] = value.bits[i] & MAX4BITE;
    }
    return result;
}

s21_decimal convert_to_decimal(s21_big_decimal value) {
    s21_decimal result;
    for (int i = 0; i < 4; i++) {
        result.bits[i] = value.bits[i] & MAX4BITE;
    }
    return result;
}

// int right_shift(s21_big_decimal* big_number) {
//     int remainder = 0;
//     for(int i = 6; i < 0; i--) {
//         big_number->bits[i] += remainder << 32;
//         remainder = big_number->bits[1] % 10;
//         big_number->bits[i] /= 10;
//     }
//     big_number->scale--;
//     return remainder;
// }

void left_shift_pointer(s21_big_decimal* big_number) {
     s21_big_decimal copy_num = *big_number;
    for(int i = 0; i < 7; i++) {
        copy_num.bits[i] *= 10;
    }

    if(is_overflow(*big_number) != TRUE) {
        big_number->scale++;
        *big_number = copy_num;
    }
}

s21_big_decimal set_scale_and_number(s21_big_decimal value_1, int scale, int scale_n){
    s21_big_decimal result = value_1;

    printf("\n\nset_scale_and_number\nscale = %d and new = %d", scale, scale_n);
    if(scale < scale_n){
        for(int i = scale; i <= scale_n; i++){
            printf("left = %d", i);
            result = left_shift(result);
        }
    } else if(scale > scale_n) {
        for(int i = scale;i >= scale_n;i--){
            printf("right");
           result = right_shift_normal(result); 
        }
    }

    return result;
}
enum ArithmeticErrorsCode {
    OK,
    INF,  // number is too large or equal to infinity
    NEG_INF,  // the number is too small or equal to negative infinity
    DIV_BY_ZERO
};

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){

    s21_big_decimal value_big_1 = convert_to_big_decimal(value_1);
    s21_big_decimal value_big_2 = convert_to_big_decimal(value_2);
    s21_big_decimal result_big = convert_to_big_decimal(*result);

    if (is_zero(value_1) == TRUE) {
        printf("zerro");
        *result = value_2;
        printf("result = %d %d %d %d =", result->bits[0], result->bits[1], result->bits[2], result->bits[3]);

        return OK;
    } else if (is_zero(value_2) == TRUE) {
        printf("zerro");
        *result = value_1;
        return OK;
    }

    printf("start val1 = %d %d %d %d =\n", value_big_1.bits[0], value_big_1.bits[1], value_big_1.bits[2], value_big_1.bits[3]);
    printf("start val2 = %d %d %d %d =\n", value_big_2.bits[0], value_big_2.bits[1], value_big_2.bits[2], value_big_2.bits[3]);

    int s = normalize_scale(value_1, value_2);
    value_big_1 = set_scale_and_number(value_big_1, get_scale(value_1), s);
    value_big_2 = set_scale_and_number(value_big_2, get_scale(value_2), s);

    printf("\nval1 = %u %u %u %u =\n", value_big_1.bits[0], value_big_1.bits[1], value_big_1.bits[2], value_big_1.scale);
    printf("val2 = %u %u %u %u =\n", value_big_2.bits[0], value_big_2.bits[1], value_big_2.bits[2], value_big_2.scale);


    if(s21_get_sign(value_1) == s21_get_sign(value_2)){
        for(int i=0; i < 3; i++) {
            result_big.bits[i] = value_big_1.bits[i] + value_big_2.bits[i];
        }
        //return OK;
    } else {
        if(s21_is_less(value_1, value_2) == TRUE) {
            for(int i=0; i < 3; i++) {
                result_big.bits[i] = value_big_2.bits[i] - value_big_1.bits[i];
            }
        } else {
            for(int i=0; i < 3; i++) {
                result_big.bits[i] = value_big_1.bits[i] - value_big_2.bits[i];
            }
        }
        //return OK;
    }

    int sc = s <<= 16;
    printf("s<<=16 = %d", sc);
    result_big.scale = sc;
    printf("result_big.scale = %d", result_big.scale);

    result_big.bits[3] = result_big.scale;
    printf("result_big.bits[3] = %d", result_big.bits[3]);


    is_overflow_pointer(&result_big);
    
    printf("result big = %LU %LU %LU %LU  =\n", result_big.bits[0], result_big.bits[1], result_big.bits[2], result_big.bits[3]);
    
    *result = convert_to_decimal(result_big);

    printf("result = %LU %LU %LU %LU  =", result->bits[0], result->bits[1], result->bits[2], result->bits[3]);
    ///*result = re

    return OK;                                                                                                                   
}

// s21_big_decimal set_scale_and_number(s21_big_decimal value_1, int scale, int scale_n){
//     s21_big_decimal result = value_1;
//     if(scale < scale_n){
//         for(int i = scale;i<=scale_n;i++){
//             left_shift(result);
//         }
//     }else{
//         for(int i = scale;i>=scale_n;i--){
//            right_shift_normal(result); 
//         }

//     }
//     return result;
// }


// < nado fix sdelat chto kogda ravno ono toje 0 vozvrashaet
int s21_is_less(s21_decimal value_1, s21_decimal value_2){  
    int result = 1;

    s21_big_decimal value_1_b = convert_to_big_decimal(value_1);
    s21_big_decimal value_2_b = convert_to_big_decimal(value_2);
    int scale_1 = get_scale(value_1);
    int scale_2 = get_scale(value_2);

    int needed_scale = normalize_scale(value_1,value_2);
    value_1_b = set_scale_and_number(value_1_b, scale_1, needed_scale);
    value_2_b = set_scale_and_number(value_2_b, scale_2, needed_scale);


    for(int i = 3;i >= 0; i--){
        if(value_1_b.bits[i] > value_2_b.bits[i]){
            result = 0;
            break;
        }
    }
    
return result;

}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2){
    int result = 1;
    
    s21_big_decimal value_1_b = convert_to_big_decimal(value_1);
    s21_big_decimal value_2_b = convert_to_big_decimal(value_2);
    int scale_1 = get_scale(value_1);
    int scale_2 = get_scale(value_2);
    int needed_scale = normalize_scale(value_1,value_2);
    value_1_b = set_scale_and_number(value_1_b, scale_1, needed_scale);
    value_2_b = set_scale_and_number(value_2_b, scale_2, needed_scale);

    for(int i = 0; i<3;i++){
        if(value_1_b.bits[i] != value_2_b.bits[i]){
            result = 0;
            break;
        }
    }
    return result;
}





// --------------------- get scale -----------------------

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

int main() {
// --------------------- convert to big decimal -----------------------
// -0.5
    s21_decimal decimal1 = {{0x5, 0x0, 0x0, 0x80010000}};
    // 26409387
    s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
    // 26409386.5
    s21_decimal check = {{0xFBDC0A9, 0x0, 0x0, 0x10000}};

s21_decimal* result = malloc(sizeof(s21_decimal)); 

s21_add(decimal1, decimal2, result); 
printf("\ncheck = %d %d %d %d =", check.bits[0], check.bits[1], check.bits[2], check.bits[3]);

///printf("%d", s21_is_less(decimal1,decimal2));

// s21_big_decimal decimal2 = {{0,0,0,0,0,0,0}, 0}


// decimal2.scale = get_scale(decimal1);


// s21_add(decimal1,decimal2,result);

// printf("%d\n%d",check.bits[0],result->bits[0]);


// for(int i = 0;i<3;i++){
//     if(decimal1.bits[i] >= decimal2.bits[i]){
//         printf("true \n");
//     }else{
//         printf("false");
//     }
// }


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