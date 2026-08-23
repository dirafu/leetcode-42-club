//space complexity: O(...)
//time complexity: O(...)

#include <vector>
#include <algorithm>

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
      int biggest_side = 0;
      for (int i = 0; i < matrix.size(); ++i){
        for (int j = 0; j < matrix[i].size(); ++j){
          bool obstacle = matrix[i][j] != '1';
          int side = 1;
          while (!obstacle){
            biggest_side = std::max(biggest_side, side);
            if (i + side >= matrix.size() || j + side >= matrix[i].size())
              break;
            ++side;
            for (int k = i; !obstacle && k < i + side - 1; ++k){
              obstacle = matrix[k][j + side - 1] != '1';
            }
            for (int h = j; !obstacle && h < j + side; ++h){
              obstacle = matrix[i + side - 1][h] != '1';
            }
          }
        }
      }
      return (biggest_side * biggest_side);
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