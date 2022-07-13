class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> dnd, visited; // to keep track of deadends and visited keys
        queue<string> q; // for BFS
        
        for(auto s : deadends)
            dnd.insert(s);
        
        string str = "0000"; // starting key
        
        // check if starting key is deadend or not
        if(dnd.count(str))
            return -1;
        
        // check if starting key is the target
        if(str == target)
            return 0;
        
        q.push(str);
        visited.insert(str);
        
        int moves = 0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string key = q.front();
                q.pop();
                
                // moves for each key
                for(int i=0;i<key.size();i++){
                    string tempA = key, tempB = key;
                    
                    // move up -> moving forward
                    if(tempA[i] == '9')
                        tempA[i] = '0';
                    else
                        tempA[i]++;
                    
                    if(dnd.count(tempA) == 0){
                        
                        // if found the target
                        if(tempA == target)
                            return moves + 1;
                        
                        //check if keys alreay visited already visited
                        if(visited.count(tempA) == 0){
                            q.push(tempA);
                            visited.insert(tempA);
                        }
                        
                    }
                    
                    // move down -> moving backward
                    if(tempB[i] == '0')
                        tempB[i] = '9';
                    else
                        tempB[i]--;
                    
                    // check if current formed keys are deadends                    
                    if(dnd.count(tempB) == 0){
                        
                        // if found the target
                        if(tempB == target)
                            return moves + 1;
                        
                        //check if keys alreay visited already visited
                        if(visited.count(tempB) == 0){
                            q.push(tempB);
                            visited.insert(tempB);
                        }
                    }
                        
                }
            }
            moves++;
        }
        
        return -1;
    }
};