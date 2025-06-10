#include "bistromathique.h"

int print_usage(char *caller) {
  printf("Usage: ./%s '[mathematical operation]'\n", caller);
  return -1;
}

void print_result(char *result) {
  while ((result[0] == '0' || result[0] == ' ') && result[0] != '\0') {
    result = result + 1;
  }
  puts(result);
}

int main(int argc, char** argv) {
  if (argc != 2) {
    return print_usage(argv[0]);
  }
  if (!bistromathique_check_operation(argv[1])) {
    fprintf(stderr, "./%s: Invalid operation: %s\n", argv[0], argv[1]);
  }

  bistromathique(argv[1]);

  print_result(argv[1]);
  return 0;
}
