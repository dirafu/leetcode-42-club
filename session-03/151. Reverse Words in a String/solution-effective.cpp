//space complexity: O(1)
//time complexity: O(n)

#include <string>
#include <algorithm>

class Solution {
public:
  std::string reverseWords(std::string s) {
    std::reverse(s.begin(), s.end());
    bool in_word = false;
    std::string::iterator write_it;
    std::string::iterator read_it;
    std::string::iterator word_start_it;
    for (write_it = s.begin(), read_it = s.begin(); read_it != s.end(); ++read_it){
      if (*read_it != ' '){
        if (!in_word)
          word_start_it = read_it;
        in_word = true;
      }
      if (*read_it == ' '){
        if (in_word){
          if (write_it != s.begin()){
            *write_it = ' ';
            ++write_it;
          }
          std::reverse(word_start_it, read_it);
          std::move(word_start_it, read_it, write_it);
          write_it += std::distance(word_start_it, read_it);
        }
      in_word = false;
      }
    }
    if (in_word){
      if (write_it != s.begin()){
        *write_it = ' ';
        ++write_it;
      }
      std::reverse(word_start_it, read_it);
      std::move(word_start_it, read_it, write_it);
      write_it += std::distance(word_start_it, read_it);
    }
    s.resize(std::distance(s.begin(), write_it));
    return s;
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