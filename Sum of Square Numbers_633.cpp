/*
17 june daily
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:

Input: c = 3
Output: false
 

Constraints:

0 <= c <= 231 - 1
*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        long start=0;
        long end=(int)sqrt(c);
        while(start<=end){
            long long x=start*start+end*end;
            if(x==c){
                return true;
            }
            else if(x>c){
                end--;
            }
            else{
                start++;
            }
        }
        return false;
    }
};