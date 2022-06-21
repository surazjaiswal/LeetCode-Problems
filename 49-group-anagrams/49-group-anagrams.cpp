class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        
        for(string str : strs){
            string rev = str;
            sort(rev.begin(),rev.end());
            mp[rev].push_back(str);
        }
        
        vector<vector<string>> ans;
        for(auto it : mp){
            vector<string> vt;
            for(auto s : it.second)
                vt.push_back(s);
            ans.push_back(vt);
        }
        
        return ans;
    }
};