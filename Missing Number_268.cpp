/*
20/2/24
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
 

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
 

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      if(nums[0]!=0){
          return 0;
      }
      int miss;
      for(int i=0;i<nums.size();i++){
          if(i<nums.size()-1 && nums[i+1]-nums[i]==2){
            miss=nums[i]+1;
            break;
          }
          else{
            miss=nums.size();
            
          }
          
      }
      

      return miss;
    }
};

/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n+1);
        int miss;
        for(int i=0;i<n;i++){
            arr[nums[i]]=1;
        }
        for(int i=0;i<n+1;i++){
            if(arr[i]!=1){
                miss=i;
            }
        }
        return miss;
    }
};
*/


/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int total=(n*(n+1))/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        return total-sum;
    }
};
*/