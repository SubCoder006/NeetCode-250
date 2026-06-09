class MyHashMap {
   public:
    int size;
    vector<list<pair<int, int>>> buckets;
    MyHashMap() {
        size = 1000;
        buckets.resize(size);
    }

    int hash(int key) { return key % size; }

    void put(int key, int value) {
        int idx = hash(key);
        for (auto& it : buckets[idx]) {
            if (it.first == key) {
                it.second = value;  // update
                return;
            }
        }
        buckets[idx].push_back({key, value});
    }

    int get(int key) {
        int idx = hash(key);
        for (auto& it : buckets[idx]) {
            if (it.first == key) {
                return it.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int idx = hash(key);
        for (auto it = buckets[idx].begin(); it != buckets[idx].end(); it++) {
            if (it->first == key) {
                buckets[idx].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */