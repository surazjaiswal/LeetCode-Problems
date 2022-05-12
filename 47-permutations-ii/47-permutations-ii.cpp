class Solution {
public:
    set<string> st;
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int n=nums.size();
        
        string s="";
        for(auto it : nums)
            s+=(char)it;
        
        permute(0,n,nums,s);
        return ans;
    }
    
    void permute(int i,int n,vector<int> &nums,string &s){
        if(i==n){
            if(!st.count(s)){
                ans.push_back(nums);
                st.insert(s);
            }
            return;
        }
        
        for(int j=i;j<n;j++){
            swap(s[i],s[j]);
            swap(nums[i],nums[j]);
            permute(i+1,n,nums,s);
            swap(nums[i],nums[j]);
            swap(s[i],s[j]);
        }
        return;
    }
};