//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
        // code here
        int minSteps(int D){
        int sum=0;
        int steps=0;
        for(steps=1;sum<D;steps++)sum+=steps;
        if(sum==D)return steps-1;
        else if(!((sum-D)&1))return steps-1;
        else if(!((sum-D+steps)&1))return steps;
        else if(!((sum-D+steps+steps+1)&1))return steps+1;
        return -1;
    }
   
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends