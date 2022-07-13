class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        vector<char> gene = {'A','C','G','T'}; // types of genes
        
        bool isPresent = false; // for checking is end mutation is present in bank or not
        unordered_set<string> bnk, visited; // for checking of available and non visited mutation
        
        for(auto s : bank){
            if(s == end)
                isPresent = true; // end mutation is present in the bank
            bnk.insert(s);
        }
        
        // if end mutation not present in bank
        if(!isPresent)
            return -1;
        
        // if start and end mutation are same
        if(start == end)
            return 0;
        
        queue<string> q; // for BFS, leads to min change path to end muatation
        q.push(start);
        visited.insert(start);
        
        int mutations = 0; // count no. of mutations required
        
        while(!q.empty()){
            int sz = q.size(); // number of mutations possible from current state
            while(sz--){
                string str = q.front();
                q.pop();
                
                // check for every char that can lead to target gene
                for(int i=str.size()-1;i>=0;i--){
                    string temp = str;
                    for(char g : gene){
                        temp[i] = g;
                        
                        // if current mutation not in bank
                        if(bnk.count(temp) == 0)
                            continue;
                        
                        // current mutation is equal to target gene
                        if(temp == end)
                            return mutations+1;
                        
                        // if current mutation is not visited already
                        if(visited.count(temp) == 0){
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            mutations++; // moving to next level
        }
        return -1;
    }
};