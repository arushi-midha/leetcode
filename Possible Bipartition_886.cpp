We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: The first group has [1,4], and the second group has [2,3].
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
 

Constraints:

1 <= n <= 2000
0 <= dislikes.length <= 104
dislikes[i].length == 2
1 <= ai < bi <= n
All the pairs of dislikes are unique.


class Solution {
    public:
        bool dfs(int node, unordered_map<int, vector<int>>&graph,int c, vector<int>&color){
            color[node]=c;
            for(auto&i:graph[node]){
                if(color[i]==-1){
                    if(!dfs(i,graph,1-c, color))return false;
                }
                else if(color[i]==color[node]){
                    return false;
                }
            }
            return true;
        }
        
        bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
            
            int s=dislikes.size();
            unordered_map<int, vector<int>> h;
            vector<int>color(n+1,-1);
            for(int i=0;i<s;i++){
                h[dislikes[i][0]].push_back(dislikes[i][1]);
                h[dislikes[i][1]].push_back(dislikes[i][0]);
            }
    
            for(int i=0;i<n;i++){
                if(color[i]==-1){
                    if(!dfs(i,h,0,color))return false;
                }
            }
            return true;
    
        }
    };