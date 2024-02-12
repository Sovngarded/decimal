#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>
#include "./s21_decimal.h"
//#include ""

#define TEST_COMPARISON_FALSE 0
#define TEST_COMPARISON_TRUE 1

Suite *is_less_suite1(void);
Suite *is_less_suite2(void);
Suite *is_less_suite3(void);
Suite *is_less_suite4(void);
Suite *is_less_suite5(void);
Suite *is_less_suite6(void);
Suite *is_less_suite7(void);
Suite *is_less_suite8(void);
Suite *is_less_suite9(void);
Suite *is_less_suite10(void);
Suite *is_less_suite11(void);
Suite *is_less_suite12(void);
Suite *is_less_suite13(void);
Suite *is_less_suite14(void);
Suite *is_less_suite15(void);
Suite *is_less_suite16(void);

Suite *is_equal_suite1(void);
Suite *is_equal_suite2(void);
Suite *is_equal_suite3(void);
Suite *is_equal_suite4(void);
Suite *is_equal_suite5(void);
Suite *is_equal_suite6(void);
Suite *is_equal_suite7(void);
Suite *is_equal_suite8(void);
Suite *is_equal_suite9(void);
Suite *is_equal_suite10(void);
Suite *is_equal_suite11(void);
Suite *is_equal_suite12(void);
Suite *is_equal_suite13(void);
Suite *is_equal_suite14(void);
Suite *is_equal_suite15(void);
Suite *is_equal_suite16(void);

Suite *is_less_or_equal_suite1(void);
Suite *is_less_or_equal_suite2(void);
Suite *is_less_or_equal_suite3(void);
Suite *is_less_or_equal_suite4(void);
Suite *is_less_or_equal_suite5(void);
Suite *is_less_or_equal_suite6(void);
Suite *is_less_or_equal_suite7(void);
Suite *is_less_or_equal_suite8(void);
Suite *is_less_or_equal_suite9(void);
Suite *is_less_or_equal_suite10(void);
Suite *is_less_or_equal_suite11(void);
Suite *is_less_or_equal_suite12(void);
Suite *is_less_or_equal_suite13(void);
Suite *is_less_or_equal_suite14(void);
Suite *is_less_or_equal_suite15(void);
Suite *is_less_or_equal_suite16(void);

Suite *is_greater_suite1(void);
Suite *is_greater_suite2(void);
Suite *is_greater_suite3(void);
Suite *is_greater_suite4(void);
Suite *is_greater_suite5(void);
Suite *is_greater_suite6(void);
Suite *is_greater_suite7(void);
Suite *is_greater_suite8(void);
Suite *is_greater_suite9(void);
Suite *is_greater_suite10(void);
Suite *is_greater_suite11(void);
Suite *is_greater_suite12(void);
Suite *is_greater_suite13(void);
Suite *is_greater_suite14(void);
Suite *is_greater_suite15(void);
Suite *is_greater_suite16(void);

Suite *is_greater_or_equal_suite1(void);
Suite *is_greater_or_equal_suite2(void);
Suite *is_greater_or_equal_suite3(void);
Suite *is_greater_or_equal_suite4(void);
Suite *is_greater_or_equal_suite5(void);
Suite *is_greater_or_equal_suite6(void);
Suite *is_greater_or_equal_suite7(void);
Suite *is_greater_or_equal_suite8(void);
Suite *is_greater_or_equal_suite9(void);
Suite *is_greater_or_equal_suite10(void);
Suite *is_greater_or_equal_suite11(void);
Suite *is_greater_or_equal_suite12(void);
Suite *is_greater_or_equal_suite13(void);
Suite *is_greater_or_equal_suite14(void);
Suite *is_greater_or_equal_suite15(void);
Suite *is_greater_or_equal_suite16(void);

Suite *is_not_equal_suite1(void);
Suite *is_not_equal_suite2(void);
Suite *is_not_equal_suite3(void);
Suite *is_not_equal_suite4(void);
Suite *is_not_equal_suite5(void);
Suite *is_not_equal_suite6(void);
Suite *is_not_equal_suite7(void);
Suite *is_not_equal_suite8(void);
Suite *is_not_equal_suite9(void);
Suite *is_not_equal_suite10(void);
Suite *is_not_equal_suite11(void);
Suite *is_not_equal_suite12(void);
Suite *is_not_equal_suite13(void);
Suite *is_not_equal_suite14(void);
Suite *is_not_equal_suite15(void);
Suite *is_not_equal_suite16(void);

void test_is_less(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_is_equal(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_is_less_or_equal(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_is_greater(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_is_greater_or_equal(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_is_not_equal(s21_decimal decimal1, s21_decimal decimal2, int check);

#endif  // SRC_TESTS_TEST_H_