//space complexity: O(1)
//time complexity: O(n)

#include <string>
#include <unordered_map>

class Solution {
public:
  int romanToInt(std::string s) {
    static std::unordered_map<char, int> alphabet = {
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000},
    };
    int result = 0;
    for (std::string::reverse_iterator r_it = s.rbegin(), prev_it = r_it; r_it != s.rend(); ++r_it){
      if (alphabet[*r_it] < alphabet[*prev_it]){
        result -= alphabet[*r_it];
      }
      else
        result += alphabet[*r_it];
      prev_it = r_it;
    }
    return result;
  }
};

#include <iostream>
#include "../../utils.hpp"
int main(void)
{
  Solution test;
  std::vector<std::pair<std::string, int>> test_cases = {
    {"III", 3},
    {"LVIII", 58},
    {"MCMXCIV", 1994}
  };

  std::vector<std::pair<std::string, int>>::iterator it;
  for (it = test_cases.begin(); it != test_cases.end(); ++it){
    int result;
    std::cout << it->first << '=';
    std::cout << (result = test.romanToInt(it->first)) << ':'
      << ((result == it->second) ? Color::GREEN + "OK" : Color::RED + "KO") << Color::RESET << '\n';
  }
}