//space complexity: O(1)
//time complexity: O(n)

#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int max_jump_bound = 0;
        int jump_counter = 0;
        int curr_bound = 0;
        for (int i = 0; i < nums.size(); ++i){
          if (i > curr_bound){
            ++jump_counter;
            curr_bound = max_jump_bound;
          }
          int curr_max_jump = i + nums[i];
          if (curr_max_jump > max_jump_bound){
            max_jump_bound = curr_max_jump;
          }
          if (max_jump_bound >= nums.size() - 1){
            if (curr_bound < nums.size() - 1)
              ++jump_counter;
            return jump_counter;
          }
        }
        return -1;
    }
};

#include <iostream>
int main(void)
{
  Solution test;
  std::vector<int> test_vec1{2,3,1,1,4};
  std::vector<int> test_vec2{7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
  std::vector<int> test_vec3{0};
  std::cout << test.jump(test_vec1) << std::endl;
  std::cout << test.jump(test_vec2) << std::endl;
  std::cout << test.jump(test_vec3) << std::endl;
}
