class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // this problem is similar to inversion count
        int n = nums.size();
        vector<pair<int,int>> vt;
        vector<int> count(n,0);
        
        for(int i=0;i<n;i++)
            vt.push_back({nums[i],i});
        
        mergeSort(vt,count,0,n-1);
        
        return count;
    }
    
    void mergeSort(vector<pair<int,int>> &vt,vector<int> &count,int low, int high){
        if(low<high){
            int mid = (low+high)/2;
            mergeSort(vt,count,low,mid);
            mergeSort(vt,count,mid+1,high);
            mergeArr(vt,count,low,mid,high);
        }
    }
    
    void mergeArr(vector<pair<int,int>> &vt,vector<int> &count,int low,int mid, int high){
        vector<pair<int,int>> temp_vt;
        int i=low, j=mid+1;
        
        while(i<=mid && j<=high){
            if(vt[i].first <= vt[j].first){
                temp_vt.push_back(vt[j]);
                j++;
            }else{
                count[vt[i].second] += high - j + 1;
                temp_vt.push_back(vt[i]);
                i++;
            }
        }
        
        while(i<=mid){
            temp_vt.push_back(vt[i++]);
        }
        
        while(j<=high){
            temp_vt.push_back(vt[j++]);
        }
        
        int k=0;
        for(int i=low;i<=high;i++){
           vt[i] = temp_vt[k++];
        }
        
    }
};