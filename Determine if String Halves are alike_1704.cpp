/*
-------13/1/24--------

You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

 

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
 

Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.
*/

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        int count1=0;
        int count2=0;
        for(int i=0;i<n/2;i++){
            if(checkvowels(s[i])) count1++;
            }
        

        for(int i=n/2;i<n;i++){
            if(checkvowels(s[i])) count2++;
        }

        return count1==count2;
    }

    bool checkvowels(char c){
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or c=='A' or c=='E' or c=='I' or c=='O' or c=='U'){
            return true;
        }
        else{ return false;}
    }
};