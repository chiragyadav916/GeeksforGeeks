//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        
    int n = arr.size();
    int low = 0, maxi = 0, startIdx = -1;
    multimap<int, int> mp;

    for (int i = 0; i < n; i++) {
        
        mp.insert({arr[i], i});

        int num1 = mp.begin()->first;  
        int num2 = prev(mp.end())->first;  

        while (num2 - num1 > x) {  
        
            int toErase = arr[low];
            auto it = mp.find(toErase);
            mp.erase(it);
            low++;  

            num1 = mp.begin()->first;  
            num2 = prev(mp.end())->first;  
        }

        int len = i - low + 1;
        
        if (len > maxi) {
            maxi = len;
            startIdx = low;
        }
        
        
    }

    vector<int> ans;
    
    if (startIdx != -1) {
        
        for (int i = startIdx; i < startIdx + maxi; i++) {
            ans.push_back(arr[i]);
        }
        
    }

    return ans;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends