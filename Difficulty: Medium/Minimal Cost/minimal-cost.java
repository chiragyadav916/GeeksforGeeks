//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;


// } Driver Code Ends
// User function Template for Java

class Solution {
    public int solve(int k, int[] arr, int n, int[] dp, int idx) {
        if (idx == n - 1)
            return 0;

 

        if (dp[idx] != -1)
            return dp[idx];

        int ans = Integer.MAX_VALUE;
        for (int j = idx + 1; j <= Math.min(idx + k, n - 1); j++)
            ans = Math.min(ans, Math.abs(arr[idx] - arr[j]) + solve(k, arr, n, dp, j));
        return dp[idx] = ans;
    }

    public int minimizeCost(int k, int[] arr) {
        int n = arr.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);

        return solve(k, arr, n, dp, 0);
    }
}

//{ Driver Code Starts.

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine());
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;
            Solution obj = new Solution();
            int res = obj.minimizeCost(k, arr);

            System.out.println(res);
        }
    }
}
// } Driver Code Ends