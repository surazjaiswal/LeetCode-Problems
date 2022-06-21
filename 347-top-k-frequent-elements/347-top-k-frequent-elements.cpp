
class compare{
    public:
    bool operator()(pair<int,int> p1,pair<int,int>p2){
        return p1.second < p2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        unordered_map<int,int> mp;
        for(int num : nums)
            mp[num]++;
        
        for(auto it : mp)
            pq.push({it.first,it.second});
        
        vector<int> ans;
        while(pq.size() && k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};