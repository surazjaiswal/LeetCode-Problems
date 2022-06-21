class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> nums;
        for(int i=1;i<=n;i++)
            nums.push_back(i);
        
        sort(nums.begin(),nums.end(),compare);
        return nums;
    }
    
    bool static compare(int a, int b){
        string str_a = to_string(a);
        string str_b = to_string(b);
        
        return str_a < str_b;
    }
};