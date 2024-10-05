//{ Driver Code Starts
// Initial Template for Java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Consume the newline character
        while (t-- > 0) {
            String input = sc.nextLine();
            String[] inputArr = input.split(" ");
            int[] arr = new int[inputArr.length];
            for (int i = 0; i < inputArr.length; i++) {
                arr[i] = Integer.parseInt(inputArr[i]);
            }

            Solution ob = new Solution();
            long ans = ob.findSmallest(arr);
            System.out.println(ans);
        }
        sc.close();
    }
}

// } Driver Code Ends


class Solution {
    public long findSmallest(int[] arr) {
        // Your code goes here
        // initialize the smallest missing positive integer
        long smallestMissing = 1;
        
        // iterate through the sorted array
        for(int num : arr)
        {
            // if the current number is greater than the smallest missing 
            // we cannot form the smallest missing number
            
            if(num > smallestMissing)
            {
                break;  // no need to continue, as we found the answer
            }
            
            // otherwise, update the smallest missing number
            smallestMissing = smallestMissing + num;
            
        }
        
        return smallestMissing;
    }
}