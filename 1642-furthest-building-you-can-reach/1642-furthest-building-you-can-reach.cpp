class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        // minHeap for storing min diff b/w heights so as to use minDiff only for the bricks
        priority_queue<int,vector<int>, greater<int>> minHeap; 
        // we can also have maxHeap that is default heap and store negative values for the diff
        // this will work same
        
        for(int i=0;i<n-1;i++){
            int diff = heights[i+1] - heights[i];
            // if diff is > 0 then we add it minHeap
            // assuming it to be the large diff and we would use ladders for this case
            if(diff > 0){
                minHeap.push(diff);
            }
            // now as for each diff in minHeap we are suppose to use ladder
            // but if ladder count is less than its use case (ladders < heap.size()), this will limit its use
            // so here we will use bricks, so we take the top of minHeap which gives min height diff 
            // hence here we can use the bricks, and save the ladder for larger diff
            
            if(minHeap.size() > ladders){
                bricks -= minHeap.top(); // decrease the number of bricks by as much utilized
                minHeap.pop(); // pop the diff for which we used the bricks
            }
            // if case aries that number of bricks is negative
            // means that at this very step we used amount of bricks which are not available and ladders are reserved for larger diff occured
            // so no way further we can move forwards from this stage
            if(bricks < 0)
                return i;
        }
        // at this stage we have reach to last building
        return n-1;
    }
};