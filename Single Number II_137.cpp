/*
31-5-24
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        int bits[32]={0};
        for(int num:nums){
            for(int i=0;i<32;i++){
                if(num & (1<<i)){
                    bits[i]++;
                }
            }
        }

        for(int i=0;i<32;i++){
            if(bits[i]%3!=0){
                ans|=(1<<i);
            }
        }
        return ans;
    }
};