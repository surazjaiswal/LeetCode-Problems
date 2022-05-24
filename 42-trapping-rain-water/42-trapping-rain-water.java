class Solution {
    public int trap(int[] height) {
        int n = height.length;
        
        int left[] = new int[n];
        int right[] = new int[n];
        
        int maxLeft = height[0];
        for(int i=0;i<n;i++){
            maxLeft = Math.max(maxLeft,height[i]);
            left[i] = maxLeft;
        }
        
        int maxRight = height[n-1];
        for(int i=n-1;i>=0;i--){
            maxRight = Math.max(maxRight,height[i]);
            right[i] = maxRight;
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans += Math.min(left[i],right[i]) - height[i];
        }
        
        return ans;
    }
}