class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(nums1.size()==0)
            nums2=nums1;
        
        int k=0;
        for(int i=m;i<nums1.size();i++)
            nums1[i]=nums2[k++];
        sort(nums1.begin(),nums1.end());
        
    }
};