//space complexity: O(1) (subject says: "The output array does not count as extra space for space complexity analysis")
//time complexity: O(n)

#include <vector>
#include <ostream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> result(nums.size(), 1);
        for (int i = nums.size() - 1, product = 1; i > 0; --i){
          product *= nums[i];
          result[i - 1] = product;
        }
        for (int i = 0, product = 1; i < nums.size(); ++i){
          result[i] *= product;
          product *= nums[i];
        }
        return result;
    }
};

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

#include <iostream>
int main(void)
{
  Solution test;
  std::vector<int> test_vec1{1,2,3,4};
  std::vector<int> test_vec2{-1,1,0,-3,3};
  std::cout << test.productExceptSelf(test_vec1) << std::endl;
  std::cout << test.productExceptSelf(test_vec2) << std::endl;
}
