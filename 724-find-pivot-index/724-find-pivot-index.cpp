class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
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
        
        /*
        int n=nums.size();
        int sum=0;
        for(auto it:nums)
            sum+=it;
        int sumL=0,sumR=sum;
        for(int i=0;i<n;i++){
            sumL=sum-sumR;
            sumR-=nums[i];
            // cout<<sumL<<" "<<sumR<<endl;
            if(sumL==sumR)
                return i;          
        }
        return -1;
        */
    }
};