#include <vector>

//space complexity: O(1)
//time complexity: O(n)

class Solution {
private:
    typedef std::vector<int>::iterator It;
public:
    int removeDuplicates(std::vector<int>& nums) {
      int k = nums.size();
      int repetition_n = 0;
      It write_head = nums.begin();
      It read_head = write_head;
      for (; read_head != nums.end(); ++read_head) {
        int prev;
        if (read_head != nums.begin()) {
          if (*read_head != prev)
            repetition_n = 0;
        }
        ++repetition_n;
        if (write_head != read_head)
          *write_head = *read_head;
        prev = *read_head;
        if (repetition_n > 2)
          --k;
        else
          ++write_head;
      }
      return (k);
    }
};

#include <iostream>
int main(void)
{
  Solution test;
  std::vector<int> test_vec{0,0,1,1,1,1,2,3,3,3,3,3,3,3};
  int k;
  std::cout << (k = test.removeDuplicates(test_vec)) << std::endl;
  for(int i = 0; i < k; ++i)
    std::cout << test_vec[i] << " ";
  std::cout << std::endl;
}
