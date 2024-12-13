//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = Integer.parseInt(scanner.nextLine());

        Solution ob = new Solution(); // Instantiate the Solution object once

        while (t-- > 0) {
            String line = scanner.nextLine();
            String[] elements = line.split(" ");
            int[] arr = new int[elements.length]; // Changed to int[]

            for (int i = 0; i < elements.length; i++) {
                arr[i] = Integer.parseInt(elements[i]);
            }

            System.out.println(ob.findMin(arr));
            System.out.println("~");
        }
        scanner.close();
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    public int findMin(int[] arr) {
        int i=0;
        int j=arr.length-1;
        int n=arr.length;
        
        while(i<=j) {
        	int mid=(i+j)>>1;
        	int next=(mid+1)%n;
        	int prev=(mid+n-1)%n;
        	
        	if(arr[mid]<=arr[next] && arr[prev]>=arr[mid]) {
        		return arr[mid];
        	}else {
        		if(arr[mid]<arr[j]) {
        			j=mid-1;
        		}else {
        			i=mid+1;
        		}
        	}
        }
    	return -1;
    }
}
