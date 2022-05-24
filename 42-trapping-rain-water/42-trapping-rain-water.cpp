class Solution {
public:
    int trap(vector<int>& height) {
        int num = height.size();
        if(num==0)
            return 0;
        vector<int> leftMax(num),rightMax(num);
        int temp = height[0];
        for(int i=0;i<num;i++){
            if(height[i]>temp)
                temp=height[i];
            leftMax[i]=temp;
        }
        temp = height[num-1];
        for(int i=num-1;i>=0;i--){
            if(height[i]>temp)
                temp=height[i];
            rightMax[i]=temp;
        }
        int sum=0;
        for(int i=0;i<num;i++)
            sum+=min(leftMax[i],rightMax[i]) - height[i];
        return sum; 
    }
};