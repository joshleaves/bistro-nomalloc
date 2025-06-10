#ifndef INCLUDE_DOUBLE_CHAR_H
#define INCLUDE_DOUBLE_CHAR_H

#include <stdbool.h> // for bool
#include <stdio.h>   // for printf, fprintf & stderr
#include <stddef.h>  // for size_t

void split_string(char *operation, size_t from, size_t until);
void reunite_string(char *operation, size_t from, size_t until);

char get_operand(char *operation, size_t idx);
char get_result(char *operation, size_t idx);
void set_operand(char *operation, size_t idx, char operand);
void set_result(char *operation, size_t idx, char result);
char increment_result(char *operation, size_t idx, char increment);

#endif 