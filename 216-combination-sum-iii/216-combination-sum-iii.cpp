class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        
        int minSum = (k*(k+1))/2;
        if(minSum > n)
            return {};
        
        vector<int> nums;
        getSum(nums,1,0,k,n,0);
        return ans;
    }
    
    void getSum(vector<int> &nums,int i, int cnt, int k, int n, int sum){
        if(cnt > k){
            return;
        }
        
        if(sum == n && nums.size()==k){
            ans.push_back(nums);
            return;
        }
        
        for(int j=i;j<=9;j++){
            sum += j;
            nums.push_back(j);
            getSum(nums,j+1,cnt+1,k,n,sum);
            sum -= j;
            nums.pop_back();            
        }
    }
};