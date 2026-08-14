//space complexity: O(n)
//time complexity: O(n)

#include <vector>

#include <iostream>
#include <ostream>
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

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        std::vector<int> candies(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); ++i){
          if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
        }

        for (int i = ratings.size() - 2; i >= 0; --i){
          if (ratings[i] > ratings[i + 1]){
            if (candies[i] < candies[i + 1] + 1)
              candies[i] = candies[i + 1] + 1;
          }
        }

        std::cout << candies << std::endl;

        int result = 0;
        for (int i = 0; i < candies.size(); ++i){
          result += candies[i];
        }
        return result;
    }
};

int main(void)
{
  Solution test;
  std::vector<std::pair<std::vector<int>, int>> test_cases = {
    {{1,0,2}, 5},
    {{1,2,2}, 4},
    {{1,3,2,2,1}, 7},
    {{1,2,87,87,87,2,1}, 13},
    {{1,3,4,5,2}, 11}
  };

  std::vector<std::pair<std::vector<int>, int>>::iterator it;
  for (it = test_cases.begin(); it != test_cases.end(); ++it){
    int result;
    std::cout << (result = test.candy(it->first)) << ':'
      << ((result == it->second) ? Color::GREEN + "OK" : Color::RED + "KO") << Color::RESET << '\n';
  }
}
