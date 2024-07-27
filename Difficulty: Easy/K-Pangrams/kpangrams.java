//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine().trim());
        while (t-- > 0) {
            String str = sc.nextLine();
            int k = Integer.parseInt(sc.nextLine().trim());
            Solution obj = new Solution();
            if (obj.kPangram(str, k))
                System.out.println("true");
            else
                System.out.println("false");
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    boolean kPangram(String str, int k) {
        // code here
        str=str.replaceAll("\\s", "");
        int n=str.length();
        if(n<26) return false;
        if(n>=26 && k==25) return true;
        
        int freq[]=new int[26];
        for(int i=0;i<n;i++) {
            char ch=str.charAt(i);
            freq[ch - 'a']++;
        }
        
        int count=0;
        for(int i=0;i<26;i++) {
            if(freq[i]==0)
            {
                count++;
            }
        }
        
        return k>=count;
    }

}