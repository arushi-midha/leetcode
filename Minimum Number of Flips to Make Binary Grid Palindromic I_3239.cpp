/*
You are given an m x n binary matrix grid.

A row or column is considered palindromic if its values read the same forward and backward.

You can flip any number of cells in grid from 0 to 1, or from 1 to 0.

Return the minimum number of cells that need to be flipped to make either all rows palindromic or all columns palindromic.

 

Example 1:

Input: grid = [[1,0,0],[0,0,0],[0,0,1]]

Output: 2

Explanation:



Flipping the highlighted cells makes all the rows palindromic.

Example 2:

Input: grid = [[0,1],[0,1],[0,0]]

Output: 1

Explanation:



Flipping the highlighted cell makes all the columns palindromic.

Example 3:

Input: grid = [[1],[0]]

Output: 0

Explanation:

All rows are already palindromic.

 

Constraints:

m == grid.length
n == grid[i].length
1 <= m * n <= 2 * 105
0 <= grid[i][j] <= 1
 */

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==1 or n==1){
            return 0;
        }
        int count1=0;
        for(int i=0;i<m;i++){
            int l=0;
            int r=n-1;
            while(l<=r){
                if(grid[i][l]!=grid[i][r]){
                    count1++;
                }
                l++;
                r--;
            }
        }
        int count2=0;
        for(int i=0;i<n;i++){
            int l=m-1;
            int r=0;
            while(r<=l){
                if(grid[l][i]!=grid[r][i]){
                    count2++;
                }
                r++;
                l--;
            }
        }
        cout<<count1<<endl;
        cout<<count2<<endl;
        return min(count1,count2);
    }
};