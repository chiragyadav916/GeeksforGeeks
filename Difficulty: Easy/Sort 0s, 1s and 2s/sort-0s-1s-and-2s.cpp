//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int z=0,o=0,h=arr.size()-1;
        int i=0;
        while(o<=h)
        {
            if(arr[o]==0)
             {
                 swap(arr[o],arr[z]);
                 z++;
                 o++; 
             }
            else if( arr[o]==1)
            o++;
            else if(arr[o]==2){
                swap(arr[o],arr[h]);
                h--;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends