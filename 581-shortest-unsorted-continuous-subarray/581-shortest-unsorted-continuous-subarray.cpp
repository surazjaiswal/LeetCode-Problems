class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        
        vector<int> vt = nums;
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        while(i<n){
            if(nums[i]!=vt[i])
                break;
            i++;
        }
        
        while(j>=0){
            if(nums[j]!=vt[j])
                break;
            j--;
        }
        
        if(i==n || j < 0)
            return 0;
        
        return j-i+1;
        
    }
};