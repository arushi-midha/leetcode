/*
-------22/1/24-------

An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

 

Example 1:

Input: nums = [1,2,2,3]
Output: true
Example 2:

Input: nums = [6,5,4,4]
Output: true
Example 3:

Input: nums = [1,3,2]
Output: false
 

Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105
*/

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag1;
        bool flag2;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=nums[i-1]){
                flag1=true;
            }
            else{
                flag1=false;
                break;
            }
        }

        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                flag2=true;
            }
            else{
                flag2=false;
                break;
            }
        }
        return flag1 or flag2;
    }
};

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag1=true;
        bool flag2=true;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                flag1=false;
            }
            if(nums[i]<nums[i-1]){
                flag2=false;
            }
            if(flag1==false && flag2==false){
                return false;
            }

        }
        return flag1 or flag2;
    }
};