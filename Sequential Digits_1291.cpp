/*
--------3/2/24--------
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        char str[]="123456789";
        int val=0;
        for(int win=2;win<10;win++){
            for(int index=0;index<10-win;index++){
                val=0;
                for(int i=0;i<win;i++){
                    val+=(str[index+i]-'0')*pow(10,win-i-1);
                }
                ans.push_back(val);
            }
        }
        vector<int> finalans;
        int size=ans.size();
        for(int i=0;i<size;i++){
            if(ans[i]>=low &&ans[i]<=high){
                finalans.push_back(ans[i]);
            }
        }
     
        return finalans;
    }
};