class Solution {
public:
    vector<string> bins;
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if(n < k)
            return false;
        
        set<string> st;
        string ss = "";
        int j=0;
        while(j<=n){
            
            if(j<k){                
                ss += s[j];
                j++;
                continue;
            }
            
            st.insert(ss);
            ss.erase(0,1);
            if(j<n)
                ss = ss + s[j];
            j++;    
        }
        
        int bins = pow(2,k);
        if(st.size() == bins)
            return true;
               
        return false;
    }
};