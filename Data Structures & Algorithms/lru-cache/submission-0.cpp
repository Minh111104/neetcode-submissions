class LRUCache {
private:
    int capacity; // maximum # of items allowed

    // Stores {key, value}.
    // Front = most recently used
    // Back = least recently used
    list<pair<int, int>> cache;

    // key -> iterator pointing to that key's node in the list or address of this node
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // Key does not exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        // Move the accessed node to the front because it is now the most recently used item
        auto node = mp[key];
        int value = node->second;

        cache.erase(node);
        cache.push_front({key, value}); // Insert it at the front

        // Update the iterator because we erased the node
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        // If the key already exists, remove its old node
        if (mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        }

        // Add and update the key as the most recently used item
        cache.push_front({key, value});
        mp[key] = cache.begin();

        // If capacity is exceeded, remove the least recently used item from the back
        if (cache.size() > capacity) {
            int lruKey = cache.back().first;

            mp.erase(lruKey);
            cache.pop_back();
        }
    }
};