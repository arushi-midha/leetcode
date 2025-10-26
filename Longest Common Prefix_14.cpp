Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string check=strs[0];
        
        for(string s:strs){
            int i=0;
            int j=0;
            string newcheck="";
            while(i<s.length() && j<check.length() && s[i]==check[j]){
                newcheck+=s[i];
                i++;
                j++;
                
            }
            check=newcheck;
        }
        return check;
    }
};