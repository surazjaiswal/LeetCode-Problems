// class compare{
//     bool operator()(string a, string b){
//         return a.length() > b.length();
//     }
// };

class Solution {
    unordered_set<string> s;
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        vector<string> ans;
        for(auto word : words){
            if(s.find(word)!=s.end()){
                continue;
            }
            ans.push_back(word);
            for(int i=word.size()-1;i>=0;i--){
                string t = word.substr(i);
                s.insert(t);
            }
        }
        int res=0;
        for(auto word:ans){
            res += word.size();
        }
        return res + ans.size();
    }
    
    bool static compare(string a, string b){
        return a.length() > b.length();
    }
};