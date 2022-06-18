class values{
public:
    int dist;
    int x,y;
    values(int dist,int x,int y){
        this->dist = dist;
        this->x  = x;
        this->y = y;
    }
};

class compare{
public:
    bool operator()(values *a, values *b){
        return a->dist > b->dist; // this will create minHeap
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<values*,vector<values*>,compare> minHeap;
        
        for(auto it : points){
            int x = it[0], y = it[1];
            int dist = (pow(x,2) + pow(y,2));
            minHeap.push(new values(dist,x,y));
        }
        
        vector<vector<int>> ans;
        int cnt=0;
        while(minHeap.size()){
            values *val = minHeap.top();
            minHeap.pop();
            if(cnt++ < k)
                ans.push_back({val->x,val->y});
            else break;
        }
        return ans;
    }
};