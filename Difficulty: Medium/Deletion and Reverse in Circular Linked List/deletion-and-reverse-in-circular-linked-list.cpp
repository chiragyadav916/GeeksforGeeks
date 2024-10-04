//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends

class Solution {
  public:
    Node* reverse(Node* head) {
        vector<int> l;
        Node* temp = head;
        while ( temp ){
            l.push_back(temp->data);
            temp = temp->next;
            if ( temp == head ) break;
        }
        for ( int i = l.size()-1; i>=0; i-- ){
            temp->data = l[i];
            temp = temp->next;
        } return head;
    }

    Node* deleteNode(Node* head, int key) {
        vector<Node*> l; Node* temp = head;
        while ( temp ){
            l.push_back(temp);
            temp = temp->next;
            if ( temp == head ) break;
        }
        int ind = -1, n = l.size();
        for ( int i = 0; i<n; i++ ){
            if ( l[i]->data == key ){
                ind = i;
                break;
            }
        }
        if ( ind == -1 ) return head;
        else if ( ind == 0 ){
            l[ind]->next = NULL;
            l[n-1]->next = l[1];
            return l[1];
        } else if ( ind == n-1 )  {
            l[n-1]->next = NULL;
            l[n-2]->next = l[0];
            return head;
        } else {
            l[ind]->next = NULL;
            l[ind-1]->next = l[ind+1];
            return head;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends