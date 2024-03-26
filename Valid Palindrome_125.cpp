/*
26-3-24

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/


class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int i=0;
        int k=0;
        int j=n-1;
    
        while(i<j){
            if(!isalnum(s[i])){
                i++;
            }
            if(!isalnum(s[j])){
                j--;
            }
            if(isalnum(s[i]) and isalnum(s[j])){
                
                if(tolower(s[i])!=tolower(s[j])){
                    cout<<i<<" "<<j<<endl;
                    cout<<s[i]<<" "<<s[j];
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
};