//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        int n = arr.size();
        if(n<3)
            return false;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            int start=0, end=n-1;
            while(start<end){
                if(start==i){
                    start++;
                    continue;
                }
                if(end == i){
                    end--;
                    continue;
                }
                if(arr[start]+arr[end] == arr[i]){
                    return true;
                }else if(arr[start]+arr[end] < arr[i]){
                    start++;
                }else{
                    end--;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends