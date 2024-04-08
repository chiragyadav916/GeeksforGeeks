//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    // Your code goes here
	     int M = points.size();
        int N = points[0].size();
        vector<vector<int>> hp(M + 1, vector<int>(N + 1, INT_MAX));
 
        // Base cases: Minimum HP needed at bottom right and rightmost bottom cell is 1
        hp[M][N - 1] = 1;
        hp[M - 1][N] = 1;
 
        // DP loop: Fill the table from bottom right to top left
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                int currentHP = points[i][j]; // Current HP cost of the cell
                int neededHP = min(hp[i + 1][j], hp[i][j + 1]) - currentHP;  // Minimum HP required based on neighbors
 
                // Ensure positive HP: If neededHP is non-positive, set it to 1
                hp[i][j] = neededHP <= 0 ? 1 : neededHP;
            }
        }
 
        return hp[0][0];
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends