Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200

class Solution {
public:
    int move(int up, int left,vector<vector<int>>&grid){
        if(up==0 and left==0){
            
            return grid[0][0];
        }
        int l=INT_MAX,u=INT_MAX;
        if(up<0 || left<0)return INT_MAX;
        if(up>0){
            
            u=grid[up][left]+move(up-1,left,grid);
        }
        if(left>0){
            l=grid[up][left]+move(up,left-1,grid);
        }
        return min(u,l);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int res=0;
        int n=grid.size();
        int m=grid[0].size();
       
        res=move(n-1,m-1,grid);
        return res;
    }
};


class Solution {
public:
    int move(int up, int left,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(dp[up][left])return dp[up][left];
        if(up==0 and left==0){
            
            return grid[0][0];
        }
        int l=INT_MAX,u=INT_MAX;
        if(up<0 || left<0)return INT_MAX;
        if(up>0){
            
            u=grid[up][left]+move(up-1,left,grid,dp);
        }
        if(left>0){
            l=grid[up][left]+move(up,left-1,grid,dp);
        }
        return dp[up][left]=min(u,l);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int res=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
       
        res=move(n-1,m-1,grid,dp);
        return res;
    }
};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0){
                    dp[i][j]=grid[0][0];
                }
                else{
                    int u=INT_MAX,l=INT_MAX;
                if(i>0){
                    u=grid[i][j]+dp[i-1][j];

                }
                if(j>0){
                    l=grid[i][j]+dp[i][j-1];
                }
                dp[i][j]=min(u,l);
 
                }
            }
            
            
        }
        return dp[n-1][m-1];

    }
};