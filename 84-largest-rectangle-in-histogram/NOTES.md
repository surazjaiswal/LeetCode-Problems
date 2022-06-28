https://www.youtube.com/watch?v=vhUxKxiconE
​
**TLE**
```
class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
int n = heights.size();
int max_ar=0;
for(int i=0;i<n;i++){
int curr_h = heights[i];
int left = i-1,right=i+1;
while(left>=0 && heights[left]>curr_h){
left--;
}
while(right<n && heights[right]>curr_h){
right++;
}
int curr_ar = curr_h * (right-left-1);
max_ar = max(max_ar,curr_ar);
}
return max_ar;
}
};
```
​