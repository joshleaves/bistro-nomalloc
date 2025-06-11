#ifndef INCLUDE_BISTROMATHIQUE_H
#define INCLUDE_BISTROMATHIQUE_H

#include <stdbool.h> // for bool
#include <stdio.h>   // for printf, fprintf & stderr
#include <stddef.h>  // for size_t
#include <stdint.h>  // for SIZE_MAX
#include <string.h>  // for strlen

#if DEBUG_MULT
  #define DBG_MULT(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DBG_MULT(...) ((void)0)
#endif

#if DEBUG_ADD
  #define DBG_ADD(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DBG_ADD(...) ((void)0)
#endif

#if DEBUG_PROCESS
  #define DBG_PROCESS(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DBG_PROCESS(...) ((void)0)
#endif

#define DBG_PRINT_RESULT(OP_TYPE, op, from, to) \
  do { \
    DBG_##OP_TYPE("Result: _"); \
    for (size_t _i = (from); _i <= (to); _i++) \
      DBG_##OP_TYPE("%d", get_result((op), _i)); \
    DBG_##OP_TYPE("_\n"); \
  } while (0) 

int main(int argc, char**argv);
int print_usage(char *caller);
void print_result(char *result);

bool bistromathique_check_operation(const char *operation);
void bistromathique_process_operation(char *operation, size_t len, int depth);
void bistromathique(char *operation);

// utils.c
bool is_number(char c);

// lookups.c
size_t lookup_number_idx(const char *operation, size_t len, size_t car_idx);
size_t lookup_number_end(const char *operation, size_t len, size_t cdr_end);

size_t lookup_parenthesis_open(const char *operation, size_t len);
size_t lookup_parenthesis_close(const char *operation, size_t len);
size_t lookup_mult_sign(const char *operation, size_t len);
size_t lookup_plus_or_minus_sign(const char *operation, size_t len);

// bistromathique_add.c
void bistromathique_process_add(char *operation, size_t len, size_t sign_idx);

// bistromathique_mult.c
void bistromathique_process_mult(char *operation, size_t len, size_t sign_idx);


#endif
