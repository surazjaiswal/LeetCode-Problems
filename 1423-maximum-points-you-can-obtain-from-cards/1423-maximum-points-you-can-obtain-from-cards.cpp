class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefix_sum(n+1);
        prefix_sum[0] = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += cardPoints[i];
            prefix_sum[i+1] = sum;
        }
        
        int ans = 0;
        int i=0, j=n-k;
        while(j<=n){
            int rsum = prefix_sum[j] - prefix_sum[i];
            ans = max(ans,sum - rsum);
            i++,j++;
        }
        
        return ans;
    }
};