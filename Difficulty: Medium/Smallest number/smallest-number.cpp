//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        if(s>9*d)
        return "-1";
        string ans="";
        for(int i=d;i>=1;i--){
            for(int j=9;j>=0;j--){
                if(i!=1){
                if(s-j>0){
                    ans=to_string(j)+ans;
                    s-=j;
                    break;
                }
                }
                else{
                    ans=to_string(s)+ans;
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends