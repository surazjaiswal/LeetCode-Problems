class MyHashSet {
public:
    
    vector<int> nums;
    MyHashSet() {
        nums.resize(1e6+1,-1);
    }
    
    void add(int key) {
        nums[key] = 1;
    }
    
    void remove(int key) {
        nums[key] = -1;
    }
    
    bool contains(int key) {
        if(nums[key] == 1)
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */