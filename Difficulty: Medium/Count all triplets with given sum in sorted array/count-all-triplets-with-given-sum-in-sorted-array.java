//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String[] arr1Str = sc.nextLine().split(" ");
            int[] arr = Arrays.stream(arr1Str).mapToInt(Integer::parseInt).toArray();
            int target = Integer.parseInt(sc.nextLine());

            Solution ob = new Solution();
            int ans = ob.countTriplets(arr, target);
            System.out.println(ans);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public int countTriplets(int[] arr, int target) {
        int n = arr.length;
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            int low = i + 1, high = n - 1;
            while (low < high) {
                int sum = arr[i] + arr[low] + arr[high];
                if (sum == target) {
                    count++;
                    
                    // Check all possible duplicates for the same target sum
                    int tempLow = low + 1;
                    int tempHigh = high - 1;

                    while (tempLow < high && arr[tempLow] == arr[low]) {
                        count++;
                        tempLow++;
                    }
                    while (tempHigh > low && arr[tempHigh] == arr[high]) {
                        count++;
                        tempHigh--;
                    }

                    // Move pointers inward
                    low++;
                    high--;
                } else if (sum < target) {
                    low++; // Increase sum
                } else {
                    high--; // Decrease sum
                }
            }
        }

        return count;
    }
}