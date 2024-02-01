CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
FILES = 
FILE_TESTS = 
TARGET=s21_decimal.a

OS := $(shell uname -s)
TEST_FLAGS = -lcheck
ifeq ($(OS), Linux)
TEST_FLAGS =  -lcheck -lm -lsubunit
endif

all: gcov_report

$(TARGET): 
	$(CC) ${CFLAGS} -c ${FILES}
	ar rc libs21_string.a s21*.o
	ranlib libs21_string.a
	cp libs21_string.a s21_decimal.a

test: $(TARGET)
	$(CC) test.c ${CFLAGS} ${FILES} ${FILE_TESTS} s21_decimal.h ${TEST_FLAGS} -o s21_decimal --coverage
	@echo "---------------------------TESTS--------------------------------------" 
	./s21_decimal
	@echo "----------------------------------------------------------------------"

gcov_report: test 
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	open ./report/src/index.html

clean:
	rm -rf s21_decimal
	rm -rf *.out
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gch
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.info
	rm -rf *.html
	rm -rf *.css
	rm -rf test
	rm -rf gcov_test
	rm -rf test report