class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i : stones)
            pq.push(i);
        
        while(pq.size()>1){
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            int left = abs(s2-s1);
            pq.push(left);
        }
        int ans = pq.top();
        return ans;
    }
};