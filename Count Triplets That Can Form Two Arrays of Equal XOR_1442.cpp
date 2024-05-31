/*
30-5-24
Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.

 

Example 1:

Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
Example 2:

Input: arr = [1,1,1,1,1]
Output: 10
 

Constraints:

1 <= arr.length <= 300
1 <= arr[i] <= 108

*/
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        vector<int> prefix(n+1);
        for(int i=0;i<n;i++){
            prefix[i+1]^=prefix[i]^arr[i];
        }

        for(int j=0;j<n+1;j++){
            for(int k=j+1;k<n+1;k++){
                if(prefix[j]==prefix[k]){
                    count+=k-j-1;
                }
            }
        }
        return count;
    }
};