class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        timeRecord.push_back(t);
        int cnt = 0;
        for(int i = timeRecord.size() - 1; i >= 0 && t - timeRecord[i] <= 3000; i--)
        {
            cnt++;
        }
        return cnt;
    }
private:
    vector<int> timeRecord;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
