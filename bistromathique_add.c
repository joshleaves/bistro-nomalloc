#include "bistromathique.h"
#include "double_char.h"

void bistromathique_process_add(char *operation, size_t len, size_t sign_idx) {
  size_t car_idx = lookup_number_idx(operation, len, sign_idx);
  size_t car_end = sign_idx - 1;
  while (operation[car_end] == ' ')
    car_end--;
  size_t cdr_idx = sign_idx + 1;
  size_t cdr_end = lookup_number_end(operation, len, sign_idx);
  // while (car_idx > 0 && is_number(operation[car_idx - 1]))
  //   car_idx--;
  // while (cdr_end < len && is_number(operation[cdr_end + 1]))
  //   cdr_end++;
  DBG_ADD("-> Indexes CAR: %c->%c\n", operation[car_idx], operation[car_end]);
  DBG_ADD("-> Indexes CDR: %c->%c\n", operation[cdr_idx], operation[cdr_end]);
  split_string(operation, car_idx, cdr_end);
  DBG_ADD("-> Indexes CAR: %d->%d\n", get_operand(operation, car_idx), get_operand(operation, car_end));
  DBG_ADD("-> Indexes CDR: %d->%d\n", get_operand(operation, cdr_idx), get_operand(operation, cdr_end));
  DBG_PRINT_RESULT(ADD, operation, car_idx, cdr_end);

  size_t car_len = car_end - car_idx;
  size_t cdr_len = cdr_end - cdr_idx;
  size_t maxlen = car_len;
  if (cdr_len > maxlen)
    maxlen = cdr_len;
  int carry = 0;
  bool car_consumed = false;
  bool cdr_consumed = false;
  for (size_t i = 0; i <= maxlen; i++) {
    int car_value = car_consumed ? 0 : get_operand(operation, car_end - i);
    int cdr_value = cdr_consumed ? 0 : get_operand(operation, cdr_end - i);
    int value = car_value + cdr_value + carry;
    DBG_ADD("-> Operation: %d + %d = %d\n", car_value, cdr_value, value);
    set_operand(operation, car_end - i, 0);
    carry = increment_result(operation, cdr_end - i, value);
    if (!car_consumed && (car_idx == car_end - i))
      car_consumed = true;
    if (!cdr_consumed && (cdr_idx == cdr_end - i))
      cdr_consumed = true;
    // operation[car_end - i] = '0';
    // operation[cdr_end - i] = '0' + value % 10;
    DBG_PRINT_RESULT(ADD, operation, car_idx, cdr_end);
  }
  reunite_string(operation, car_idx, cdr_end);
}