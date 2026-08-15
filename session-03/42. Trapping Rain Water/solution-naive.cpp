//space complexity: O(1)
//time complexity: O(n)

#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        if (height.size() <= 2)
          return (0);
        int result = 0;
        int highest = 0;
        for (int i = 1, peak = 0, chunk = 0; i < height.size(); ++i){
          if (height[i - 1] > highest)
            highest = height[i - 1];
          if (!peak && height[i] < height[i - 1]){
            peak = height[i - 1];
          }
          if (peak){
            if (height[i] < peak)
              chunk += peak - height[i];
            else{
              peak = 0;
              result += chunk;
              chunk = 0;
            }
          }
        }
        for (int i = height.size() - 2, peak = 0, chunk = 0;
              i >= 0 && height[i + 1] < highest; --i){
          if (!peak && height[i] < height[i + 1]){
            peak = height[i + 1];
          }
          if (peak){
            if (height[i] < peak)
              chunk += peak - height[i];
            else{
              peak = 0;
              result += chunk;
              chunk = 0;
            }
          }
        }
        return (result);
    }
};

#include <iostream>
#include <ostream>
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

std::ostream& operator<<(std::ostream& lhs, const std::vector<int>& rhs)
{
  std::vector<int>::const_iterator it;
  lhs << '[';
  for (it = rhs.begin(); it != rhs.end(); ++it){
    if (it != rhs.begin())
      lhs << ", ";
    lhs << *it;
  }
  lhs << ']';
  return lhs;
}

namespace Color {
    const std::string RESET   = "\033[0m";
    const std::string RED     = "\033[31m";
    const std::string GREEN   = "\033[32m";
    const std::string YELLOW  = "\033[33m";
    const std::string BLUE    = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN    = "\033[36m";
}
