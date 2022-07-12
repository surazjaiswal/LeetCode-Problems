class Solution {
public:
    bool makesquare(vector<int>& sticks) {
        int sum = 0;
        for(int i : sticks)
            sum += i;
        
        // if sum cannot be divided among all 4 sides
        if(sum % 4 > 0)
            return false;
        
        // len of each side
        int side = sum/4;
        
        // making stick sorted in decending order 
        // this help in reducing unnecessary calls, since all large invalid side len will be checked first 
        sort(sticks.begin(),sticks.end(),greater<int>());
        
        return solve(sticks,0,side,side,side,side);
    }
    
    // backtracking apporach placing stick every stick on all possible sides 
    // TC : O(4^N), we have 4 side choice of placement for each stick
    bool solve(vector<int>& sticks,int i,int left,int top,int right,int bottom){
        
        // wrong posistioning of sticks
        if(i > sticks.size() || left < 0 || top < 0 || right < 0 || bottom < 0)
            return false;
        
        // all the sticks placed correctly
        if(i == sticks.size())
            return true;
        
        // all the sticks placed correctly, no side has any space left
        if(left == 0 && top == 0 && right == 0 && bottom == 0)
            return true;
        
        // keep stick on left side
        if(solve(sticks,i+1,left - sticks[i],top,right,bottom))
            return true;
        
        // keep stick on top side
        if(solve(sticks,i+1,left,top - sticks[i],right,bottom))
            return true;
        
        // keep stick on right side
        if(solve(sticks,i+1,left,top,right - sticks[i],bottom))
            return true;
        
        // keep stick on bottom side
        if(solve(sticks,i+1,left,top,right,bottom - sticks[i]))
            return true;
        
        // no correct position available
        return false;
    }
};