//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class Driver_code {
    static Node insert(Node head, int data) {
        Node temp = new Node(data);
        if (head == null) {
            head = temp;
            return head;
        } else {
            Node t = head;
            while (t.next != null) {
                t = t.next;
            }
            t.next = temp;
        }
        return head;
    }

    static void printList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {

            Node head = null;

            String str[] = read.readLine().trim().split(" ");
            int listSize = str.length;
            for (int i = 0; i < listSize; i++) {
                head = insert(head, Integer.parseInt(str[i]));
            }
            boolean f = new Solution().isPalindrome(head);

            System.out.println(f ? "true" : "false");
        }
    }
}

// } Driver Code Ends




/* Structure of class Node is
class Node
{
	int data;
	Node next;
	
	Node(int d)
	{
		data = d;
		next = null;
	}
}*/

class Solution
{
    //Function to check whether the list is palindrome.
    
    String convertToString(Node head)
    {
        StringBuilder s= new StringBuilder();
        Node cur=head;
        while(cur!=null)
        {
            s.append(Integer.toString(cur.data));
            cur=cur.next;
        }
        return s.toString();
    }
    
    
    boolean isPalindrome(Node head) 
    {
        if(head.next==null)
            return true;   //LL of length 1
            
        String s1=convertToString(head);
        
        Node prev=null,curr=head;
        while(curr!=null)
        {
            Node temp=curr.next;
            curr.next=prev;
            prev=curr;
            curr=temp;
        }
        //prev is head now
        
        String s2=convertToString(prev);
        
        if(s1.equals(s2))
            return true;
        return false;
    
    }    
}
