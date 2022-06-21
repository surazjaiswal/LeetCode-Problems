class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Here the main concept used is prefix sum
        // the advantage here is we can calculate subarray sum using prefix sum
        // required subarray sum can be calculated by subtracting the previous subarray sum i.e prefix sum
        //subarry_sum[i,j] = prefix_sum_till[j] - prefix_sum_till[i]; this will give subarray sum form i to j
        
        // the same concept can be visualized as;
        // let's consider a subarray sum S
        // is there a subarray whose sum is S - k present in the current subarray that has occured before
        // if there is then, we can see the subarray sum like
        // (S - K) + (K) = S, that is this configuration is possible when current subarray possess
        // two subarrays with sums as (S-K) and (K) <--- this is what we want
        // so for this we will maintain a map to check if (curr_prefix_sum - target_sum) has appreared before or not
        // if appeared then add its count to answer
        
        
        unordered_map<int,int> mp; // map to maintain prefix_sum that occured before
        int prefix_sum=0;
        int ans=0;
        
        mp[0]=1; 
        // this is done because we can have a edge case where we get the subarray sum from start of array
        // like we have [3,2,1], k=5
        // prefix_sum for till i=1 is 5
        // in map we will search for 5(prefix_sum) - 5(target) = 0, which might not be present 
        // therefore we are adding it to the map
        
        for(int i=0;i<nums.size();i++){
            prefix_sum += nums[i];
            // now check, is there subarray sum i.e. (prefix_sum-target) occured
            if(mp[prefix_sum - k]){
                ans += mp[prefix_sum - k]; // adding it to answer count, each of prefix_sum will produce required subarray sum
            }
            
            mp[prefix_sum]++; // counting the occurance of prefix_sum
        }
        
        return ans;
    }
};