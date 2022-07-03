class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg;
        for(int i : nums){
            if(i<0)
                neg.push_back(i);
            else 
                pos.push_back(i);
        }
        
        vector<int> ans;
        int i=0,j=0;
        while(i<pos.size() && j<neg.size()){
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }

        return ans;
    }
};