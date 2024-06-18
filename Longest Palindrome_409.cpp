/*
4-6-24

Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome
 that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mymap;
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            mymap[s[i]]++;
        }
        int odd=0;
        for(auto item:mymap){
            if(item.second%2==0){
                ans+=item.second;
                cout<<"even freq"<<item.first;
            }
            else{
                ans+=item.second-1;
                odd=1;
            }
        }
        return ans+odd;
    }
};

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> upper(26);
        vector<int> lower(26);
        int ans=0;
        for(char c:s){
            if(c>='a'){
                lower[c-'a']++;
            }
            else{
                upper[c-'A']++;
            }
            
        }
        int odd=0;
        for(int item:lower){
            if(item%2==0){
                ans+=item;
            }
            else{
                ans+=item-1;
                odd=1;
            }
        }
        for(int item:upper){
            if(item%2==0){
                ans+=item;
            }
            else{
                ans+=item-1;
                odd=1;
            }
        }
        return ans+odd;
    }
};