//space complexity: O(1)
//time complexity (average):
//  preprocessing  O(m)
//  search         O(n)
//time complexity (worst):
//  preprocessing  O(m)
//  search         O(n*m)

#include <string>
#include <vector>

class Solution {
private:
  int pow_int(int base, int exp){
    int result = 1;
    while (exp--)
      result *= base;
    return (result);
}

  int mod_euclidean(int a, int b){
    if (b < 0)
      b = -b;
    int r = a % b;
    if (r < 0)
      r += b;
    return r;
  }

  int naive_strnstr(const std::string& haystack, const std::string& needle, size_t len){
    if (!needle.size())
      return (0);
    for (int i = 0; i < haystack.size() && len > 0; ++i){
      int j = 0;
      while (haystack[i + j] && haystack[i + j] == needle[i + j] && len - j > 0)
        ++j;
      if (!needle[i + j])
        return (i);
      else if (!haystack[i + j])
        break;
      --len;
    }
    return (-1);
  }
public:
  int strStr(std::string haystack, std::string needle){
    if (needle.empty())
      return (0);

    int p_hash = 0;
    int t_hash = 0;
    int q = 8388607;
    int d = pow_int(2, sizeof(std::string::value_type) * 8);
    int m;
    for (m = 0; m < needle.size(); ++m) {
      if (m >= haystack.size())
        return (-1);
      p_hash = mod_euclidean(d * p_hash + needle[m], q);
      t_hash = mod_euclidean(d * t_hash + haystack[m], q);
    }
    int h = 1;
    for (int i = 1; i < m; ++i)
      h = mod_euclidean(h * d, q);

    for (int i = 0; i + m <= haystack.size(); ++i){
      if (p_hash == t_hash){
        int match = naive_strnstr(haystack.substr(i), needle, m);
        if (match >= 0)
          return(match + i);
      }
      if (i + m < haystack.size())
        t_hash = mod_euclidean(haystack[i + m] + d
          * mod_euclidean(t_hash - mod_euclidean(h * haystack[i], q), q), q);
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
