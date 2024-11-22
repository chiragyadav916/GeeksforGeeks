//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
    int maximumProfit(vector<int> &prices) {
       int n = prices.size(); 
        int ans = 0; 
        int taken = prices[0]; 
        for(int i = 1; i<n; i++){
           if(prices[i]>taken){
               ans = max(ans,prices[i]-taken); 
           }else{
               taken = prices[i]; 
           }
        }
        return ans; 
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends