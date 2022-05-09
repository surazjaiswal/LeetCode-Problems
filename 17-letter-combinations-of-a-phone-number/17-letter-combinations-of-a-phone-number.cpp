class Solution {
public:
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        
        if(digits.size()==0)
            return {};
        
        char keypad[][10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
        char key[10];
        generate(digits,keypad,key,0,0);
        return ans;      
        
    }
    
    void generate(string digits,char keypad[][10],char key[],int i,int j){
        if(digits[i]=='\0'){
            key[j] = '\0';
            ans.push_back(key);
            return;
        }
        int d = digits[i]-'0';
        for(int k=0;keypad[d][k]!='\0';k++){
            key[j]=keypad[d][k];
            generate(digits,keypad,key,i+1,j+1);
        }
        return;        
    }
};

// ans is in lexicographical order