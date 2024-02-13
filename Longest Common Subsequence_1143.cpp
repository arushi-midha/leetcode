/*
13/2/24

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length();
        int l2=text2.length();
        //vector<vector<int>> ans (l2+1,vector<int> (l1+1));
        int ans[l2+1][l1+1];

        for(int i=0;i<l2+1;i++){
            for(int j=0;j<l1+1;j++){
                if(i==0 or j==0){
                    ans[i][j]=0;
                }
                else if(text2[i-1]==text1[j-1]){
                    ans[i][j]=1+ans[i-1][j-1];
                }
                else{
                    ans[i][j]=max(ans[i][j-1],ans[i-1][j]);
                }
            }
        }

        /*for(int i=0;i<l2+1;i++){
            for(int j=0;j<l1+1;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }*/

        return ans[l2][l1];
    }
};