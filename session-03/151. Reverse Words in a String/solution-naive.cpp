//space complexity: O(1)
//time complexity: O(n)

#include <string>

class Solution {
public:
  std::string reverseWords(std::string s) {
    bool in_word = false;
    std::string result;
    std::string::iterator word_end;
    std::string::reverse_iterator it;
    for (it = s.rbegin(); it != s.rend(); ++it){
      if (*it == ' '){
        if (in_word){
          if (!result.empty())
            result.append(1, ' ');
          result.append(it.base(), word_end);
        }
        in_word = false;
      }
      else {
        if (!in_word)
          word_end = it.base();
        in_word = true;
      }
    }
    if (in_word){
      if (!result.empty())
          result.append(1, ' ');
      result.append(it.base(), word_end);
    }
    return result;
  }
};

#include <iostream>
#include "../../utils.hpp"
int main(void)
{
  Solution test;
  std::vector<std::pair<std::string, std::string>> test_cases = {
    {"the sky is blue", "blue is sky the"},
    {"  hello world  ", "world hello"},
    {"a good   example", "example good a"}
  };

  std::vector<std::pair<std::string, std::string>>::iterator it;
  for (it = test_cases.begin(); it != test_cases.end(); ++it){
    std::string result;
    std::cout << it->first << '=';
    std::cout << (result = test.reverseWords(it->first)) << ':'
      << ((result == it->second) ? Color::GREEN + "OK" : Color::RED + "KO") << Color::RESET << '\n';
  }
}