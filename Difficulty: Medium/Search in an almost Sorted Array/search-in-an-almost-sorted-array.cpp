//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int bs(int l, int r, vector<int> &arr, int &x){
        if(l>r)
            return -1;
        int m = l+(r-l)/2;
        if(arr[m]==x)
            return m;
        if(arr[m]<x){
            if(m>0 && arr[m-1]==x)
                return m-1;
            return bs(m+1, r, arr, x);    
        }
        else{
            if(m<(arr.size()-1) && arr[m+1]==x)
                return m+1;
            return bs(l, m-1, arr, x);
        }
        return -1;
    }
  
    int findTarget(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        return bs(0, n-1, arr, target);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends