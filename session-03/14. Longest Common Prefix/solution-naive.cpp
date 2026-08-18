//space complexity: O(1)
//time complexity: O(nm)

#include <string>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    int i;
    for (i = 0; i < strs[0].size(); ++i){
      char c = strs[0][i];
      for (int j = 1; j < strs.size(); ++j){
        if (i >= strs[j].size() || strs[j][i] != c)
          return (strs[0].substr(0, i));
      }
    }
    return (strs[0].substr(0, i));
  }
};

#include <iostream>
#include "../../utils.hpp"
int main(void)
{
  Solution test;
  std::vector<std::pair<std::vector<std::string>, std::string>> test_cases = {
    {{"flower","flow","flight"}, "fl"},
    {{"dog","racecar","car"}, ""}
  };

  std::vector<std::pair<std::vector<std::string>, std::string>>::iterator it;
  for (it = test_cases.begin(); it != test_cases.end(); ++it){
    std::string result;
    std::cout << it->first << '=';
    std::cout << (result = test.longestCommonPrefix(it->first)) << ':'
      << ((result == it->second) ? Color::GREEN + "OK" : Color::RED + "KO") << Color::RESET << '\n';
  }
}