#include <map>
#include <vector>
#include <iostream>

std::map<std::string, unsigned int>
frequencyTable (const std::vector<std::string>& text) {
  std::map<std::string, unsigned int> map;
  for (auto& s : text) {
    map[s]++;
  }
  return map;
}

int main () {
  std::vector<std::string> text({"aaa", "bbb", "ccc", "aaa", "ddd"});



  return 0;
}

std::ostream& operator<< (std::ostream& out,
                          std::map<std::string, unsigned int>& tab)
{
  
  return out;
}
