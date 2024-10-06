//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    // Function to find the number of islands.
    

//   BFS code 


    void bfs(int r,int c,vector<vector<char>> &grid,vector<vector<int>> &vis){
        vis[r][c]=1;
        queue<pair<int,int>> q;
        
        q.push({r,c});
        int n=grid.size();
        int m=grid[0].size();
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            
            q.pop();
            
            for(int delr=-1;delr<=1;delr++){
                for(int delc=-1;delc<=1;delc++){
                    int nrow=delr+row;
                    int ncol=delc+col;
                    
                    if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    

//  DFS code


    void dfs(int r,int c,vector<vector<char>> &grid,vector<vector<int>> &vis){
        vis[r][c]=1;
        
        int n=grid.size();
        int m=grid[0].size();
    
                for(int delr=-1;delr<=1;delr++){
                    for(int delc=-1;delc<=1;delc++){
                        int nrow=delr+r;
                        int ncol=delc+c;
                        
                        if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                            vis[nrow][ncol]=1;
                            dfs(nrow,ncol,grid,vis);
                        }
                    }
                }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                 //   bfs(i,j,grid,vis);
                   dfs(i,j,grid,vis);
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends