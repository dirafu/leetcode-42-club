//space complexity: O(1)
//time complexity: O(n*l)

#include <string>
#include <vector>

class Solution {
private:
  typedef std::vector<std::string>::iterator It;
  std::string get_line(It start, size_t word_count, size_t spaces) {
    std::string res;
    int gap;
    int surplus;
    if (word_count == 1) {
      gap = spaces;
      surplus = 0;
    }
    else {
      gap = spaces / (word_count - 1);
      surplus = spaces % (word_count - 1);
    }
    for (It it = start; it != (start + word_count); ++it) {
      res.append(*it);
      if (it + 1 != start + word_count || word_count == 1) {
        res.append(gap, ' ');
        if (surplus) {
        res.append(1, ' ');
        --surplus;
        }
      }
    }
    return (res);
  }
public:
  std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
    std::vector<std::string> result;
    int line_so_far_len = 0;
    int words_count = 0;
    It line_start = words.begin();
    for (It it = words.begin(); it != words.end(); ++it){
      if (line_so_far_len + (*it).size() + words_count > maxWidth){
        result.push_back(get_line(line_start, words_count, maxWidth - line_so_far_len));
        line_start = it;
        line_so_far_len = 0;
        words_count = 0;
      }
      line_so_far_len += (*it).size();
      ++words_count;
    }
    std::string last_line;
    for (It it = line_start; it != words.end(); ++it){
      last_line.append(*it);
      if (it + 1 == words.end())
        last_line.append(maxWidth - line_so_far_len - words_count + 1, ' ');
      else
        last_line.append(1, ' ');
    }
    result.push_back(last_line);
    return (result);
  }
};

#include <iostream>
#include <tuple>
#include "../../utils.hpp"
int main(void)
{
  Solution test;
  typedef std::vector<std::pair<std::tuple<std::vector<std::string>, int>,
            std::vector<std::string>>> test_cases_t;
  test_cases_t test_cases = {
    {{{"This", "is", "an", "example", "of", "text", "justification."}, 16},
      {"This    is    an", "example  of text", "justification.  "}},
    {{{"What","must","be","acknowledgment","shall","be"}, 16},
      {"What   must   be", "acknowledgment  ", "shall be        "}},
    {{{"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"}, 20},
      {"Science  is  what we", "understand      well", "enough to explain to", "a  computer.  Art is", "everything  else  we", "do                  "}}
  };

  test_cases_t::iterator it;
  for (it = test_cases.begin(); it != test_cases.end(); ++it){
    std::vector<std::string> result;
    std::cout << std::get<0>(it->first) << ' '
      << " width:" << std::get<1>(it->first) << '=';
    std::cout << (result = test.fullJustify(std::get<0>(it->first), std::get<1>(it->first))) << ':'
      << ((result == it->second) ? Color::GREEN + "OK" : Color::RED + "KO") << Color::RESET << '\n';
  }
}