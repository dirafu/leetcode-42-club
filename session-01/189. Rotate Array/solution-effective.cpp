#include <vector>

//space complexity: O(n)
//time complexity: O(n)

class Solution {
private:
    typedef std::vector<int>::iterator It;
public:
    void rotate(std::vector<int>& nums, int k) {
      It it = nums.begin();
      int tmp_n;
      int tmp_n_plus1;
      int distance;
      if (nums.size() % k)
      {
        do {
          tmp_n = *it;
          distance = std::distance(nums.begin(), it) + k;
          if (distance > nums.size())
            it = nums.begin() + distance % k;
          else
            it += k;
          *it = tmp_n;
          tmp_n = tmp_n_plus1;
        } while (it != nums.begin());
        
        it += k;
        tmp_n_plus1 = *it;
        *it = tmp_n;
        tmp_n = tmp_n_plus1;
        while (it != nums.begin())
        {
          tmp_n_plus1 = *it;
          distance = std::distance(nums.begin(), it) + k;
          if (distance > nums.size())
            it = nums.begin() + distance % k;
          else
            it += k;
          *it = tmp_n;
          tmp_n = tmp_n_plus1;
        }
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