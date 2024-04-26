//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        int i=0,ni=0,j=0,nj=1;
        char currDir='R';
        vector<int> ans(2);
        while(i<n and j<m and i>=0 and j>=0){
            if(matrix[i][j]){
                matrix[i][j]=0;
                switch(currDir){
                    case 'R': currDir='D'; ni=1,nj=0; break;
                    case 'L': currDir='U'; ni=-1,nj=0; break;
                    case 'D': currDir='L'; ni=0,nj=-1; break;
                    case 'U': currDir='R'; ni=0,nj=1; break;
                }
            }
            ans[0]=i,ans[1]=j;
            i+=ni,j+=nj;
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
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends