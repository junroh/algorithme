// https://leetcode.com/problems/lru-cache/
class LRUCache {
    list<pair<int,int>> dq;
    unordered_map<int, list<pair<int,int>>::iterator> cacheMap;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = cacheMap.find(key);
        if(it==cacheMap.end())
            return -1;
        int value = it->second->second;
        put(key, value);
        return value;
    }
    
    void put(int key, int value) {
        auto it = cacheMap.find(key);        
        if(it==cacheMap.end()) {
            if(dq.size()==cap) {
                cacheMap.erase(dq.back().first);
                dq.pop_back();
            }
        } else {
            dq.erase(it->second);
        }
        dq.push_front(make_pair(key,value));
        cacheMap[key] = dq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
