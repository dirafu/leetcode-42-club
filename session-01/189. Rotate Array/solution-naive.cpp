#include <vector>

//space complexity: O(n)
//time complexity: O(n)

class Solution {
private:
    typedef std::vector<int>::iterator It;
public:
    void rotate(std::vector<int>& nums, int k) {
      std::vector orig(nums);
      int i = 0;
      for (It it = orig.begin(); it != orig.end(); ++it) {
        nums[(i + k) % nums.size()] = *it;
        ++i;
      }
    }
};

#include <iostream>
int main(void)
{
  Solution test;
  std::vector<int> test_vec{-1,-100,3,99};
  int k = 2;
  test.rotate(test_vec, k);
  for(int i = 0; i < test_vec.size(); ++i)
    std::cout << test_vec[i] << " ";
  std::cout << std::endl;
}