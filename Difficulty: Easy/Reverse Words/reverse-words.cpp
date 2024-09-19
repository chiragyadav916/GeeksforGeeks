//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) {
    int st = 0, en = S.length() - 1;
    
    // Reverse the entire string.
    while (st <= en) {
        swap(S[st], S[en]);
        st++;
        en--;
    }
    
    string s = S;
    int start = 0;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            int end = i - 1;
            
            // Reverse the characters within a word.
            while (start <= end) {
                swap(s[start], s[end]);
                start++;
                end--;
            }
            
            start = i + 1;
        }
    }
    
    // Reverse the last word (or the only word if there are no periods in the string).
    int end = n - 1;
    
    while (start <= end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
    
    return s;
}
 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends