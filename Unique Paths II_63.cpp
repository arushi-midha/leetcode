You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.

class Solution {
public:
    int move(int up, int left,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(dp[up][left])return dp[up][left];
        if(grid[up][left]==1)return 0;
        if(up==0 and left==0){
            return 1;
        }
        
        int u=0,l=0;
        if(up>0)u=move(up-1,left,grid,dp);
        if(left>0)l=move(up,left-1,grid,dp);
        return dp[up][left]=u+l;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int res=0;
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        res=move(n-1,m-1,obstacleGrid,dp);
        return res;
    }
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0]=1;
        if(m==1 and n==1 and obstacleGrid[0][0]==1)return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0 and obstacleGrid[i][j]!=1){
                    dp[i][j]=1;
                }
                else{
                    if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                int u=0;
                if(i>0){
                    u=dp[i-1][j];
                }
                int l=0;
                if(j>0){
                    l=dp[i][j-1];
                }
                dp[i][j]=u+l;
                

                }
            }
        }
        return dp[n-1][m-1];
    }
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<int> prev(m,0);
        for(int i=0;i<m;i++){
            if(obstacleGrid[0][i]!=1){
                prev[i]=1;
            }
            else{
                break;
            }
        }

        for(int i=1;i<n;i++){
            vector<int> temp(m,0);
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]!=1){
                    if(j>0){
                        temp[j]+=temp[j-1];
                    }if(i>0){
                        temp[j]+=prev[j];
                    }
                    
                }
            }
            prev=temp;
        }
        return prev[m-1];
    }
};