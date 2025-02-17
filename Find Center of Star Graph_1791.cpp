/*
27 june 2024
There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

 

Example 1:


Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
Example 2:

Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1
 

Constraints:

3 <= n <= 105
edges.length == n - 1
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
The given edges represent a valid star graph.
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> freq;
        for(int i=0;i<edges.size();i++){
            freq[edges[i][0]]++;
            freq[edges[i][1]]++;
        }
        int ans=0;
        int maxfreq=0;
        for(auto i:freq){
            if(i.second>=maxfreq){
                maxfreq=i.second;
                ans=i.first;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> freq(n+1);
        for(int i=0;i<edges.size();i++){
            freq[edges[i][0]-1]++;
            freq[edges[i][1]-1]++;
        }
        int ans=0;
        int maxfreq=0;
        for(int i=0;i<freq.size();i++){
            if(freq[i]>=maxfreq){
                maxfreq=freq[i];
                ans=i+1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0]==edges[1][0] or edges[0][0]==edges[1][1]){
            return edges[0][0];
        }
        else{
            return edges[0][1];
        }
    }
};