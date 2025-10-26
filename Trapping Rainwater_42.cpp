Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105


//monotonic stack solution
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        s.push(0);
        int water=0;
        for(int i=1;i<height.size();i++){
            while(!s.empty() && height[i]>height[s.top()]){
                int t=s.top();
                s.pop();
                if(s.empty())break;
                int l=s.top();
                
                int width=i-l-1;
                int h=min(height[i],height[l])-height[t];
                water+=width*h;
            }
            s.push(i);
        }
        return water;
    }
};


//BRUTE FORCE
class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;
        
        for(int i=0;i<height.size();i++){
            int leftb=0;
            int rightb=0;
            for(int l=i;l>=0;l--){leftb=max(leftb,height[l]);}
            for(int r=i;r<height.size();r++){rightb=max(rightb,height[r]);}
            water+=min(leftb,rightb)-height[i];

        }
        return water;

    }
};









//PRECOMPUTED LEFT AND RIGHT MAXIMUMS
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftb(n);
        vector<int> rightb(n);
        int left=0;
        int right=0;
        leftb[0]=height[0];
        for(int i=1;i<n;i++){
            leftb[i]=max(leftb[i-1],height[i]);
            
        }
        rightb[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightb[i]=max(rightb[i+1],height[i]);
            
        }
        int water=0;
        for(int i=0;i<n;i++){
            water+=min(leftb[i],rightb[i])-height[i];
        }
        return water;
    }
};

//TWO POINTERS

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int leftmax=0; int rightmax=0;
        int water=0;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>leftmax){
                    leftmax=height[left];
                }
                else{
                    water+=leftmax-height[left];
                }
                left++;
            }
            else{
                if(height[right]>rightmax){
                    rightmax=height[right];
                }
                else{
                    water+=rightmax-height[right];
                }
                right--;
            }
        }
        return water;
    }
};