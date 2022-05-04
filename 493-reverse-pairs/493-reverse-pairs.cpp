class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int ans = revCount(nums,0,n-1);
        return ans;
    }
    
    int revCount(vector<int> &nums,int l,int h){
        if(l>=h)
            return 0;
        
        int mid = (l+h)/2;
        int x = revCount(nums,l,mid);
        int y = revCount(nums,mid+1,h);
        int z = mergeCount(nums,l,mid,h);
        
        return x+y+z;
    }
    
    int mergeCount(vector<int> &nums,int l,int mid,int h){
        int i=l,j=mid+1,k=l;
        int cnt = 0;
        
        while(i<=mid && j<=h){
            if((long long)nums[i] > (long long)2*(nums[j])){
                cnt += mid - i + 1;
                j++;
            }else{
                i++;
            }
        }
        
        i=l,j=mid+1;
        vector<int> vt;
        while(i<=mid && j<=h){
            if(nums[i] < nums[j]){
                vt.push_back(nums[i++]);
            }else{
                vt.push_back(nums[j++]);
            }
        }
        
        while(i<=mid){
            vt.push_back(nums[i++]);
        }
        
        while(j<=h){
            vt.push_back(nums[j++]);
        }
        
        int c=0;
        for(int k=l;k<=h;k++){
            nums[k] = vt[c++];
        }
        
        return cnt;
    }
    
    
};