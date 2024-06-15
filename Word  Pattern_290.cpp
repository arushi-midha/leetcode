/*
13 june 2024
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream iss(s);
        while(iss>>word){
            words.push_back(word);
        }
        
        if(pattern.length()!=words.size()){
            return false;
        }

        map<char, string> m;
        map<string, char> n;
        for(int i=0;i<pattern.size();i++){
            if(m.count(pattern[i])&& m[pattern[i]]!=words[i])return false;
            if(n.count(words[i])&& n[words[i]]!=pattern[i])return false;
            m[pattern[i]]=words[i];
            n[words[i]]=pattern[i];
            
        }
        return true;
    }
};

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream iss(s);
        while(iss>>word){
            words.push_back(word);
        }
        
        if(pattern.length()!=words.size()){
            return false;
        }

        map<char, string> m;
        set<string> st;
        for(int i=0;i<pattern.size();i++){
            if(m.count(pattern[i])){
                if(m[pattern[i]]!=words[i]){
                    return false;
                }
            }
            else{
                if(st.count(words[i])>0){
                    return false;
                }
                m[pattern[i]]=words[i];
                st.insert(words[i]);
            }
        }
        return true;
    }
};