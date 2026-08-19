//space complexity: O(1)
//time complexity: O(n)

#include <string>
#include <cstdlib>

class Solution {
public:
  std::string convert(std::string s, int numRows) {
    std::string result;
    for (int jump_a = numRows + std::max(numRows - 2, 0), jump_b = 0,
          i = 0; i < numRows; ++i){
      int j = i;
      bool jump_selector = true;
      while (j < s.size()){
        result.append(1, s[j]);
        j += ((jump_selector && jump_a) || !jump_b) ? jump_a : jump_b;
        jump_selector = !jump_selector;
      }
      jump_a -= 2;
      jump_b += 2;
    }
    return result;
  } 
};

#include <iostream>
#include <tuple>
#include "../../utils.hpp"
int main(void)
{
  Solution test;
  std::vector<std::pair<std::tuple<std::string, int>, std::string>> test_cases = {
    {{"PAYPALISHIRING", 3}, "PAHNAPLSIIGYIR"},
    {{"PAYPALISHIRING", 4}, "PINALSIGYAHRPI"},
    {{"AB", 1}, "AB"},
    {{"A", 1}, "A"}
  };

  std::vector<std::pair<std::tuple<std::string, int>, std::string>>::iterator it;
  for (it = test_cases.begin(); it != test_cases.end(); ++it){
    std::string result;
    std::cout << std::get<0>(it->first) << ' '
      << std::get<1>(it->first) << " rows " << '=';
    std::cout << (result = test.convert(std::get<0>(it->first), std::get<1>(it->first))) << ':'
      << ((result == it->second) ? Color::GREEN + "OK" : Color::RED + "KO") << Color::RESET << '\n';
  }
}