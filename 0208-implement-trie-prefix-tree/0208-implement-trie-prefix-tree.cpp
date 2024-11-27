class Trie {
public:
   
    struct TrieNode{
        bool isEndOfWord;
        TrieNode* children[26];
    };
    TrieNode* getNode(){
        TrieNode* newNode = new TrieNode();
        newNode->isEndOfWord = false;
        
        for(int i=0;i<26;i++)
        {
        newNode->children[i] = NULL;
        }
        return newNode;
    }
    TrieNode* root;
    Trie() {
        root = getNode();
    }
    
    void insert(string word) { //apple
        TrieNode* solve = root;
        
        for(int i=0;i<word.length();i++)
        {
            char ch = word[i];
            int idx = ch-'a';
            
            if(solve->children[idx]==NULL)
            {
                solve->children[idx] = getNode();//'a'
            }
            solve = solve->children[idx];
        }
        solve->isEndOfWord = true; //'e'
    }
    
    bool search(string word) {
         TrieNode* solve = root;
        
        for(int i=0;i<word.length();i++)
        {
            char ch = word[i];
            int idx = ch-'a';
            
            if(solve->children[idx]==NULL)
            {
               return false;
            }
            solve = solve->children[idx];
        }
        if(solve!=NULL && solve->isEndOfWord==true)
            return true;
        
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *solve = root;
        int i = 0;
        for (i = 0; i < prefix.length(); i++) { 
            int idx = prefix[i] - 'a'; 
            
            if (!solve->children[idx]) 
                return false; 
            
            solve = solve->children[idx]; 
        }
        if(i==prefix.length())
            return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */