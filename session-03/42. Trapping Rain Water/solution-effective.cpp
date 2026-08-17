//space complexity: O(1)
//time complexity: O(n)

#include <vector>

class Solution {
private:
    typedef std::vector<int>::iterator It;
public:
    int trap(std::vector<int>& height) {
      It left = height.begin();
      It right = height.end() - 1;
      int l_peak = 0;
      int r_peak = 0;
      int result = 0;
      while (left < right){
        if (*left <= *right){
          if (*left > l_peak)
            l_peak = *left;
          else
            result += l_peak - *left;
          ++left;
        }
        else {
          if (*right > r_peak)
            r_peak = *right;
          else
            result += r_peak - *right;
          --right;
        }
      }
      return result;
    }
};

#include <iostream>
#include "../../utils.hpp"
int main(void)
{
  Solution test;
  std::vector<std::pair<std::vector<int>, int>> test_cases = {
    {{4,2,3}, 1},
    {{0,1,0,2,1,0,1,3,2,1,2,1}, 6},
    {{0,1,0,2,1,0,1,2,2,1,2,1}, 6},
    {{4,2,0,3,2,5}, 9}
  };

  std::vector<std::pair<std::vector<int>, int>>::iterator it;
  for (it = test_cases.begin(); it != test_cases.end(); ++it){
    int result;
    std::cout << (result = test.trap(it->first)) << ':'
      << ((result == it->second) ? Color::GREEN + "OK" : Color::RED + "KO") << Color::RESET << '\n';
  }
}
