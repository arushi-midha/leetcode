/*
27-3-24

Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Example 2:

Input: nums = [1,2,3], k = 0
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106
*/

/*
ABSOLUTE BRUTE FORCE SHIT ASS SOLUTION BECAUSE BRAIN WASNT WORKING

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long int product;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            product=1;
            for(int j=i;j<n;j++){
                //if(nums[i]<k) count++;
                product*=nums[j];
                if(product<k && product!=0){
                    count++;
                }
                else if(product>k){
                    break;
                }
            }
        }
        return count;
    }
};*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int product=1;
        int n=nums.size();
        int count=0;
        for(int i=0, j=0;j<n;j++){
            product*=nums[j];
            while(i<=j && product>=k){
                product/=nums[i];
                i++;
            }
            count+=j-i+1;
            
        }
        return count;
    }
};