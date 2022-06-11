class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0,n=nums.size();
        for(int num : nums)total+=num;
        int need=total-x,cur=0,longest=0;
        if(need==0)return n;
        int l=0,r=0;
        while(l<=r){
            if(cur<need){
                if(r<n)cur+=nums[r++];
                else break;
            }else if(cur>need){
                cur-=nums[l++];
            }else{
                longest=max(longest,r-l);
                cur-=nums[l++];
            }
        }
        if(cur==need)longest=max(longest,r-l);
        if(longest==0)return -1;
        return n-longest;
    }
};