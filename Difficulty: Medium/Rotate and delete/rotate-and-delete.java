//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;


// } Driver Code Ends

class Solution {
    public static int rotateDelete(ArrayList<Integer> arr) {
        int k = 1; // Start with the first operation

        while (arr.size() > 1) {
            // Step 1: Rotate the array to the right by 1
            rotateRight(arr);

            // Step 2: Calculate the index to delete
            int indexToRemove = arr.size() - k;
            
            // Remove the element at the calculated index
            if (indexToRemove >= 0) {
                arr.remove(indexToRemove);
            } else {
                arr.remove(0); // If out of bounds, remove the first element (as per given explanation)
            }

            k++; // Increment the operation number for the next iteration
        }

        return arr.get(0); // The last remaining element
    }

    public static void rotateRight(ArrayList<Integer> arr) {
        // Rotate the array to the right by 1
        int lastElement = arr.remove(arr.size() - 1);
        arr.add(0, lastElement);
    }
}

//{ Driver Code Starts.

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> arr = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                arr.add(Integer.parseInt(token));
            }

            Solution obj = new Solution();
            int res = obj.rotateDelete(arr);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends