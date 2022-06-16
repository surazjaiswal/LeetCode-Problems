class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        int cnt=0;
        for(int num : nums){        
            if(cnt<k){
                minHeap.push(num);
                cnt++;
            }
            else{
                if(num > minHeap.top()){
                    minHeap.pop();
                    minHeap.push(num);
                }
            }
        }
        int ans=minHeap.top();
        return ans;
    }
};