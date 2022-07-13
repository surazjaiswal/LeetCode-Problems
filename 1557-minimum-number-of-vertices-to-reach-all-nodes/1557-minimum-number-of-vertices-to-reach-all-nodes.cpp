class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,1);
        for(auto it: edges){
            visited[it[1]]=0;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(visited[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};