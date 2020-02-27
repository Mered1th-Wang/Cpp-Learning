#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity)
    : _capacity(capacity)
    {}

    void put(int key, int value)
    {
        auto it = _hashMap.find(key);
        if(it == _hashMap.end())    //添加新元素
        {
            if(_cacheList.size() == _capacity)
            {
                int key = _cacheList.back().key;
                _hashMap.erase(key);
                _cacheList.pop_back();
            }
            _cacheList.push_front(CacheNode(key, value));
            _hashMap.insert(make_pair(key, _cacheList.begin()));
        }
        else{
            //key存在
            it->second->value = value;
            _cacheList.splice(_cacheList.begin(), _cacheList, it->second);
            _hashMap[key] = _cacheList.begin();
        }
    }

    int get(int key)
    {
        auto it = _hashMap.find(key);
        if(it == _hashMap.end())
            return -1;
        else{
            int value = it->second->value;
            _cacheList.splice(_cacheList.begin(), _cacheList, it->second);
            _hashMap[key] = _cacheList.begin();
            return value;
        }
    }

    struct CacheNode
    {
        int key;
        int value;
        CacheNode(int k, int v):key(k), value(v){}
    };

private:
    int _capacity;
    list<CacheNode> _cacheList;
    unordered_map<int, list<CacheNode>::iterator> _hashMap;
};

int main()
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
    return 0;
}
