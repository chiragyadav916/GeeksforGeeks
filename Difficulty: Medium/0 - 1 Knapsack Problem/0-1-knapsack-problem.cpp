//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  int fun(int n,int W, vector<int> &val, vector<int> &wt,vector<vector<int>> &dp){
      //base case
      if(n==0){
          if(wt[0]<=W) return val[0];
          else return 0;
      }
      
      if(dp[n][W] != -1) return dp[n][W];
      int take=INT_MIN;
      int nottake=0+fun(n-1,W,val,wt,dp);
      
      if(wt[n]<=W){
          take = val[n] + fun(n-1,W-wt[n],val,wt,dp);
      }
      
      return dp[n][W]=max(take,nottake);
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return fun(n-1,W,val,wt,dp);
    }
};
 





//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends