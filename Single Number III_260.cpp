/*
31-5-24

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
 

Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.
*/


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int result=0;
        vector<int> ans(2);
        for(int num:nums){
            result^=num;
        }
        int temp=result;
        int position=0;;
        for(int i=0;i<32;i++){
            if(result & (1<<i)){
                position=i;
                break;
            }
        }
        int num1=0;
        int num2=0;
        for(int num:nums){
            if(num & (1<<position)){
                num1^=num;
            }
            else{
                num2^=num;
            }
        }
        
        
        
        return {num1,num2};
    }
};