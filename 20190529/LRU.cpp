#include <iostream>
#include <map>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity):_capacity(capacity){}
    int get(int key)
    {
        auto it = table.find(key);
        if(it != table.end())
        {
            int ret = it[key].second;
            CacheNode.push_front(pair<int,int>(it.first, ret));
            list.erase(it);
            //table[key] = CacheNode.begin(); 
            return ret;
        }
        else{
            return -1;
        }
    }
   // void put(int key, int value)
   // {
   //     if()
   // }

private:
    int capacity;
    list<int, int> CacheNode;
    unordered_map<int, list<int,int> > table; //用map加速访问，不需要排序
};

int main()
{
    LRUCache cache(2);
    //cache.put(1, 1); cache.put(2, 2);
    cache.get(1);       // returns 1
    //cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    //cache.put(4, 4);    // evicts key 1
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4

    return 0;
}
