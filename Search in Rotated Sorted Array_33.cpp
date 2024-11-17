/*
21 june 2024
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
*/

class Solution {
public:

    int bs(int target, int start, int end, vector<int> &nums){
        int s=start;
        int e=end;
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[m]==target){
                return m;
            }
            else if(nums[m]<target){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int n=nums.size();
        int mindex=-1;
        while(start<=end){
            if(nums[start]<=nums[end]){
                mindex=start;
                break;
            }
            int mid=start+((end-start)/2);

            if(nums[mid]<=nums[(mid+1)%n] && nums[mid]<=nums[(mid-1+n)%n]){
                mindex=mid;
                break;
            }

            if(nums[start]<=nums[mid]){
                start=mid+1;
            }
            else if(nums[mid]<=nums[end]){
                end=mid-1;
            }

        }
        start=0;
        end=nums.size()-1;
        int x1=bs(target, start, mindex-1,nums);
        int x2=bs(target, mindex, end, nums);
        cout<<x1<<" "<<x2;
        if(x1!=-1){
            return x1;
        }
        else if(x2!=-1){
            return x2;
        }
        return -1;
        
        
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int bs(vector<int>&nums, int low, int high, int key){
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==key){
                return mid;
            }
            else if(nums[mid]>key){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }

    int find_start(vector<int>&nums, int low, int high){
        
        while(low<=high){
            if(nums[low]<=nums[high]){
                return low;
            }
            int mid=low+(high-low)/2;
            int n=nums.size();
            
            int next=(mid+1)%n;
            int prev=(mid-1+n)%n;
            if(nums[mid]<nums[prev] && nums[mid]<nums[next]){
                return mid;
            }
            
            if(nums[mid]>=nums[low]){
                    low=mid+1;
            }
            else if(nums[mid]<=nums[high]){
                    high=mid-1;
            }
            
        }
        return low;
    }
    int search(vector<int>& nums, int target) {
        int min_index=find_start(nums,0,nums.size()-1);
        int ans1=bs(nums,0,min_index-1,target);
        int ans2=bs(nums,min_index,nums.size()-1,target);
        if(ans1!=-1){
            return ans1;

        }else{
            return ans2;
        }
    }
};