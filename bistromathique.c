#include "bistromathique.h"

bool bistromathique_check_operation(const char *operation) {
  int parens_cnt = 0;
  for (int i = 0; operation[i] != '\0'; i++) {
    if (operation[i] == '(') {
      parens_cnt += 1;
    } else if (operation[i] == ')') {
      parens_cnt -= 1;
    }
  }
  if (parens_cnt != 0) {
    return false;
  }

  return true; // ;)
}

void bistromathique(char *operation) {
  size_t len = strlen(operation);
  bistromathique_process_operation(operation, len, 1);
}

void bistromathique_process_operation_for_parentheses(char *operation, size_t len, int depth) {
  (void)depth;
  size_t open_paren = lookup_parenthesis_open(operation, len);
  while (open_paren != SIZE_MAX) {
    size_t close_paren = lookup_parenthesis_close(&operation[open_paren], len - open_paren);
    if (close_paren == SIZE_MAX)
      return; // Should not happen :)
    bistromathique_process_operation(&operation[open_paren + 1], close_paren - 1, depth + 1);
    operation[open_paren] = ' ';
    operation[open_paren + close_paren] = ' ';
    open_paren = lookup_parenthesis_open(operation, len);
  }
}

void bistromathique_process_operation_for_mults(char *operation, size_t len, int depth) {
  (void)depth;
  size_t mult_sign = lookup_mult_sign(operation, len);
  while (mult_sign != SIZE_MAX) {
    bistromathique_process_mult(operation, len, mult_sign);
    mult_sign = lookup_mult_sign(operation, len);
  }
}



void bistromathique_process_operation_for_adds(char *operation, size_t len, int depth) {
  (void)depth;
  size_t plusminus_sign = lookup_plus_or_minus_sign(operation, len);
  while (plusminus_sign != SIZE_MAX) {
    printf("-> Result A: _%s_\n", operation);
    if (operation[plusminus_sign] == '+') {
      bistromathique_process_add(operation, len, plusminus_sign);
    } else {
      // TODO: Support subs
    }
    printf("-> Result B: _%s_\n", operation);
    
    
    plusminus_sign = lookup_plus_or_minus_sign(operation, len);
  }
}

void bistromathique_process_operation(char *operation, size_t len, int depth) {
  printf("%*s Process: _%.*s_\n", depth * 2, "->", (int) len, operation);

  bistromathique_process_operation_for_parentheses(operation, len, depth);
  bistromathique_process_operation_for_mults(operation, len, depth);
  bistromathique_process_operation_for_adds(operation, len, depth);
}
