class LRUCache {
private:
    int cap;
    list<int> lru_list;
    unordered_map<int, std::pair<int, std::list<int>::iterator>> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        int value = mp[key].first;
        lru_list.erase(mp[key].second);
        lru_list.push_front(key);
        mp[key].second = lru_list.begin();
    
        return value;
    }
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            lru_list.erase(mp[key].second);
            lru_list.push_front(key);
            mp[key] = {value, lru_list.begin()};
        } else {
            if (mp.size() == cap) {
                int lru = lru_list.back();
                lru_list.pop_back();
                mp.erase(lru);
            }
            lru_list.push_front(key);
            mp[key] = {value, lru_list.begin()};
        }
    }
};