class values{
public:
    char chr;
    int cnt;
    values(char chr, int cnt){
        this->chr = chr;
        this->cnt = cnt;
    }
};

class compare{
public:
    bool operator()(values *a,values *b){
        return a->cnt < b->cnt;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char,int> mp;
        for(char c : s)
            mp[c]++;
        
        priority_queue<values*,vector<values*>,compare> maxHeap;
        for(auto it : mp)
            maxHeap.push(new values(it.first,it.second));
        
        int n = s.length();
        char str[n];
        // cout<<sizeof(str)/sizeof('a')<<endl;
        int i = 0, k = 0;
        while(maxHeap.size()){
            values *val = maxHeap.top();
            maxHeap.pop();
            // char chr = val->chr;
            // int cnt = val->cnt;
            
            while(val->cnt){
                
                if(i >= n)
                    i=1;
                
                str[i] = val->chr;
                val->cnt--;
                i = i + 2;
                
                if(val->cnt == 0)
                    break;
                
            }
            
            if(i>=n)
                i=1;
        }
        
        for(int i=1;i<n;i++){
            if(str[i] == str[i-1])
                return "";
        }
        
        string ans ="";
        for(char ch : str)
            ans += ch;
        return ans;
        
    }
};