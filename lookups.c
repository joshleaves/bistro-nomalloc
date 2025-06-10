#include "bistromathique.h"

size_t lookup_number_idx(const char *operation, size_t len, size_t car_idx) {
  (void)len;
  while (car_idx > 0 && operation[car_idx - 1] == ' ')
    car_idx--;
  while (car_idx > 0 && operation[car_idx - 1] >= '0' && operation[car_idx - 1] <= '9')
    car_idx--;
  return car_idx;
}

size_t lookup_number_end(const char *operation, size_t len, size_t cdr_end) {
  while (cdr_end < len && operation[cdr_end + 1] == ' ')
    cdr_end++;
  while (cdr_end < len && operation[cdr_end + 1] >= '0' && operation[cdr_end + 1] <= '9')
    cdr_end++;
  return cdr_end;
}

size_t lookup_parenthesis_open(const char *operation, size_t len) {
  for (size_t i = 0; operation[i] != '\0' && i < len; i++) {
    if (operation[i] == '(') {
      return i;
    }
  }
  return SIZE_MAX;
}

size_t lookup_parenthesis_close(const char *operation, size_t len) {
  int parentheses = 0;
  for (size_t i = 0; operation[i] != '\0' && i < len; i++) {
    if (operation[i] == '(') {
      parentheses += 1;
    } else if (operation[i] == ')') {
      parentheses -= 1;
    }
    if (parentheses == 0) {
      return i;
    } 
  }
  return SIZE_MAX;
}

size_t lookup_mult_sign(const char *operation, size_t len) {
  for (size_t i = 0; operation[i] != '\0' && i < len; i++) {
    if (operation[i] == '*' || operation[i] == '/' || operation[i] == '%') {
      return i;
    }
  }
  return SIZE_MAX;
}

size_t lookup_plus_or_minus_sign(const char *operation, size_t len) {
  for (size_t i = 0; operation[i] != '\0' && i < len; i++) {
    if (operation[i] == '+' || operation[i] == '-') {
      return i;
    }
  }
  return SIZE_MAX;
}