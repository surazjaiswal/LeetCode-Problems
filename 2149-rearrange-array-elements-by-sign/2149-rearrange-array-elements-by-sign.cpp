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
        int i=0; // size of both pos and neg is same, given equal number of positives and negatives
        while(i<pos.size()){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
            i++;
        }

        return ans;
    }
};