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

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int first=-1;
        int last=-1;
        while(start<=end){
            int mid=start+((end-start)/2);
            if(nums[mid]==target){
                first=mid;
                end=mid-1;
            }else if(nums[mid]>target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        start=0;
        end=nums.size()-1;
        while(start<=end){
            int mid=start+((end-start)/2);
            if(nums[mid]==target){
                last=mid;
                start=mid+1;
            }else if(nums[mid]>target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return {first,last};

    }
};

class Solution {
public:
    int find(vector<int>&nums,int low, int high, int target, int i){
        int res=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                res=mid;
                if(i==1){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        ans[0]=find(nums,0,nums.size()-1,target,1);
        ans[1]=find(nums,0,nums.size()-1,target,2);
        return ans;
    }
};