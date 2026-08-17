//space complexity: O(1)
//time complexity: O(n)

#include <string>

class Solution {
public:
  int lengthOfLastWord(std::string s) {
    int last_word_len = 0;
    bool in_word = false;
    for (std::string::iterator it = s.begin(); it != s.end(); ++it){
      if (*it != ' '){
        if (!in_word)
          last_word_len = 0;
        in_word = true;
        ++last_word_len;
      }
      else
        in_word = false;
    }
    return last_word_len;
  }
};

#include <iostream>
#include "../../utils.hpp"
int main(void)
{
  Solution test;
  std::vector<std::pair<std::string, int>> test_cases = {
    {"Hello World", 5},
    {"   fly me   to   the moon  ", 4},
    {"luffy is still joyboy", 6}
  };

  std::vector<std::pair<std::string, int>>::iterator it;
  for (it = test_cases.begin(); it != test_cases.end(); ++it){
    int result;
    std::cout << it->first << '=';
    std::cout << (result = test.lengthOfLastWord(it->first)) << ':'
      << ((result == it->second) ? Color::GREEN + "OK" : Color::RED + "KO") << Color::RESET << '\n';
  }
}