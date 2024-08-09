//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  
  const int MOD = 1e9 + 7;
  
  public:
    int Maximize(vector<int> &arr) {
        // Complete the function
        long long int sum=0;
        sort(arr.begin(),arr.end());
        for(long long int i=0;i<arr.size();i++){
            sum+=i*arr[i];
        }
        return sum%MOD;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends