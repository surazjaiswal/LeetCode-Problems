class compare{
    public:
    bool operator()(pair<int,int> p1,pair<int,int> p2){
        return p1.first < p2.first;
    }
};

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n,INT_MIN);
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> maxHeap;
        dp[0] = nums[0];
        maxHeap.push({nums[0],0});
        vector<bool> isPresent(n,false);
        isPresent[0] = true;
        for(int i=1;i<n;i++){
            // cout<<maxHeap.top().first<<" "<<maxHeap.top().second<<endl;
            if(maxHeap.size() < k){
                int curr_score = nums[i] + maxHeap.top().first;
                dp[i] = curr_score;
                maxHeap.push({curr_score,i});
                isPresent[i]=true;
            }
            else{
                if(!isPresent[maxHeap.top().second]){
                    while(!isPresent[maxHeap.top().second]){
                        maxHeap.pop();
                    }
                }
                int curr_score = nums[i] + maxHeap.top().first;
                dp[i] = curr_score;
                maxHeap.push({curr_score,i});
                isPresent[i]=true;
            }
            
            if(i - k >= 0)
                isPresent[i-k]=false;
        }
        return dp[n-1];
    }
};