There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.


class Solution {
    public:
        void dfs_iter(int node, vector<vector<int>>&adj,vector<bool>&visited){
            stack<int> s;
            s.push(node);
            visited[node]=true;
    
            while(!s.empty()){
                int n=s.top();
                s.pop();
                cout<<"n  "<<n;
                for(int i=0;i<adj[n].size();i++){
    
                    if(adj[n][i] && !visited[i]){
                        s.push(i);
                        visited[i]=true;
                        
                    }
                }
            }
    
        }
        void dfs(int node, vector<vector<int>>&adj, vector<bool>&visited){
            visited[node]=true;
            for(int i=0;i<adj[node].size();i++){
                if(adj[node][i]==1 && !visited[i]){
                    dfs(i,adj,visited);
                }
            }
            
        }
        int findCircleNum(vector<vector<int>>& isConnected) {
            vector<bool> visited(isConnected.size(),false);
            int count=0;
            for(int i=0;i<visited.size();i++){
                if(!visited[i]){
                    dfs(i,isConnected,visited);
                    count++;
                }
            }
            return count;
        }
    };