//space complexity: O(...)
//time complexity: O(...)

#include <vector>
#include <algorithm>

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
      std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix[0].size()));
      int max_side = 0;
      for (int i = 0; i < matrix.size(); ++i){
        for (int j = 0; j < matrix[i].size(); ++j){
          if (matrix[i][j] == '0')
            dp[i][j] = 0;
          else if (!i || !j)
            dp[i][j] = 1;
          else
            dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
          max_side = std::max(max_side, dp[i][j]);
        }
      }
      return max_side * max_side;
    }
};

#include <iostream>
#include <tuple>
#include "../../utils.hpp"
int main(void)
{
  Solution test;
  std::vector<std::pair<std::tuple<std::vector<std::vector<char>>>, int>> test_cases = {
    {{{{'1','0','1','0','0'},
      {'1','0','1','1','1'},
      {'1','1','1','1','1'},
      {'1','0','0','1','0'}}}, 4},
    {{{{'0','1'},
      {'1','0'}}}, 1},
    {{{{'0'}}}, 0}
  };

  std::vector<std::pair<std::tuple<std::vector<std::vector<char>>>, int>>::iterator it;
  for (it = test_cases.begin(); it != test_cases.end(); ++it){
    int result;
    std::cout << std::get<0>(it->first) << ' ' << '=';
    std::cout << (result = test.maximalSquare(std::get<0>(it->first))) << ':'
      << ((result == it->second) ? Color::GREEN + "OK" : Color::RED + "KO") << Color::RESET << '\n';
  }
}