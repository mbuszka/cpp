
#include "tree.h"


int main( int argc, char* argv [ ] )
{
  tree t0("a");
  tree t1( std::string( "b" ));
  tree t2( std::string( "c" ));
  tree td("d", {t1, t2});
  tree t3 = tree( std::string( "f" ), {t0, td} );
  tree t4("h");
  std::cout << "moving:\n\t" << t4 << "\n\t";
  t4 = t3;
  std::cout << t4 << "\n";
  t3.replacefunctor("changed");
  std::cout << "changed functor\n\t" << t4 << " >> " << t3 << "\n";
  std::cout << "replacesubtree b -> bb:[c, a] :\n\t" << td << " >> ";
  tree t5 = tree("bb", {t0, t2});
  td.replacesubtree(0, t5);
  std::cout << td << "\n";
  tree t6 = subst(t4, "b", tree("alpha", {tree("beta"), tree("gamma")}));
  std::cout << "subst:\n\t" << t4 << " >> " << t6 << '\n';
  std::cout << "addreses:\nnode changes:\n\t"
            << t4.getaddress() << " >> " << t6.getaddress()
            << "\nnode doesn't change:\n\t"
            << t4[0].getaddress() << " >> " << t6[0].getaddress() << '\n';
  return 0;
}
