#include <vector>
#include <stdexcept>
#include <climits>

//space complexity: O(1)
//time complexity: O(n^2)

class Solution {
private:
    typedef std::vector<int>::iterator It;
    void shiftLeft(std::vector<int>& nums, int shift_amount, It begin, It end) {
      It target;
      if (shift_amount <= std::distance(nums.begin(), begin))
        target = begin - shift_amount;
      else
        throw (std::runtime_error("out of bounds array shift attempt"));
      for (It it = begin; it != end; ++it)
        *target++ = *it;
    }
public:
    int removeDuplicates(std::vector<int>& nums) {
      int k = nums.size();
      int repetition_n = 0;
      It it = nums.begin();
      for (int i = 0; i < k; ++i)
      {
        int prev;
        if (it != nums.begin()) {
          if (prev != *it)
            repetition_n = 0;
        }
        if (++repetition_n > 2) {
          while (i < k && *it == prev) {
            shiftLeft(nums, 1, it + 1, nums.begin() + k--);
          }
          i--;
          continue;
        }
        prev = *it;
        ++it;
      }
      return (k);
    }
};

#include <iostream>
int main(void)
{
  Solution test;
  // std::vector<int> test_vec{0,0,1,1,1,1,2,3,3};
  std::vector<int> test_vec{0,0,1,1,1,1,2,3,3,3,3,3,3,3};
  int k;
  std::cout << (k = test.removeDuplicates(test_vec)) << std::endl;
  for(int i = 0; i < k; ++i)
    std::cout << test_vec[i] << " ";
  std::cout << std::endl;
}