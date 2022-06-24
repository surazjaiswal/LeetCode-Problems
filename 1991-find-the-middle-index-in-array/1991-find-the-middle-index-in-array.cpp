class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n),rightSum(n);
        
        int s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            leftSum[i] = s;
        }
        
        s=0;
        for(int i=n-1;i>=0;i--){
            s+=nums[i];
            rightSum[i] = s;
        }
        
        // for(auto it:leftSum)
        //     cout<<it<<" ";
        // cout<<endl;
        // for(auto it:rightSum)
        //     cout<<it<<" ";
        // cout<<endl;
        
        for(int i=0;i<n;i++){
            if(leftSum[i]==rightSum[i])
                return i;
        }
        
        return -1;
    }
};