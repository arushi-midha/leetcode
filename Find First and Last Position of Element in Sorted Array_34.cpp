/*
-------16/1/24-------

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

/*class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        int first=10000000;
        int last=0;
        int count=0;

        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                count++;
                first=min(first,i);
                last=max(last,i);
            }

        }
        if (count>0){
            ans[0]=first;
            ans[1]=last;
        }
        
        
        return ans;
    }
};*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first=-1;
        int last=-1;

        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                first=i;
                break;
            }

        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==target){
                last=i;
                break;
            }
        }

        ans.push_back(first);
        ans.push_back(last);
        
        
        return ans;
    }
};