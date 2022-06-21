class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        // the idea is prefix sum
        // if a,b,c,d->are prefix sums
        // then we need to find a value for which diff b/w any prefix sum (subsequence sum) is multiple of k
        // let a,b be any progressive subsequence then
        // we need to check (b-a)%k == 0
        // which also implies that a%k == b%k
        // so idea is to stroe the prefix sum modulo for every sum and keep checking if current prefix sum modulo has already occured or not of length greater than 2
        unordered_map<int,int> mp; // <sum,idx>
        mp[0]=-1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i]; // prefix sum
            int r = sum%k; // current prefix sum modulo
            
            // check if modulo is present in mp or not
            if(mp.count(r) == 0){
                // add it to mp
                mp[r] = i;
            }            
            else{
                // present, check idx difference
                if(i - mp[r] >= 2)
                    return true;
            }
            
            // do not update the existing element in the mp
            // edge case like [0,1,0], k=1 
            // prefix sum -> [0,1,1] every modulo will be 0, but with idx diff == 1 if idx in mp is updated
            
            // corner case -> [0,0]
            if(nums[i]==0 && i+1 < nums.size() && nums[i+1]==0)
                return true;
        }
        return false;
    }
};