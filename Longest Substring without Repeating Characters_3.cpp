Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> uniq;
        int i=0;
        int j=0;
        int len=0;
        while(j<s.length() && i<=j){
            if(uniq.find(s[j])!=uniq.end()){
                if(s[i]==s[j]){
                    uniq.erase(s[i]);
                    i++;
                }else{
                    while(s[i]!=s[j]){
                    uniq.erase(s[i]);
                    i++;
                }
                }
                
                

            }else{
            uniq.insert(s[j]);
            j++;
            len=max(j-i,len);
            }
            
        }
        
        return len;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int ans=0;
        set<char> uniq;
        for(int j=0;j<s.length();j++){
            if(uniq.find(s[j])!=uniq.end()){
                while(i<j && s[i]!=s[j]){
                    uniq.erase(s[i]);
                    i++;
                }
                uniq.erase(s[i]);
                i++;
            }
            uniq.insert(s[j]);
            ans=max(ans,j-i+1);

        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256,-1);
        int l=0;
        int r=0;
        int len=0;
        while(r<s.length()){
            if(mp[s[r]]!=-1){
                l=max(mp[s[r]]+1,l);

            }
            mp[s[r]]=r;
            len=max(len,r-l+1);
            r++;


        }
        return len;

    }
};