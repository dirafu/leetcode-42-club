//space complexity: O(n)
//time complexity: O(n*log(n))

#include <vector>
#include <map>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
      std::map<int, int> hist;
      for (int i = 0; i < citations.size(); ++i) {
        ++hist[citations[i]];
      }
      int s = 0;
      int max_h = 0;
      for (std::map<int, int>::reverse_iterator it = hist.rbegin();
      it != hist.rend(); ++it){
        s += it->second;
        max_h = std::max(max_h, std::min(it->first, s));
      }
      return (max_h);
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
