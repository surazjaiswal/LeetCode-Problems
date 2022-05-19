class Solution {
public:
    int nextGreaterElement(int n) {
        // applying the same concept as in next permutation problem (31)
        
        // for this we will first convert n to nums as list of digits, then apply the above concept
        vector<int> nums;
        long long num=n;
        while(num){
            int r = num%10;
            nums.push_back(r);
            num /= 10;
        }
        
        // checking if the number of digitd are greater than required 
        // if(nums.size()>9){
        //     return -1;
        // }
        reverse(nums.begin(),nums.end());
        
        // now finding the non increasing subsequence position
        int i=nums.size()-1;
        while(i>0 && nums[i-1] >= nums[i]){
            i--;
        }
        
        if(i<=0){
            // current number is the largest possible number
            return -1;
        }
        
        // else we have number at i-1 as pivot element
        // now we will find a number just greater than pivot element
        int j = nums.size()-1;
        while(j>=0 && nums[j] <= nums[i-1]){
            j--;
        }
        
        // now the number at j is just greater than pivot element
        // now we will swap them
        swap(nums[i-1],nums[j]);
        // now we have to reverse elements right to pivot to make it smaller number
        reverse(nums.begin()+i,nums.end());
        
        
        // now at last we will convert nums array to num
        num=0;
        for(int i : nums){
            num = num*10 + i;
            if(num > INT_MAX)
                return -1;
        }
        return num;
    }
};