

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int,int> mp;
        for(int i:nums){
            if(mp[i])
                mp[i]++;
            else
                mp[i]=1;
        }
        vector<pair<int,int>> vt;
        
        for(auto it : mp)
            vt.push_back({it.first,it.second});
        
        sort(vt.begin(),vt.end(),cmp);
        vector<int> ans;
        
        for(auto it:vt){
            if(k--)
                ans.push_back(it.first);
            else
                break;
        }
        
        return ans;
    }
    
    bool static cmp(pair<int,int> v1,pair<int,int> v2){
        return v1.second > v2.second;
    }
};