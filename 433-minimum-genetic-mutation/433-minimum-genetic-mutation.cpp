class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<char> gene = {'A','C','G','T'};
        
        bool isPresent = false;
        unordered_set<string> bnk, visited;
        
        for(auto s : bank){
            if(s == end)
                isPresent = true;
            bnk.insert(s);
        }
        
        if(!isPresent)
            return -1;
        
        if(start == end)
            return 0;
        
        queue<string> q;
        q.push(start);
        visited.insert(start);
        
        int mutations = 0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string str = q.front();
                q.pop();
                
                for(int i=str.size()-1;i>=0;i--){
                    string temp = str;
                    for(char g : gene){
                        temp[i] = g;
                        if(bnk.count(temp) == 0)
                            continue;
                        
                        if(temp == end)
                            return mutations+1;
                        
                        if(visited.count(temp) == 0){
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            mutations++;
        }
        return -1;
    }
};