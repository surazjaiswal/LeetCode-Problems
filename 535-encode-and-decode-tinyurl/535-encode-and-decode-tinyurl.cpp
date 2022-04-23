// characters for generating random chars
vector<char> arr = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
                    'H', 'I', 'J', 'K', 'L', 'M', 'N',
                    'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                    'V', 'W', 'X', 'Y', 'Z',
                    '0','1','2','3','4', '5',
                    '6','7','8','9', 'a', 'b',
                    'c', 'd', 'e', 'f', 'g', 'h', 'i',
                    'j', 'k', 'l', 'm', 'n', 'o', 'p',
                    'q', 'r', 's', 't', 'u', 'v', 'w',
                    'x', 'y', 'z'};

class Solution {
public:
    
    
    int n = arr.size();
    unordered_map<string,string> mp_L2S,mp_S2L; // map for mapping urls to their different versions

    // Encodes a URL to a shortened URL.
    string encode(string longURL) {
        
        // here we generate a 6 char long random string, for converting long url to short
        string res = "";
        for(int i=0;i<6;i++){
            res += arr[rand() % n];
        }

        string shortURL = "http://tinyurl.com/" + res;
        cout<<shortURL<<endl;
        
        mp_L2S[longURL] = shortURL; // longURL --> shortURL
        mp_S2L[shortURL] = longURL; // shortURL --> longURL
        
        
        return  shortURL;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortURL) {
        return  mp_S2L[shortURL];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));