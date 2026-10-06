//space complexity: O(m)
//time complexity:
//  preprocessing  O(m)
//  search         O(n)

#include <string>
#include <vector>

class Solution {
private:
  std::vector<int> compute_prefix(const std::string& needle){
    std::vector<int> pref_table;
    int q = 0;
    pref_table.reserve(needle.size());
    pref_table.push_back(0);
    for (int i = 1; i < needle.size(); ++i){
      while (q > 0 && needle[q] != needle[i]){
        q = pref_table[q - 1];
      }
      if (needle[q] == needle[i])
        ++q;
      pref_table.push_back(q);
    }
    return (pref_table);
  }
public:
  int strStr(std::string haystack, std::string needle) {
    std::vector prefix_table = compute_prefix(needle);
    int q = 0;
    for (int i = 0; i < haystack.size(); ++i){
      while (q > 0 && needle[q] != haystack[i]){
        q = prefix_table[q - 1];
      }
      if (needle[q] == haystack[i])
        ++q;
      if (q == needle.size())
        return (i - q + 1);
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