class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // first we will search if the end word is present in the word list
        // and maintain a look up for words in wordlist by maintaining a set
        unordered_set<string> st;
        bool isPresent = false;
        for(string word : wordList){
            if(endWord==word)
                isPresent = true; 
            st.insert(word);
        }
        
        if(isPresent==false){
            // endword not present
            return 0;
        }
        // here we need to maintain queue for words transformed, breadth-first-search
        queue<string> q;
        q.push(beginWord);
        int level=1;
        while(!q.empty()){
            int level_size = q.size(); // size of the current level
            while(level_size--){
                string word = q.front(); 
                q.pop();
                for(int i=0;i<word.size();i++){
                    // now here we will transform word by changing every char one by one
                    // and check its presence in the wordList
                    // if present then this implies that current word can lead to endWord
                    // then add it to the queue
                    string temp_word=word;
                    for(char ch='a';ch<='z';ch++){
                        temp_word[i]=ch;
                        if(word.compare(temp_word)==0){
                            // if the transformed word is same as current choosen word 
                            continue;
                        }
                        if(temp_word.compare(endWord)==0){
                            // check if transformed word is equal to end word or not
                            return level+1;
                        }   
                        // now check if the transformed word is present in the wordList or not
                        // if present push it into the queue;
                        if(st.count(temp_word)){
                            q.push(temp_word);
                            st.erase(temp_word);
                        }
                    }
                }
            }
            level++; // moving to next level
        }
        return 0;
    }
};