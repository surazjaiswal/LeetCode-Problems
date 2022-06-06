class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int sz=INT_MAX;
        map<int,vector<string>> mp;
        
        for(int i=0;i<list1.size();i++){
            for(int j=0;j<list2.size();j++){
                if(list1[i] == list2[j]){
                    sz = min(sz,i+j);
                    mp[i+j].push_back(list1[i]);
                }
            }
        }
        
        return mp[sz];
    }
};