/*
-------21/11/23-------
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        int stk[n];
        int top=-1;
        for(int i=0;i<n;i++){
            if (s[i]=='(' or s[i]=='[' or s[i]=='{'){
                top++;
                stk[top]=s[i];
            } 
            if (s[i]==')' or s[i]==']' or s[i]=='}'){
            if(top!=-1){
                if((stk[top]=='(' and s[i]==')') or (stk[top]=='[' and s[i]==']') or (stk[top]=='{' and s[i]=='}')){
                    top--;
                }
                else{
                    return false;
                }      
            }
            else{return false;}
                    
                
                
            }
            
        }
        if(top>-1){
            return false;
        }    
        else{
            return true;
        }
    }
};

class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            for(char c:s){
                if(c=='(' or c=='{' or c=='['){
                    st.push(c);
                }
                else if(!st.empty()){
                    if(st.top()=='(' and c==')'){
                    st.pop();
                    }
                    else if(st.top()=='{' and c=='}'){
                    st.pop();
                    }
                    else if(st.top()=='[' and c==']'){
                    st.pop();
                    }
                    else{
                        return false;
                    }
    
                }
                else{
                    return false;
                }
                
                
    
            }
            if(st.size()==0){
                return true;
    
            }else{
                return false;
            }
        }
    };
