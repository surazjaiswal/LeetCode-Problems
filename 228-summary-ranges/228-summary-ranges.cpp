class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++)
        {
            int a = nums[i];
            while ((i + 1 < n) && (nums[i] + 1 == nums[i + 1]))
            {
                i++;
            }
            int b = nums[i];
            ans.push_back({a, b});
        }
        vector<string> str_ans;
        for (auto it : ans)
        {
            if (it.first != it.second){
                // cout << it.first << "->" << it.second << " ";
                str_ans.push_back(to_string(it.first) + "->" + to_string(it.second));
            }
            else{
                // cout << it.first << " ";
                str_ans.push_back(to_string(it.first));
            }
        }
        return str_ans;
    }
};