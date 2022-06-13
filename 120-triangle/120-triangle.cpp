class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       int n=triangle.size();
        vector<int> ans(n,0);
        ans[0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=i;j>=0;j--){
                if(j==0)
                    ans[j] = ans[0] + triangle[i][j];
                else if(j==i)
                    ans[j] = ans[j-1] + triangle[i][j];
                else{
                    ans[j] = min(ans[j],ans[j-1]) + triangle[i][j];
                }
            }
        }
        // for(auto it:ans)
        //     cout<<it<<" " ;
        return *min_element(ans.begin(),ans.end());
    }
};