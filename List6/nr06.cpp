
#include <fstream>
#include <iostream>
#include <chrono>
#include <random>
#include <string>

#include "listtest.h"
#include "vectortest.h"

int main( int argc, char* argv [] )
{
  // std::vector<std::string> invec = vectortest::readfile(std::cin);
  // std::cout << invec << "\n";

  auto n = std::stoul(argv[1]);
  auto s = std::stoul(argv[2]);
  std::vector< std::string > vect1 = vectortest::randomstrings(n, s);
  std::vector< std::string > vect2 = vect1;
  std::vector< std::string > vect3 = vect1;

  std::list<std::string> list1 = listtest::convert(vect1);
  std::list<std::string> list2 = list1;
  // std::list<std::string> list3 = list1;
  /*
  // std::cout << vect << "\n";
  std::cout << "sorting lists: \n" << "std::move:\n";
  auto tl1 = std::chrono::high_resolution_clock::now( );
  listtest::sort_move( list1 );
  auto tl2 = std::chrono::high_resolution_clock::now( );
  std::chrono::duration< double > dl1 = ( tl2 - tl1 );
  std::cout << "sorting took " << dl1. count( ) << " seconds\n";

  std::cout << "assign:\n";
  auto tl3 = std::chrono::high_resolution_clock::now( );
  listtest::sort_assign( list2 );
  auto tl4 = std::chrono::high_resolution_clock::now( );
  std::chrono::duration< double > dl2 = ( tl4 - tl3 );
  std::cout << "sorting took " << dl2. count( ) << " seconds\n";

  std::cout << "sorting vectors:\n" << "assign\n";
  auto tv1 = std::chrono::high_resolution_clock::now( );
  vectortest::sort_assign( vect1 );
  auto tv2 = std::chrono::high_resolution_clock::now( );
  std::chrono::duration< double > dv1 = ( tv2 - tv1 );
  std::cout << "sorting took " << dv1. count( ) << " seconds\n";

  std::cout << "std::move:\n";
  auto tv3 = std::chrono::high_resolution_clock::now( );
  vectortest::sort_move( vect2 );
  auto tv4 = std::chrono::high_resolution_clock::now( );
  std::chrono::duration< double > dv2 = ( tv4 - tv3 );
  std::cout << "sorting took " << dv2. count( ) << " seconds\n";

  std::cout << "std::sort:\n";
  auto tv5 = std::chrono::high_resolution_clock::now( );
  vectortest::sort_std( vect3 );
  auto tv6 = std::chrono::high_resolution_clock::now( );
  std::chrono::duration< double > dv3 = ( tv6 - tv5 );
  std::cout << "sorting took " << dv3. count( ) << " seconds\n";
  */
  std::cout << "sorting vectors:\n" << "move\n";
  auto tv1 = std::chrono::high_resolution_clock::now( );
  vectortest::sort_move2( vect1 );
  auto tv2 = std::chrono::high_resolution_clock::now( );
  std::chrono::duration< double > dv1 = ( tv2 - tv1 );
  std::cout << "sorting took " << dv1. count( ) << " seconds\n";

  std::cout << "move2:\n";
  auto tv3 = std::chrono::high_resolution_clock::now( );
  vectortest::sort_move( vect2 );
  auto tv4 = std::chrono::high_resolution_clock::now( );
  std::chrono::duration< double > dv2 = ( tv4 - tv3 );
  std::cout << "sorting took " << dv2. count( ) << " seconds\n";

  return 0;
}
