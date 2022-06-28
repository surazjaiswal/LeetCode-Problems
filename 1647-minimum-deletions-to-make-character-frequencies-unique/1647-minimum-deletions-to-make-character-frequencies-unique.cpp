class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(char c : s)
            freq[c-'a']++;
        
        int cnt = 0;
        sort(freq.begin(),freq.end());
        set<int> st;
        // st.insert(freq[25]);
        int i=25;
        while(i >= 0 && freq[i] != 0){
            int fq = freq[i];
            if(st.count(fq) == 0){
                st.insert(fq);
            }else{
                while(st.count(fq)!=0){
                    fq--;
                    cnt++;
                }
                if(fq != 0)
                    st.insert(fq);
            }
            i--;
        }
        
        // for(int i : st)
        //     cout<<i<<" ";
        
        return cnt;
    }
};