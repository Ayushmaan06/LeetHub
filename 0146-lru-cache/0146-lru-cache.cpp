#include <unordered_map>
#include <list>

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1; // Key not found

        // Move the accessed item to the front of the list
        recent.splice(recent.begin(), recent, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = cache.find(key);

        if (it != cache.end()) {
            // Key exists, update the value and move it to the front of the list
            it->second->second = value;
            recent.splice(recent.begin(), recent, it->second);
        } else {
            // Key does not exist
            if (recent.size() == capacity) {
                // Capacity is full, remove the least recently used item
                int old_key = recent.back().first;
                recent.pop_back();
                cache.erase(old_key);
            }
            // Insert the new key-value pair
            recent.emplace_front(key, value);
            cache[key] = recent.begin();
        }
    }

private:
    int capacity;
    std::list<std::pair<int, int>> recent; // List to store the keys and values
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache; // Hash map to store the key and corresponding list iterator
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
