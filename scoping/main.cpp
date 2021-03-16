#include <cstdio>

static int i_global = 0;
namespace raju {
static int i_global = 1;
namespace bar {
static int i_global;
  struct bar {};
namespace foo {
//static int i_global = 3;
using ::raju::bar::i_global;
  void bar() {
    printf("%s\n", __PRETTY_FUNCTION__);
    printf("%d, %d, %d, %d\n", ::i_global,
        ::raju::i_global,
        ::raju::bar::i_global,
        i_global);
  }
  void foo() {
    printf("%s\n", __PRETTY_FUNCTION__);
  }
}
}
}

struct Foo {
  void foo() {
    i_global++;
  }
  int i_global;
};

namespace FooS {
  void foo() {
    i_global++;
  }
  int i_global;
}

namespace vtkm {
#if defined(VTK_USE_STD_SHARED_PTR)
  template <class T, class Destroyer = std::destroy<T> >
  using SharedPtr = std::shared_ptr<T,Destroyer>;
#elif defined(VTK_USE_STD_SHARED_PTR_TR1)
  template <class T, class Destroyer = std::destroy<T> >
  using SharedPtr = std::tr1::shared_ptr<T,Destroyer>;
#else
  // ...implemation of shared_ptr
#endif
}

vtkm::SharedPtr


#if defined(GFOO_NS)
namespace {
  void foo() {
    printf("%s\n", __PRETTY_FUNCTION__);
  }

  template <class T>
  void fooT() {

  }
}
#elif defined(GFOO_GLOBAL)
void foo() {
  printf("%s\n", __PRETTY_FUNCTION__);
}
#elif defined(GFOO_STATIC)
static void foo() {
  printf("%s\n", __PRETTY_FUNCTION__);
}
#endif

//using namespace raju;
namespace anshul = raju::bar::foo;

int main(int argc, char* args[]) {
  Foo f;
  f.foo();
  FooS::foo();
  raju::bar::i_global = 2;
  anshul::foo();
  anshul::bar();
  //foo();
  ::foo();

  int i = 0;
  {
    int i = 1;
    i++;
    raju::i_global++;
  }
  printf("%d\n", i);
  printf("%d, %d, %d, %d\n", ::i_global, raju::i_global, raju::bar::i_global, raju::bar::foo::i_global);

  return 0;
}
