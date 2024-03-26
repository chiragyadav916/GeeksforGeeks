//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool isAdditiveSequence(string s) {
        
        int n = s.length();
        //First number
        int num1 = 0;
        //Atmost first number will contain n/2 digits in it, so looping against it
        for(int i = 0; i < n/2; i++){
            //Finding the first number 
            num1 = num1*10 + (s[i] - '0');
            //Going for the second number 
            int num2 = 0;
            // Search for the second number starts from the next index, hence i + 1th index
            for(int j = i + 1; j < n - 1; j++){
                //Assigning the value to the second number 
                num2 = num2*10 + (s[j] - '0');
                int prev2 = num1, prev1 = num2;
                //Now finding the third number which can satisfy the equation of num1 + num2 = num
                int num = 0;
                int k = j + 1;
                while(k < n){
                    num = num * 10 + (s[k] - '0');
                    if(num == (prev1 + prev2)){
                        prev2 = prev1;
                        prev1 = num;
                        num = 0;
                    }
                    k++;
                }
                if (k == n && num == 0){
                    return 1;
                }
            }
       }
       return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends