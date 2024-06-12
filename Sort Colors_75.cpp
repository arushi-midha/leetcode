/*
14-5-23

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3);
        
        for(int n:nums){
            count[n]++;
        }
        int k=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<count[i];j++){
                nums[k]=i;
                k++;
            }
        }
        
        




    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3);
        vector<int> og;
        for(int n:nums){
            count[n]++;
            og.push_back(n);
        }
        for(int i=1;i<3;i++){
            count[i]=count[i-1]+count[i];
        }
        int n=og.size();
        for(int i=n-1;i>-1;i--){
            int x=count[og[i]]-1;
            count[og[i]]--;
            nums[x]=og[i];
        }




    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int iter=0;
        while(iter<=end){
            if(nums[iter]==0){
                swap(nums[iter],nums[start]);
                iter++;
                start++;
            }
            else if(nums[iter]==2){
                swap(nums[iter],nums[end]);
                end--;
            }
            else{
                iter++;
            }
        }
    }
};