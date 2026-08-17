//space complexity: O(1)
//time complexity: O(n)

#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
  std::string intToRoman(int num) {
    static std::unordered_map<int, char> alphabet = {
      {1,   'I'},
      {5,   'V'},
      {10,  'X'},
      {50,  'L'},
      {100, 'C'},
      {500, 'D'},
      {1000,'M'}
    };
    std::string result;
    int rem;
    int tens = 1;
    while (num){
      rem = num % 10;
      num /= 10;
      if (rem > 0 && rem <= 3){
        while (rem--)
          result.append(1, alphabet[tens]);
      }
      else if (rem == 4 || rem == 9){
        result.append(1, alphabet[(rem + 1) * tens]);
        result.append(1, alphabet[tens]);
      }
      else if (rem){
        while (rem > 5){
          result.append(1, alphabet[tens]);
          --rem;
        }
        result.append(1, alphabet[5 * tens]);
      }
      tens *= 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};

#include <iostream>
#include "../../utils.hpp"
int main(void)
{
  Solution test;
  std::vector<std::pair<int, std::string>> test_cases = {
    {3749, "MMMDCCXLIX"},
    {58, "LVIII"},
    {1994, "MCMXCIV"}
  };

  std::vector<std::pair<int, std::string>>::iterator it;
  for (it = test_cases.begin(); it != test_cases.end(); ++it){
    std::string result;
    std::cout << it->first << '=';
    std::cout << (result = test.intToRoman(it->first)) << ':'
      << ((result == it->second) ? Color::GREEN + "OK" : Color::RED + "KO") << Color::RESET << '\n';
  }
}