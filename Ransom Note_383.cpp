/*
28-3-24

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/


//SPACE OPTIMIZED SOLUTION

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        int i=0;
        int j=0;
        int count=0;
        while(j<magazine.length()){
            if(ransomNote[i]==magazine[j]){
                count++;
                i++;
            }
            j++;
        }

        return count==ransomNote.length();

    }
};


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;

        for(int i=0;i<magazine.length();i++){
            m[magazine[i]]++;
        }

        for(int i=0;i<ransomNote.length();i++){
            if(m[ransomNote[i]]>0){
                m[ransomNote[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};