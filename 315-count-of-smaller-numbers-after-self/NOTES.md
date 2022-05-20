Brute Force
**TLE**
​
```
class Solution {
public:
vector<int> countSmaller(vector<int>& nums) {
int n=nums.size();
vector<int> ans(n);
for(int i=0;i<n;i++){
int cnt=0;
for(int j=i+1;j<n;j++){
if(nums[j]<nums[i])
cnt++;
}
ans[i]=cnt;
}
return ans;
}
};
```
​
​
​
https://www.youtube.com/watch?v=_sA1xI4XK0c
​
https://github.com/Ayu-99/Data-Structures/blob/master/Leetcode%20Challenge/June/Count%20of%20Smaller%20Numbers%20After%20Self.cpp