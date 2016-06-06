#include <map>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <ctype.h>

struct case_insensitive {
  bool operator( ) ( const std::string& s1, const std::string& s2 ) const;
};

struct case_insensitive_hash
{
  size_t operator ( ) ( const std::string& s ) const;
};

struct case_insensitive_equality
{
  bool operator ( ) ( const std::string& s1,
                      const std::string& s2 ) const;
};

std::map<std::string, unsigned int, case_insensitive>
frequencyTable (const std::vector<std::string>& text) {
  std::map<std::string, unsigned int, case_insensitive> map;
  for (auto& s : text) {
    map[s]++;
  }
  return map;
}

std::ostream& operator<< (std::ostream& out,
                          const std::map<std::string, unsigned int, case_insensitive>& freqs)
{
  out << "[ ";
  for ( const auto& p : freqs ) {
    out << p.first << " : " << p.second << ", ";
  }
  out << "]";
  return out;
}

std::unordered_map<std::string, unsigned int, case_insensitive_hash, case_insensitive_equality>
hashed_frequencytable( const std::vector<std::string>& text ) {
  std::unordered_map<std::string, unsigned int, case_insensitive_hash, case_insensitive_equality> map;
  for (auto& s : text) {
    map[s]++;
  }
  return map;

}

bool case_insensitive::operator() (const std::string& s1,
                                   const std::string& s2 ) const
{
  size_t len1 = s1.length();
  size_t len2 = s2.length();
  size_t n = len1 <= len2 ? len1 : len2;
  for ( size_t i = 0; i < n; i++ ) {
    char c1 = tolower(s1[i]); char c2 = tolower(s2[i]);
    if ( c1 < c2 ) return true;
    if ( c1 > c2 ) return false;
  }
  return len1 < len2;
}

size_t case_insensitive_hash::operator ( ) ( const std::string& s ) const {
  std::string lc(s.length(), 'a');
  for ( size_t i = 0; i < s.length(); i++ ) lc[i] = tolower(s[i]);
  return std::hash<std::string>()(lc);
}

bool case_insensitive_equality::operator ( ) ( const std::string& s1,
                                               const std::string& s2 ) const
{
  size_t len1 = s1.length(); size_t len2 = s2.length();
  size_t n = len1 <= len2 ? len1 : len2;
  for ( size_t i = 0; i < n; i++ ) {
    char c1 = tolower(s1[i]); char c2 = tolower(s2[i]);
    if ( c1 != c2 ) return false;
  }
  return len1 == len2;
}

int main () {
  std::vector<std::string> text({"aaa", "bbb", "ccc", "aaa", "ddd"});
  std::map<std::string, unsigned int, case_insensitive> freqs = frequencyTable(text);
  std::cout << freqs << "\n";
  case_insensitive c;
  std::cout << c( "aab", "Aa" ) << c( "a","b" ) << c( "A", "b" ) << "\n";
  case_insensitive_hash h;
  std::cout << h( "xxx" ) << " " << h( "XXX" ) << "\n";
  std::cout << h( "Abc" ) << " " << h( "abC" ) << "\n";
  case_insensitive_equality e;
  std::cout << e( "xxx", "XXX" ) << "\n";
  std::vector<std::string> text2( { "aa", "AA", "bb", "BB" } );
  auto map2 = hashed_frequencytable(text2);
  for (auto p : map2) {
    std::cout << p.first << " : " << p.second << "\n";
  }


  return 0;
}
