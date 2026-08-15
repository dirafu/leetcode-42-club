//space complexity: O(1)
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
    int sum_ap(int a1, int n){
        int an = a1 + n - 1;
        if (!(n % 2))
          return ((a1 + an) * (n / 2));
        else
          return (((a1 + an) / 2) * n);
      }

    int candy(std::vector<int>& ratings) {
        int result = 0;
        for (int i = 0, upslope = 0, downslope = 0, h_up = 0; i < ratings.size(); ++i){
          if (i && ratings[i] > ratings[i - 1]){
            if (downslope){
              result += std::max(h_up, downslope) + 1;
              h_up = 0;
              result += sum_ap(2, downslope - 1);
              downslope = 0;
            }
            ++upslope;
          }
          else if (i && ratings[i] < ratings[i - 1]){
            if (upslope){
              result += sum_ap(1, upslope);
              h_up = upslope;
              upslope = 0;
            }
            ++downslope;
          }
          if (!i || ratings[i] == ratings[i - 1] || i == ratings.size() - 1){
            if (upslope || downslope){
              result += sum_ap(1, (upslope | downslope));
              result += std::max(h_up | upslope, downslope) + 1;
              upslope = 0;
              downslope = 0;
              h_up = 0;
            }
            if ((!i || ratings[i] == ratings[i - 1])
                && (i == ratings.size() - 1 || ratings[i + 1] == ratings[i]))
              result += 1;
          }
        }
        return result;
    }
};

int main(void)
{
  Solution test;
  std::vector<std::pair<std::vector<int>, int>> test_cases = {
    {{42,42}, 2},
    {{5,3,7,3}, 6},
    {{1,0,2}, 5},
    {{1,2,2}, 4},
    {{1,3,2,2,1}, 7},
    {{1,2,87,87,87,2,1}, 13},
    {{1,3,4,5,2}, 11}
  };

  std::vector<std::pair<std::vector<int>, int>>::iterator it;
  for (it = test_cases.begin(); it != test_cases.end(); ++it){
    int result;
    std::cout << it->first << std::endl;
    std::cout << (result = test.candy(it->first)) << ':'
      << ((result == it->second) ? Color::GREEN + "OK" : Color::RED + "KO") << Color::RESET << '\n';
  }
}
