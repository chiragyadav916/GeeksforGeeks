//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here 
            Node *head = arr[0], *tail = head,*prev;
            map<int, vector<Node*>> mp;
            int n = arr.size();
            for(int i = 0; i<n; i++) {
                tail = arr[i];
                while(tail != NULL) {
                    mp[tail->data].push_back(tail);
                    tail = tail->next;
                    //if(tail->next == NULL) break;
                }
            }
            Node * ptr;
            int flag = 0;
            for(auto it:mp) {
                
                int size = it.second.size(),j=0;
                while(j<size){
                    if(!flag) {
                    prev = it.second[j];
                    ptr = prev;
                    flag = 1;
                }
                else {
                    prev->next = it.second[j];
                    prev = it.second[j];
                }
                    j++;
                    
                }
            }
            return ptr;
}
};




//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends