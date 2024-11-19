//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        //step 1:find the position where permutation can be done.
        int n=arr.size();
        int temp=0;
        int i;
        for(i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                break;
            }
        }
        //step 2:find next greater than arr[i].
        if(i>-1){
            int nextmax=INT_MAX;
            int nextposi=0;
            for(int j=i+1;j<n;j++){
               if(arr[j]>arr[i] && arr[j]<nextmax){
                   nextposi=j;
                   nextmax=arr[j];
                }
            }
            temp=arr[i];                         //swap two elements.
            arr[i]=arr[nextposi];
            arr[nextposi]=temp;
            int k=n-1;
            int l=i+1;
            while(l<k){            //swap remaining array.
                temp=arr[l];
                arr[l]=arr[k];
                arr[k]=temp;
                l++;
                k--;
            }
        }
        else {
            sort(arr.begin(),arr.end());     //if no permutation sort array.
        }
        
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
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends