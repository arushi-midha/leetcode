/*
24/4/24

The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537
 

Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
*/

class Solution {
public:
    long long tribonacci(int n) {
        vector<long long> arr;
        int a=0;
        int b=1;
        int c=1;
        int d=0;

        
        if(n==0) return a;
        if(n==1) return b;
        if(n==2) return c;
        
        
        
        for(int i=3;i<n+1;i++){
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        
    
        return d;
    }
};