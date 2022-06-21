class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> nums;
        traverse(1,n,nums);
        return nums;
    }
    
    // draw the recursive to understand better
    void traverse(int i,int n,vector<int> &nums){
        if(i > n)
            return;
        nums.push_back(i);
        traverse(i*10,n,nums);
        if(i % 10 != 9)
            traverse(i+1,n,nums);
    }
};