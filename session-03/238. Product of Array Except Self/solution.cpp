#include <vector>
#include <ostream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> pref;
        pref.reserve(nums.size() - 1);
        std::vector<int> suff;
        suff.reserve(nums.size() - 1);

        for (int i = 0, product = 1; i < nums.size() - 1; ++i){
          product *= nums[i];
          pref.insert(pref.end(), product);
        }
        for (int i = nums.size() - 1, product = 1; i > 0; --i){
          product *= nums[i];
          suff.insert(suff.end(), product);
        }
        std::vector<int> result(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i){
          if (i < nums.size() - 1)
            result[i] *= suff[suff.size() - 1 - i];
          if (i)
            result[i] *= pref[i - 1];
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