/*
-------23/1/24-------

You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
 

Constraints:

2 <= nums.length <= 104
1 <= nums[i] <= 104

*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int index;
        
        sort(nums.begin(),nums.end());
        int asum=nums[0];
        for(int i=1;i<n;i++){
            asum+=nums[i];
            if(nums[i]==nums[i-1]){
                ans.push_back(nums[i]);
                index=i;
            }
        }
        
        int sum=(n*(n+1))/2;
        cout<<sum;
        cout<<asum;
        int x=sum-(asum-nums[index]);
        ans.push_back(x);
        
        return ans;
    }
};