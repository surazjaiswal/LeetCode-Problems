class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(),people.end(),compare);
        
        for(int i=0;i<people.size();i++){
            int place = people[i][1];
            ans.insert(ans.begin() + place,people[i]);
        }
        return ans;
    }
    bool static compare(vector<int> a,vector<int> b){
        return (a[0] > b[0] || (a[0] == b[0] && a[1]<b[1]));
    }
};