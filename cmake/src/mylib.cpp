#include <cstdio>
#include "mylib_private.h"

void foo() {
  printf("Hello foo\n");
  bar<int>();
}
