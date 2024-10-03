//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
   vector<int> findMajority(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto i: nums){
            map[i]++;
        }
        int limit = nums.size()/3;
        
        vector<int> output;
        int flag=0;
        for(auto i:map){
            if(i.second>limit){
                output.push_back(i.first);
                flag=1;
            }
        }
        if(flag==0)output.push_back(-1);
        sort(output.begin(),output.end());
        return output;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends