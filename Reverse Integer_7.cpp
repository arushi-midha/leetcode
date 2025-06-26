/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1
*/
class Solution {
public:
    int reverse(int x) {
        bool negative=false;
        if(x==0){
            return 0;
        }
        else if(x<0){
            negative=true;
        }
        if(x+pow(2,31)==0){
            return 0;
        }
        x=abs(x);
        int rev=0;
        while(x>0){
            if((pow(2,31)-1)/rev<10){
                return 0;
            }
            else{
                rev*=10;
            }
            int c=x%10;
            x=x/10;
            rev+=c;
        }
        if(negative){
            rev*=-1;
        }
        return rev;
    }
};

//better solution

#include <iostream>
using namespace std;

int reverse(int x) {
    int rev = 0;

    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        // Check for overflow before multiplying by 10
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) return 0;

        rev = rev * 10 + digit;
    }

    return rev;
}

int main() {
    int x;
    cout << "Enter number: ";
    cin >> x;

    cout << "Reversed: " << reverse(x) << endl;
    return 0;
}


