#include <vector>
#include <map>

//space complexity: O(1)
//time complexity: O(n)

class Solution {
private:
    typedef std::vector<int>::iterator It;
public:
    int majorityElement(std::vector<int>& nums) {
      int cand;
      int k = 0;
      for (It it = nums.begin(); it != nums.end(); ++it) {
        if (k) {
          if (*it == cand)
            ++k;
          else
            --k;
        }
        else {
          cand = *it;
          ++k;
        }
      }
      return (cand);
    }
};

#include <iostream>
int main(void)
{
  Solution test;
  std::vector<int> test_vec{2,2,1,1,1,2,2};
  std::cout << test.majorityElement(test_vec) << std::endl;
}
