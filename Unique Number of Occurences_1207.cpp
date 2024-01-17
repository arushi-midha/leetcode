/*
-------17/1/24-------

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int count=1;
        vector<int> occurences;
        for(int i=1;i<n;i++){
            if(arr[i-1]==arr[i]){
                count++;
            }
            else{
                occurences.push_back(count);
                count=1;
            }
        }
        occurences.push_back(count);

        int l=occurences.size();
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                if(occurences[i]==occurences[j] && i!=j){
                    return false;
                }
            }
        }
        return true;
    }
};