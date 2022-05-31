class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        
        if(n < k)
            return false;
        
        int bins = 1<<k;
        
        set<string> st;
        for(int i=k;i <= n;i++){
            string ss = s.substr(i-k,k);
            st.insert(ss);
            if(st.size() == bins)
                return true;
        }
        
        return false;
    }
};