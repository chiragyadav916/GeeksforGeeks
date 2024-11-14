//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        if(k!=0){
            // vector<int>nums;
            int indx=0;
            priority_queue<int,vector<int>,greater<int>>q;
            int i=0;
            while(i<k){
                q.push(arr[i]);
                i++;
            }
            for(int j=i; j<arr.size(); j++){
                if(q.size()==k){
                    arr[indx]=q.top();
                    q.pop();
                    q.push(arr[j]);
                    indx++;
                }
            }
            while(!q.empty()){
                arr[indx]=q.top();
                q.pop();
                indx++;
            }
            for(int i=0; i<arr.size()-1; i++){
                if(arr[i]>arr[i+1]){
                    swap(arr[i],arr[i+1]);
                }
            }
        }
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
        Solution obj;
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends