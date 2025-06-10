#include "double_char.h"

void split_string(char *operation, size_t from, size_t until) {
  for (size_t i = from; i <= until; i++) {
    printf("-> Modify _%c_ =>", operation[i]);
    if (operation[i] >= '0' && operation[i] <= '9') {
      operation[i] = operation[i] - '0';
    } else {
      operation[i] = 0;
    }
    printf(" _%d_\n", get_operand(operation, i));
  }
}

void reunite_string(char *operation, size_t from, size_t until) {
  for (size_t i = from; i <= until; i++) {
    operation[i] = get_result(operation, i) + '0';
  }
}

char get_operand(char *operation, size_t idx) {
  return operation[idx] % 10;
}

char get_result(char *operation, size_t idx) {
  return operation[idx] / 10;
}

void set_operand(char *operation, size_t idx, char operand) {
  char result = operation[idx] / 10;
  operation[idx] = result * 10 + operand;
}

void set_result(char *operation, size_t idx, char result) {
  char operand = operation[idx] % 10;
  operation[idx] = result * 10 + operand;
}

char increment_result(char *operation, size_t idx, char increment) {
  char result = operation[idx] / 10;
  char sum = result + increment;
  set_result(operation, idx, sum % 10);
  return sum / 10; // carry
}