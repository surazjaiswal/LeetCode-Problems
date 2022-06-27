class Solution {
public:
    int minPartitions(string n) {
        int mx = 0;
        for(char c : n){
            int d = c-'0';
            mx = max(mx,d);
        }
        return mx;
    }
};