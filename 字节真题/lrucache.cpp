class LRUCache {
public:
    //val
    list<pair<int, int>> data;
    //key, list node addr
    unordered_map<int, list<pair<int, int>>::iterator> key_node_mp;
    int cap;
    
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        
        if(key_node_mp.find(key) != key_node_mp.end()) {
            int resval = key_node_mp[key]->second;
            auto node_addr = key_node_mp[key];
            data.erase(node_addr);
            data.push_front(make_pair(key, resval));
            key_node_mp[key] = data.begin();
            return resval;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(key_node_mp.find(key) != key_node_mp.end())
        {
            auto node_addr = key_node_mp[key];
            data.erase(node_addr);
            data.push_front(make_pair(key, value));
            key_node_mp[key] = data.begin();
        }
        else if(data.size() >= cap)
        {
            int erase_key = data.back().first;
            key_node_mp.erase(erase_key);
            data.pop_back();
            data.push_front(make_pair(key, value));
            key_node_mp[key] = data.begin();
        }
        else
        {
            data.push_front(make_pair(key, value));
            key_node_mp[key] = data.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
