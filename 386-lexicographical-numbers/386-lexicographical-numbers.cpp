class Node{
    public:
    int num;
    map<int,Node*> children;
    bool isTerminal;
    Node(int num){
        this->num = num;
    }
};

class Trie{
    public:
    Node *root;
    
    Trie(){
        root = new Node(0);
    }
    
    void insert(int num){
        Node *temp = root;
        vector<int> digit;
        while(num){
            int r = num%10;
            digit.push_back(r);
            num /= 10;
        }
        for(int i=digit.size()-1;i>=0;i--){
            int n = digit[i];
            if(temp->children.count(n)){
                temp = temp->children[n];
            }else{
                temp->children[n] = new Node(n);
                temp = temp->children[n];
            }
        }
        temp->isTerminal = true;
    }
    
    vector<int> getNums(){
        vector<int> ans;
        int num=0;
        dfs_helper(root,ans,num);
        return ans;
    }
    
    void dfs_helper(Node *root,vector<int> &ans,int &num){
        for(auto it : root->children){
            num = num*10 + it.first;
            if(it.second->isTerminal)
                ans.push_back(num);
            dfs_helper(it.second,ans,num);
            num /= 10;
        }
    }
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        Trie T;
        for(int i=1;i<=n;i++)
            T.insert(i);
        
        return T.getNums();
    }
};