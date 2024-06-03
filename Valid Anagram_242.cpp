/*
4-6-24
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mymap;
        for(int i=0;i<s.length();i++){
            mymap[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            mymap[t[i]]--;
        }
        for(auto item:mymap){
            if(item.second!=0){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26);
        for(char c:s){
            freq[c-'a']++;
        }
        for(char c:t){
            if(freq[c-'a']==0){
                return false;
            }
            freq[c-'a']--;
        }
        for(int c:freq){
            if(c!=0){
            return false;
            }
        }
        return true;
    }
};
