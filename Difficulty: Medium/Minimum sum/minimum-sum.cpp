//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string addTwoString(string s1,string s2){
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        
        int n1=s1.size();
        int n2=s2.size();
        
        int i=0,j=0,carry=0;
        string ans;
        
        while(i<n1 && j<n2){
            int t=(s1[i]-'0')+(s2[j]-'0')+carry;
            carry=t/10;
            t%=10;
            ans.push_back(t+'0');
            i++;
            j++;
        }
        
        while(i<n1){
            int t=(s1[i]-'0')+carry;
            carry=t/10;
            t%=10;
            ans.push_back(t+'0');
            i++;
            
        }
        
        while(j<n2){
            int t=(s2[j]-'0')+carry;
            carry=t/10;
            t%=10;
            ans.push_back(t+'0');
            j++;
        }
        
        
        if(carry)
            ans.push_back('1');
        while(ans.size() && ans.back()=='0')    
            ans.pop_back();    
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    bool allZero(string s){
        bool flag=true;
        for(auto ch:s){
            if(ch!='0')
                flag=false;
            
        }
     return flag;   
    }
    
  
    string minSum(vector<int> &arr) {
        // code here
        string num1,num2;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size();i++){
            if(i&1)
                num2.push_back(arr[i]+'0');
            else
                num1.push_back(arr[i]+'0');
        }
        
        string ans=addTwoString(num1,num2);

        if(ans.size()==0)                   
            return "0";
        return ans;
        
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends