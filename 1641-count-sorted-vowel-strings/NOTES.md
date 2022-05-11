```
class Solution {
public:
vector<string> ans;
int countVowelStrings(int n) {
vector<string> vowels = {"a","e","i","o","u"};
getVowels(vowels,0,0,n,"");
cout<<endl;
return ans.size();
}
void getVowels(vector<string> &vowels,int cnt,int j,int n,string str){
if(cnt > n){
return;
}
if(cnt == n && str.length() == n){
// cout<<str<<" ";
ans.push_back(str);
return;
}
for(int i=j;i<vowels.size();i++){
str += vowels[i];
getVowels(vowels,cnt+1,i,n,str);
str.pop_back();
}
}
};
```