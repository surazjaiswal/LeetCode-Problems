class Solution {
public:
    int dp[601][101][101] = {};
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        vector<pair<int,int>> vt;
        for(string str : strs){
            int a=0,b=0;
            for(int i=0;i<str.length();i++){                
                if(str[i]-'0' == 0)
                    a++;
                else
                    b++;
            }
            vt.push_back({a,b});
        }
        int ans = getMaxSize(vt,0,m,n);
        return ans;
    }
    
    int getMaxSize(vector<pair<int,int>> &vt, int idx, int zeroCnt, int oneCnt){
        // base case 
        if(idx == vt.size() || (zeroCnt == 0 && oneCnt == 0))
            return 0;
        
        if(dp[idx][zeroCnt][oneCnt] != -1)
            return dp[idx][zeroCnt][oneCnt];
        
        if(vt[idx].first > zeroCnt || vt[idx].second > oneCnt)
            return dp[idx][zeroCnt][oneCnt] = getMaxSize(vt,idx+1,zeroCnt,oneCnt);
        
        // two case include or exclude
        int inCnt = 1 + getMaxSize(vt,idx+1,zeroCnt - vt[idx].first,oneCnt - vt[idx].second);
        int exCnt = getMaxSize(vt,idx+1,zeroCnt,oneCnt);
        
        return dp[idx][zeroCnt][oneCnt] = max(inCnt,exCnt);
    }
};