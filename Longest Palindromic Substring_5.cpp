Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

class Solution {
public:
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans="";
        int max_l=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(s,i,j)){
                    if(j-i+1>max_l){
                        max_l=j-i+1;
                        ans=s.substr(i,j-i+1);
                    }
                }
                
            }
        }
        return ans;
    }
};

//dp
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        vector<int> ans(2);
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                ans={i,i+1};
            }
        }

        for(int length=2;length<n;length++){
            for(int i=0;i<n-length;i++){
                int j=i+length;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    ans={i,j};
                }
            }

        }
        return s.substr(ans[0],ans[1]-ans[0]+1);
    }
};


class Solution {
public:
    string expand(string &s, int i, int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            string odd=expand(s,i,i);
            if(odd.size()>ans.size()){
                ans=odd;
            }

            string even=expand(s,i,i+1);
            if(even.size() >ans.size()){
                ans=even;
            }
        }
        return ans;
    }
};