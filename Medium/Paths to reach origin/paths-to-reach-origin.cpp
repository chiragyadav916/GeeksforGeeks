//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int r(int x, int y){
        if(x==0 && y==0){
            return 1;
        }
        if(x<0 || y<0){
            return 0;
        }
        
        int oneMove=r(x-1,y);
        int secondMove=r(x,y-1);
        
        return (oneMove+secondMove)%1000000007;
    }
    
    int memo(int x, int y, vector<vector<int>>& t){
        if(x==0 && y==0){
            return 1;
        }
        if(x<0 || y<0){
            return 0;
        }
        if(t[x][y]!=-1){
            return t[x][y];
        }
        int oneMove=memo(x-1,y,t);
        int secondMove=memo(x,y-1,t);
        
        return t[x][y]=(oneMove+secondMove)%1000000007;
    }
    
    int ways(int x, int y)
    {
       
    //Recursion
        // return r(x,y);
        
    //Memoization
        // vector<vector<int>> t(x+1,vector<int>(y+1,-1));
        // return memo(x,y,t);
    
    //Tabulation 
        vector<vector<int>> t(x+1,vector<int>(y+1));
        for(int i=0;i<x+1;i++){
            for(int j=0;j<y+1;j++){
                if(i==0 || j==0){
                    t[i][j]=1;
                }
            }
        }
        t[0][0]=1;
        for(int i=1;i<x+1;i++){
            for(int j=1;j<y+1;j++){
                int oneMove=t[i-1][j];
                int secondMove=t[i][j-1];
                t[i][j]=(oneMove+secondMove)%1000000007;
            }
        }
        return t[x][y];
            }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends