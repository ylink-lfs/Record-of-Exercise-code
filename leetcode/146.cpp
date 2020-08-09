class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = key_val_store.find(key);
        if(it == key_val_store.end())
            return -1;
        else
        {
            auto found_val = it->second;
            auto op_it = key_pos_store[key];
            body.erase(op_it);
            body.push_back(key);
            auto dummy = body.end(); dummy--;
            key_pos_store[key] = dummy;
            return found_val;
        }
    }
    
    void put(int key, int value) {
        if(key_val_store.find(key) == key_val_store.end())
        {
            if(body.size() >= cap)
            {
                auto erase_key = body.front();
                body.pop_front();
                key_val_store.erase(erase_key);
                key_pos_store.erase(erase_key);
            }
            body.push_back(key);
            key_val_store[key] = value;
            auto dummy = body.end(); dummy--;
            key_pos_store[key] = dummy;
        }
        else
        {
            auto op_it = key_pos_store[key];
            body.erase(op_it);
            body.push_back(key);
            key_val_store[key] = value;
            auto dummy = body.end(); dummy--;
            key_pos_store[key] = dummy;
        }
    }
    
    unordered_map<int, int> key_val_store;
    unordered_map<int, list<int>::iterator> key_pos_store;
    list<int> body;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
