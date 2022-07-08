class values{
public:
    string str;
    int cnt;
    values(string str, int cnt){
        this->str = str;
        this->cnt = cnt;
    }
};

class compare{
public:
    bool operator()(values *a, values *b){
        if(a->cnt == b->cnt)
            return a->str > b->str;
        return a->cnt < b->cnt; // this will create maxHeap
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(string str : words)
            mp[str]++;
        
        priority_queue<values*,vector<values*>,compare> maxHeap;
        for(auto it : mp)
            maxHeap.push(new values(it.first,it.second));
        
        int cnt=0;
        vector<string> ans;
        while(maxHeap.size()){
            // cout<<maxHeap.top()->str<<" "<<maxHeap.top()->cnt<<endl;
            if(cnt++ < k)
                ans.push_back(maxHeap.top()->str);
            else break;
            maxHeap.pop();
        }
        return ans;
    }
};