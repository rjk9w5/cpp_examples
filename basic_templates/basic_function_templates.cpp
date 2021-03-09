
#include "io_util.h"

template <class Type>
Type foo() {
  LOG_CALL();
  return Type();
}

template <class Type>
void bar(Type) {
  LOG_CALL();
}

struct foobar {
  template <class Type>
  void member(Type) {
    LOG_CALL();
  }
};

void basic_function_templates() {
  // Cannot deduce type of template from signature
  foo<int>();
  foo<double>();

  // Can deduce type of template from signature
  bar(int());
  bar(double());

  // Can override deduced type of template from signature with specified type
  bar<double>(int());
  bar<int>(int());

  foobar fb;
  // Calling templated member function
  fb.member(int());
  fb.member(double());
}
