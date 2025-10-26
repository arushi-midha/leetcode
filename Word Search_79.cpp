Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?

class Solution {
public:
    bool dfs(vector<vector<char>>&board, int i, int j, int k, string &word){
        if(k==word.size())return true;

        if(i<0||j<0||i>=board.size()||j>=board[0].size() || board[i][j]!=word[k])return false;
        int temp=board[i][j];
        board[i][j]='0';

        bool found=dfs(board,i-1,j,k+1,word) || dfs(board,i+1,j,k+1,word) || dfs(board,i,j-1,k+1,word) || dfs(board,i,j+1,k+1,word);

        board[i][j]=temp;
        return found;
    }

        
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        map<char,int>h;
        for(int i=0;i<n;i++){
            h[word[i]]++;

        }
        //can also prune by stopping the process if any letter in word appears more time in word  than in the grid.
        int l=word.size();
        if(h[word[0]]>h[word[l-1]])reverse(word.begin(),word.end());

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]  && dfs(board, i,j, 0, word))return true;
            }
        }
        return false;
    }
};