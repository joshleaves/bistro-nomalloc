#include "bistromathique.h"

bool is_number(char c) {
  if (c == ' ')
    return true;
  return (c >= '0' && c <= '9');
}