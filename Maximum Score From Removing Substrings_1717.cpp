/*
12 july 2024
You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 

Constraints:

1 <= s.length <= 105
1 <= x, y <= 104
s consists of lowercase English letters.
*/

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> stk;
        stk.push(s[0]);
        int score=0;
        if(y>=x){
            for(int i=1;i<s.length();i++){
                
                if(!stk.empty() && s[i]=='a' && stk.top()=='b'){ //substr 'ba'
                    score+=y;
                    stk.pop();
                }
                else{
                    stk.push(s[i]);
                }
                
            }
            string word="";
            while(!stk.empty()){
                word+=stk.top();
                stk.pop();
            }

            int n=word.length();
            if(n>0)stk.push(word[n-1]);
            for(int i=n-2;i>=0;i--){
                
                if(!stk.empty() && word[i]=='b' && stk.top()=='a'){
                    score+=x;
                    stk.pop();
                }
                else{
                    stk.push(word[i]);
                }
                
            }
        }
        else{
            for(int i=1;i<s.length();i++){
                if(!stk.empty() && s[i]=='b' && stk.top()=='a'){
                    score+=x;
                    stk.pop();
                }
                else{
                    stk.push(s[i]);
                }
                
            }
            string word="";
            while(!stk.empty()){
                word+=stk.top();
                stk.pop();
            }

            int n=word.length();
            if(n>0)stk.push(word[n-1]);
            for(int i=n-2;i>=0;i--){
                if(!stk.empty() && word[i]=='a' && stk.top()=='b'){
                    score+=y;
                    stk.pop();
                }
                else{
                    stk.push(word[i]);
                }
                
            }

        }
        return score;
        
    }
};