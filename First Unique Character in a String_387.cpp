/*
--------9/2/24-------

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26);
        int n=s.length();
        for(int i=0;i<n;i++){
            freq[s[i]-97]+=1;
        }
        for(int i=0;i<n;i++){
            if(freq[s[i]-97]==1){
                return i;
            }
        }

        for(int i=0; i<26;i++){
            cout<<freq[i]<<" ";
        }
        return -1;
    }
};

/*class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26);
        int n=s.length();
        for(int i=0;i<n;i++){
            freq[s[i]-97]+=1;
        }
        for(int i=0;i<n;i++){
            if(freq[s[i]-97]==1){
                return i;
            }
        }

        for(int i=0; i<26;i++){
            cout<<freq[i]<<" ";
        }
        return -1;

        unordered_map<char,int> mymap;

        for(char c:s){
            mymap[c]++;
        }
        for(int i=0;i<s.length();i++){
            if(mymap[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};*/
