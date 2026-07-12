#include <vector>

//space complexity: O(n)
//time complexity: O(n)

class Solution {
private:
    typedef std::vector<int>::iterator It;
public:
    void rotate(std::vector<int>& nums, int k) {
      It it = nums.begin();
      k = k % nums.size();
      int tmp_n;
      int tmp_n_plus1;
      int distance;
        int i = 0;
        int elements_moved = 0;
        while (elements_moved < nums.size())
        {
          It start_it = nums.begin() + i;
          it = start_it;
          tmp_n = *it;
            do {
            tmp_n_plus1 = *it;
            *it = tmp_n;
            distance = std::distance(nums.begin(), it) + k;
            if (distance > nums.size() - 1)
              it = nums.begin() + (distance % nums.size());
            else
              it += k;
            tmp_n = tmp_n_plus1;
            elements_moved++;
            *start_it = tmp_n;
          } while (it != start_it );
          i++;
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
