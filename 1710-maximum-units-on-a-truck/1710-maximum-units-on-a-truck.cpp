class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int ans=0;
        for(int i=0;i<boxTypes.size() && truckSize > 0;i++){
            if(boxTypes[i][0] < truckSize){
                int box_cnt = boxTypes[i][0] * boxTypes[i][1];
                ans += box_cnt;
                truckSize -= boxTypes[i][0];
            }else{
                int box_cnt = truckSize * boxTypes[i][1]; 
                ans += box_cnt;
                truckSize -= boxTypes[i][0];
            }
        }
        return ans;
    }
    
    bool static compare(vector<int> a,vector<int> b){
        return a[1] > b[1];
    }
    
};