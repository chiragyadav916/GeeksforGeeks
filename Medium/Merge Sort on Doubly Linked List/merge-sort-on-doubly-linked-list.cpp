//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *merge(struct Node *a, struct Node *b){
        struct Node *dummy = new Node(-1);
        struct Node *ptr = dummy;
        
        while(a && b){
            if(a->data <= b->data){
                ptr->next = a;
                a->prev = ptr;
                a = a->next;
            }
            else{
                ptr->next = b;
                b->prev = ptr;
                b = b->next;
            }
            ptr = ptr->next;
        }
        
        while(a){
            ptr->next = a;
            a->prev = ptr;
            a = a->next;
            ptr = ptr->next;
        }
        while(b){
            ptr->next = b;
            b->prev = ptr;
            b = b->next;
            ptr = ptr->next;
        }
        
        struct Node *ans = dummy->next;
        ans->prev = NULL;
        return ans;
    }
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        if(head == NULL || head->next == NULL) return head;
        
        struct Node *fast = head;
        struct Node *slow = head;
        struct Node *temp = NULL;
        
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        
        struct Node* a = sortDoubly(head);
        struct Node* b = sortDoubly(slow);
        
        return merge(a,b);
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends