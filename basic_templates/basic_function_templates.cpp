
#include "io_util.h"

// Template of return type
template <class Type>
Type foo(int line) {
  LOG_CALL(line);
  return Type();
}

// Template of the parameter type
template <class Type>
void bar(int line,Type) {
  LOG_CALL(line);
}

struct foobar {
// Template of member function
  template <class Type>
  void member(int line, Type) {
    LOG_CALL(line);
  }
};

// Template of return and parameter type
template <class RType, class PType>
RType foobar_f(int line, PType) {
  LOG_CALL(line);
  return RType();
}

template <class RType, class PType>
RType foobar_f(int line, PType, RType) {
  LOG_CALL(line);
  return RType();
}

template <class PType, class RType>
RType foobar_f_rev(int line, PType) {
  LOG_CALL(line);
  return RType();
}

void basic_function_templates() {
  // Cannot deduce type of template from signature
  foo<int>(__LINE__);
  foo<double>(__LINE__);

  // Can deduce type of template from signature
  bar(__LINE__, int());
  bar(__LINE__, double());

  // Can override deduced type of template from signature with specified type
  bar<double>(__LINE__, int());
  bar<int>(__LINE__, int());

  foobar fb;
  // Calling templated member function
  fb.member(__LINE__, int());
  fb.member(__LINE__, double());

  //int x = foobar_f(double()); // compiler error, can't deduce RType
  foobar_f<int>(__LINE__, double()); // compiler error
  foobar_f<int,double>(__LINE__, double()); // compiler error
  foobar_f(__LINE__, double(),int()); // compiler error
  //foobar_f_rev(double()); // compiler error, can't deduce RType
  foobar_f_rev<double,int>(__LINE__, double()); // compiler error
}
