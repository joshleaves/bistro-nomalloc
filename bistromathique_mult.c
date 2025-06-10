#include "bistromathique.h"
#include "double_char.h"

void bistromathique_process_mult(char *operation, size_t len, size_t sign_idx) {
  // size_t car_idx = sign_idx;
  size_t car_idx = lookup_number_idx(operation, len, sign_idx);
  size_t car_end = sign_idx - 1;
  while (operation[car_end] == ' ')
    car_end--;
  size_t cdr_idx = sign_idx + 1;
  // size_t cdr_end = sign_idx;
  size_t cdr_end = lookup_number_end(operation, len, sign_idx);
  // while (car_idx > 0 && is_number(operation[car_idx - 1]))
  //   car_idx--;
  // while (cdr_end < len && is_number(operation[cdr_end + 1]))
  //   cdr_end++;
  printf("-> Indexes CAR: %c->%c\n", operation[car_idx], operation[car_end]);
  printf("-> Indexes CDR: %c->%c\n", operation[cdr_idx], operation[cdr_end]);
  split_string(operation, car_idx, cdr_end);
  printf("-> Indexes CAR: %d->%d\n", get_operand(operation, car_idx), get_operand(operation, car_end));
  printf("-> Indexes CDR: %d->%d\n", get_operand(operation, cdr_idx), get_operand(operation, cdr_end));
  printf("Result: _");
  for (size_t i = car_idx; i <= cdr_end; i++) {
    printf("%d", get_result(operation, i));
  }
  printf("_\n");
  for (size_t mult_idx = cdr_end + 1; mult_idx-- > cdr_idx;) {
    size_t offset = cdr_end - mult_idx;
    
    char op_mult = get_operand(operation, mult_idx);
    for (size_t other_idx = car_end + 1; other_idx-- > car_idx;) {
      char op_other = get_operand(operation, other_idx);

      size_t write_pos = cdr_end - offset++;

      int carry = op_mult * op_other;
      printf("-> Calc: %d * %d => %d\n", op_mult, op_other, carry);

      while (carry > 0) {
        carry = increment_result(operation, write_pos--, carry);
      }
      printf("Result: _");
      for (size_t i = car_idx; i <= cdr_end; i++) {
        printf("%d", get_result(operation, i));
      }
      printf("_\n");
    }
  }
  reunite_string(operation, car_idx, cdr_end);
}