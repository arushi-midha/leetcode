/*
27 june 2024
456. Maximum Number of Vowels in a Substring of Given Length
Solved
Medium
Topics
Companies
Hint
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length
*/

class Solution {
public:
    int maxVowels(string s, int k) {
        int vowelcount=0;
        int j=0;
        int i;
        for(i=0;i<k;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                vowelcount++;
            }
        }
        int ans=vowelcount;

        for(i=k;i<s.length();i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                vowelcount++;
            }
            if(s[i-k]=='a' or s[i-k]=='e' or s[i-k]=='i' or s[i-k]=='o' or s[i-k]=='u'){
                vowelcount--;
            }
            ans=max(ans,vowelcount);
        }
        return ans;
    }
};