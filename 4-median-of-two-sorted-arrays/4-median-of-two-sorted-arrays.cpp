class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // sorted arrays -> think of binary search
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int n1 = nums1.size(), n2 = nums2.size();
        // applying binary search over smaller size array
        int low = 0, high = n1;
        while(low <= high){
            int cut1 = (low+high)/2; // cut for the array 1
            int cut2 = (n1+n2+1)/2 - cut1; // cut for the second array for left-out elements, like 2 (this side) | 3 (that side) total 5 selected from total of 10 elements
            
            // check if there is no element left to cut
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            
            // check if there is no element right to cut
            int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];
            
            // check for cross elements
            if(left1 <= right2 && left2 <= right1){
                // if this is the case then we have the required cut position
                // now check for length of array 
                // for even length
                if((n1+n2)%2==0){
                    // median will be max of left side + min of right side / 2
                    return (max(left1,left2) + min(right1,right2)) / 2.0;
                }
                // for odd length
                else{
                    // in this case only one median which will be max of left part
                    return max(left1,left2);
                }
            }else if(left1 > right2){
                high = cut1 - 1;
            }else{
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};