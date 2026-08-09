//space complexity: O(n)
//time complexity: O(n)

#include <vector>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
      std::vector<int> buckets(citations.size() + 1);
      for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] > citations.size()){
          ++buckets[citations.size()];
        }
        else{
          ++buckets[citations[i]];
        }
      }

      int s = 0;
      for (int i = buckets.size() - 1; i >= 0; --i){
        s += buckets[i];
        if (i <= s)
          return (i);
      }
      return (0);
    }
};


#include <iostream>
int main(void)
{
  Solution test;
  std::vector<int> test_vec1{3,0,6,1,5};
  std::vector<int> test_vec2{1,3,1};
  std::vector<int> test_vec3{100};
  std::cout << test.hIndex(test_vec1) << std::endl;
  std::cout << test.hIndex(test_vec2) << std::endl;
  std::cout << test.hIndex(test_vec3) << std::endl;
}
