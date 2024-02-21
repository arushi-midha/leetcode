/*
21/2/24

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mymap;
        for(int i=0;i<nums.size();i++){
            mymap[nums[i]]++;
        }
        int max_count=0;
        int element=-1;
        for(auto x:mymap){
            if(x.second>max_count){
                max_count=x.second;
                element=x.first;
            }
        }
        return element;
    }
};

/*
less optimal solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};
*/

/*
---------------USING MOORE VOTING ALGORITHM----------------
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=0;
        for(int num:nums){
            if(count==0){
                candidate=num;
            }

            if(num==candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};
*/