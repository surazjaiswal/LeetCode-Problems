class Solution {
public:
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
vector<double> ans;
map<pair<string,string>,double> mp;
map<string,bool> mp_chk;
for(int i=0;i<equations.size();i++){
string a = equations[i][0];
string b = equations[i][1];
mp[{a,b}] = values[i];
mp_chk[a]=true;
mp_chk[b]=true;
}
for(auto q : queries){
string a = q[0];
string b = q[1];
if(!mp_chk[a] || !mp_chk[b]){
ans.push_back(-1.0);
}else{
double x = mp[{a,b}];
ans.push_back(x);
}
}
return ans;
}
};