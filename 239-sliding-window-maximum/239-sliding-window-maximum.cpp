class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<int> maxHeap;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            maxHeap.push(nums[i]);
        }
        
        vector<int> ans;
        ans.push_back(maxHeap.top()); // adding 1st window - max element
        
        int i=1,j=k;
        while(j<nums.size()){
            
            mp[nums[i-1]]--; // removing front element from map
            mp[nums[j]]++; // including next element to map
            maxHeap.push(nums[j]); // adding next element to heap
            
            if(mp[maxHeap.top()] == 0){
                while(mp[maxHeap.top()] == 0){
                    // cout<<maxHeap.top()<<endl;
                    maxHeap.pop();
                }
            }
            
            ans.push_back(maxHeap.top());
            
            i++,j++;
        }
        
        return ans;
    }
};