class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // sort(points.begin(),points.end());
        priority_queue<pair<int,vector<int>>> pq;
        int cnt=0;
        for(auto point : points){
            int dist = pow(point[0],2) + pow(point[1],2);
            if(cnt<k){
                pq.push({dist,point});
                cnt++;
            }else{
                auto it = pq.top();
                if(it.first > dist){
                    pq.pop();
                    pq.push({dist,point});
                }
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto it = pq.top();
            ans.push_back(it.second);
            pq.pop();
        }
        return ans;
    }
};