class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer Moore Algorithm
        // if we divide the array in two parts of size (n/2 + 1) and left size will be (n/2 - 1)
        // hence we can see that only one element has the chance of becomming majority element
        // which will have the count greater than equal to (n/2 + 1)
        
        int num; // element that can be majority element
        int cnt=0; // count of the current choosen majority element
        
        for(int i : nums){
            if(i == num){
                // if curr selected element is equal to i then increase the cnt
                // as the occurance of i will increase the chance of num of becomming majority
                cnt++;
            }
            else if(cnt == 0){
                // if no element is choosen as majority then choose one and increase the cnt
                // this also occurs when some other element has reduced the chance of num becomming majority
                num = i; 
                cnt++;
            }else{
                // in this case curr i value is not equal num, this will reduce the chance of curr choosen num of becomming majority
                // so we will reduce the cnt;
                cnt--;
            }
        }
        
        // here you need not check the count of num in nums
        // as the number slected in num is the max occurring number 
        // since iterating through the array no other number was able to cancel 
        // the chance of being majority of this number
        
        return num;
    }
};