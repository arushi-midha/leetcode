/*
9 june 2024
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int i=n-1;
        int j=i-1;
        bool flag=false;
        if(n==1)return true;
        while(j>=0){
            if(nums[j]>=i-j){
                i=j;
                j=i-1;
                flag=true;
            }
            else{
                j--;
                flag=false;
            }
        }
        if(j<0 && flag==false){
            return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach=0;
        for(int i=0;i<nums.size();i++){
            if(i>reach)return false;
            reach=max(i+nums[i],reach);
            
        }
        return true;
    }
};