class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int num = graph.size();
        vector<int> visited(num);
        int color=1;
        bool ans;
        for(int i=0;i<num;i++){
            if(!visited[i]){
                if(!dfs_helper(i,visited,-1,color,graph))
                    return false;
            }
        }
        // for (int i = 0; i < num; i++)
        //     cout << "Color of " << i << " -> " << visited[i] << endl;
        return true;
    }
    bool dfs_helper(int node,vector<int> &visited,int parent,int color, vector<vector<int>>& graph){
        visited[node] = color;
        // cout<<node<<" -> "<<color<<endl;
        for(auto nbr : graph[node]){
            if(visited[nbr]==0){
                bool isBip = dfs_helper(nbr,visited,node,3-color,graph);
                if(!isBip)
                    return false;
            }else if(visited[nbr]==color && parent!=node)
                return false;
        }
        return true;
    }
};