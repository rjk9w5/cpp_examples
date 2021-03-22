#include <string>
#include <iostream>

/**
 * struct -> default visiblilty == public
 * class -> default visiblilty == private
 */

struct A {
  // BIG THREE
  // 1
  // Default Constructor
  A() :
    ptr(nullptr),
    i (counter++),
    s("hello") {
    printf("%s %d\n", __PRETTY_FUNCTION__, i);
  }

  A(int i_in) : ptr(nullptr), i(counter++) {
    printf("%s %d\n", __PRETTY_FUNCTION__, i);
  }

  // 2
  // Copy Construct
  explicit A(const A& a)
    : ptr(nullptr), i(counter++), s(a.s) {
    printf("%s %d\n", __PRETTY_FUNCTION__, i);
    if(a.ptr) {
      switch(i) {
        case 1000:
        default:
          ptr = new int;
          *(int*)ptr = *(int*)a.ptr;
      }
    }
  }

  // Copy-Assignment Operator
  A& operator=(const A& a) {
    // Don't self copy
    printf("%s\n", __PRETTY_FUNCTION__);
    if(this != &a) {
      ptr = nullptr;
      i = a.i;
      s = a.s;
      if(a.ptr) {
        switch(i) {
          case 1000:
          default:
            ptr = new int;
            *(int*)ptr = *(int*)a.ptr;
        }
      }
    }
    return *this;
  }

  // 3
  // Destructor Constructor
  ~A() {
    printf("%s %d\n", __PRETTY_FUNCTION__, i);
    delete ptr;
  }
  // A(A&& a); // Move Constructor
  // A& operator=(A&&) // Move-Assignment Operator
  // swap(A&,A&); // Swap operator

  void initPtr() {}
  void initI() {}
  void initS() {}

  void* ptr;
  int i;
  std::string s;

  static int counter;
};
int A::counter = 0;

void print(std::string name, A& a) {
  std::cout << name << ": " << std::endl;
  std::cout << "\t" << std::hex << a.ptr << std::endl;
  std::cout << "\t" << a.i << std::endl;
  std::cout << "\t" << a.s << std::endl;
}

int main() {
  A a_i(1);
  A a;
  a.ptr = new int;
  *(int*)a.ptr = 5;
  A a_copy(a);
  //a_copy.ptr = new int;
  *(int*)a_copy.ptr = 6;

  print("a", a);
  print("a_copy", a_copy);
}
