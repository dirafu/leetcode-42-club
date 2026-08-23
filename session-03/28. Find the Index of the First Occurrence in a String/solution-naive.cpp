//space complexity: O(1)
//time complexity: O(n*m)

#include <string>

class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    int needle_idx = 0;
    int i = 0;
    bool in_needle = false;
    for (std::string::iterator hay_it = haystack.begin(), needle_it = needle.begin();
          hay_it != haystack.end(); ++hay_it, ++i){
      if (*hay_it == *needle_it){
        if (!in_needle)
          needle_idx = i;
        in_needle = true;
        ++needle_it;
        if (needle_it == needle.end())
          return needle_idx;
      }
      else {
        if (in_needle){
          hay_it = haystack.begin() + needle_idx;
          i = needle_idx;
        }
        in_needle = false;
        needle_it = needle.begin();
      }
    }
    return (-1);
  } 
};

#include <iostream>
#include <tuple>
#include "../../utils.hpp"
int main(void)
{
  Solution test;
  std::vector<std::pair<std::tuple<std::string, std::string>, int>> test_cases = {
    {{"sadbutsad", "sad"}, 0},
    {{"leetcode", "leeto"}, -1},
    {{"mississippi", "issip"}, 4}
  };

  std::vector<std::pair<std::tuple<std::string, std::string>, int>>::iterator it;
  for (it = test_cases.begin(); it != test_cases.end(); ++it){
    int result;
    std::cout << std::get<0>(it->first) << ' '
      << " needle:" << std::get<1>(it->first) << '=';
    std::cout << (result = test.strStr(std::get<0>(it->first), std::get<1>(it->first))) << ':'
      << ((result == it->second) ? Color::GREEN + "OK" : Color::RED + "KO") << Color::RESET << '\n';
  }
}