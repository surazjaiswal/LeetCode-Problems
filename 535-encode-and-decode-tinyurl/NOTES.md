// Encodes a URL to a shortened URL.
string encode(string longURL) {
// here we generate a 6 char long random string, for converting long url to short
string res = "";
for(int i=0;i<6;i++){
res += arr[rand() % n];
}
​
string shortURL = "http://tinyurl.com/" + res;
cout<<shortURL<<endl;
mp_L2S[longURL] = shortURL; // longURL --> shortURL
mp_S2L[shortURL] = longURL; // shortURL --> longURL
return  shortURL;
}
​
// Decodes a shortened URL to its original URL.
string decode(string shortURL) {
return  mp_S2L[shortURL];
}
};
​
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
```