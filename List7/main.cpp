#include "../List5/tree.h"
#include "rewrite_system.h"

int main () {
  tree l0("a");
  tree l1( std::string( "b" ));
  tree l2( std::string( "c" ));
  tree l3("e");

  tree t1("d", {l0, l1, l2});
  tree t2("d", {l0, l1, l3});

  std::cout << (t1 == t2);

  test();
}
