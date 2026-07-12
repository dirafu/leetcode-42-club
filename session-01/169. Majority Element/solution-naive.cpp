#include <vector>
#include <map>

//space complexity: O(n)
//time complexity: O(nlog(n))

class Solution {
private:
    typedef std::vector<int>::iterator It;
public:
    int majorityElement(std::vector<int>& nums) {
      std::map<int, int> freq;
      for (It it = nums.begin(); it != nums.end(); ++it) {
        if (++freq[*it] > (nums.size() / 2)) {
          return (*it);
        }
      }
      return (0);
    }
};

#include <iostream>
int main(void)
{
  Solution test;
  std::vector<int> test_vec{2,2,1,1,1,2,2};
  std::cout << test.majorityElement(test_vec) << std::endl;
}
