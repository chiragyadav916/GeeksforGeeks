//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int editDistance(string word1, string word2) {
        // Code here
        int n1 = word1.size(),n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0)) ;

        for(int i=0; i<=n1; i++) dp[i][0] = i;
        for(int i=0; i<=n2; i++) dp[0][i] = i;

        for(int i=1; i<=n1; i++)
            for(int j=1; j<=n2; j++)
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            
        return dp[n1][n2];
    }
};




//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends