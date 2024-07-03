/*
2 july 2024
Given a 2D integer array nums where nums[i] is a non-empty array of distinct positive integers, return the list of integers that are present in each array of nums sorted in ascending order.
 

Example 1:

Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
Output: [3,4]
Explanation: 
The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] = [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].
Example 2:

Input: nums = [[1,2,3],[4,5,6]]
Output: []
Explanation: 
There does not exist any integer present both in nums[0] and nums[1], so we return an empty list [].
 

Constraints:

1 <= nums.length <= 1000
1 <= sum(nums[i].length) <= 1000
1 <= nums[i][j] <= 1000
All the values of nums[i] are unique.
*/

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int> m1;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                m1[nums[i][j]]++;
            }
        }
        vector<int> ans;
        int n=nums.size();
        for(auto i:m1){
            if(i.second==n){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
