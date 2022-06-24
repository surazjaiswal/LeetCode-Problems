class Solution {
public:
    int pivotIndex(vector<int>& nums) {
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
    }
};