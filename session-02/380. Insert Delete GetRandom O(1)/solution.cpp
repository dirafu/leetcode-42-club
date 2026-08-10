#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>

class RandomizedSet {
private:
    std::unordered_map<int, int> hashmap;
    std::vector<int> rand_pool;
public:
    RandomizedSet() {
      std::srand(std::time(0));
    }
    
    bool insert(int val) {
      if (hashmap.find(val) == hashmap.end()){
        rand_pool.insert(rand_pool.end(), val);
        hashmap[val] = rand_pool.size() - 1;
        return true;
      }
      return false;
    }
    
    bool remove(int val) {
      if (auto it = hashmap.find(val); it != hashmap.end()){
        std::swap(rand_pool[it->second], rand_pool[rand_pool.size() - 1]);
        hashmap[rand_pool[it->second]] = it->second;
        rand_pool.erase(rand_pool.begin() + rand_pool.size() - 1);
        hashmap.erase(it);
        return true;
      }
      return false;
    }
    
    int getRandom() {
        return (rand_pool[std::rand() % rand_pool.size()]);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

//["RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"]
//[[],[1],[2],[2],[],[1],[2],[]]

int main(void)
{
  int val = 42;
  RandomizedSet* obj = new RandomizedSet();
  obj->insert(1);
  obj->remove(2);
  obj->insert(2);
  obj->getRandom();
  obj->remove(1);
  obj->insert(2);
  obj->getRandom();
  delete obj;
}