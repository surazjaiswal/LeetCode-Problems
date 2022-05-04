class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // the answer will include elements which occur more than n/3 times
        // that means elements occuring more than equal to (n/3) + 1, will included
        // now if we divide the array in parts of size (n/3)+1 
        // we will get three parts of array that is [(n/3)+1], [(n/3)+1] and [(n/3)-2] in size
        // this impiles that the max number of elements that can occur more than (n/3) times is only 2
        
        // now applying Boyer Moore Majority Vote Algorithm
        
        // take element two variables and their count variable
        int element_1,element_2;
        int cnt_1=0,cnt_2=0;
        
        for(int num : nums){
            // check if it curr num is equal to majority 
            // by compairing to majority element variables
            if(element_1 == num){
                cnt_1++;
            }
            else if(element_2 == num){
                cnt_2++;
            }
            // now check if now count of any element is zero
            // so that we can assgin new majority element to it for counting
            else if(cnt_1 == 0){
                // this case implies that no element is currently choosen as majority
                element_1 = num; // choose the current element to be majority
                cnt_1++; // increase its count
            }
            else if(cnt_2 == 0){
                // this case implies that no element is currently choosen as majority
                element_2 = num;// choose the current element to be majority
                cnt_2++; // increase its count
            }
            else{
                // this case implies that current element is not equal to selected majority elements
                // therefore this current elements presence in the array reduces the chance of selected majority occurance
                cnt_1--;
                cnt_2--;
            }
        }
        
        // at this point we have two elements in in our element bucket element_1 and element_2
        // now check that original count of occurance of these two element 
        // and find if they occur more than (n/3) times
        
        int cnt1=0,cnt2=0;
        for(int num : nums){
            if(num == element_1)
                cnt1++;
            if(num == element_2)
                cnt2++;
        }
        
        vector<int> ans;
        int n=nums.size();
        if(cnt1 > n/3)
            ans.push_back(element_1); // if count of element_1 is more than n/3 push it to ans
        if(cnt2 > n/3)
            ans.push_back(element_2); // if count of element_2 is more than n/3 push it to ans
        
        return ans;
    }
    
    // This algo takes const space (space complexity O(1))
    // Time complexity is O(N), since we traversed the array 2 times independently O(N+N) = O(2N) = O(N)
};




