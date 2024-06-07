/*
7/6/24
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.
*/

class TrieNode{
public:
    bool is_word;
    TrieNode *children[26];

    TrieNode(){
        is_word=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class Trie {
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        int word_len=word.length();
        int k=0;
        TrieNode *cur=root;
        for(int i=0;i<word_len;i++){
            k=word[i]-'a';
            if(cur->children[k]==NULL){
                cur->children[k]=new TrieNode();
            }
            cur=cur->children[k];
        }
        cur->is_word=true;
    }
    
    bool search(string word) {
        int word_len=word.length();
        int k=0;
        TrieNode *cur=root;

        for(int i=0;i<word_len;i++){
            k=word[i]-'a';
            cur=cur->children[k];

            if(cur==NULL){
                return false;
            }
        }
        return cur->is_word;
    }
    
    bool startsWith(string prefix) {
        int word_len=prefix.length();
        int k=0;
        TrieNode *cur=root;

        for(int i=0;i<word_len;i++){
            k=prefix[i]-'a';
            cur=cur->children[k];

            if(cur==NULL){
                return false;
            }
            
        }
        return true;
    }

private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */