/*
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

class Solution {
public:
        string minWindow(string s, string t) {
        unordered_map<char, int> letters; //unordered map for storing the characters in t that we need to check for in s
        for(auto c : t) letters[c]++; 
        int count = 0; //counts number of t's letters in current window
        int low = 0, min_length = INT_MAX, min_start = 0;     
        for(int high = 0; high<s.length(); high++) {
            if(letters[s[high]] > 0) count++; //means that this letter is in t   
            letters[s[high]]--; //reduce the count for the letter on which we are currently 
            if(count == t.length()) { //if current windows contains all of the letters in t
                while(low < high && letters[s[low]] < 0) letters[s[low]]++, low++; //move low ahead if its not of any significance
                if(min_length > high-low) min_length = high-(min_start=low)+1; //update the min length
                letters[s[low++]]++; //move low ahaead and also increment the value
                count--; //count-- as we are moving low ahead & low pointed to a char in t before
            }
        }
        return min_length == INT_MAX ? "" : s.substr(min_start, min_length); //check for edge case & return the result
    }
};