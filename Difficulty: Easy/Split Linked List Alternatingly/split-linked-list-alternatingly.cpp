//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        vector<Node*>result;
        // Creating two dummy nodes
        Node* _dummy1=new Node(-1);
        Node* _dummy2=new Node(-1);
        // Creating two pointers for two dummy nodes 
        Node* temp1=_dummy1;
        Node* temp2=_dummy2;
        Node* temp3=head;
        int i=0;
        // Traversing the linked list and separting them and joining them to 
        // dummy nodes created according to question
        while(temp3 != nullptr){
            if(i%2==0){ 
                Node* _new1=new Node(temp3->data);
                temp1->next=_new1;
                temp1=temp1->next;
            }
            else{
                Node* _new2=new Node(temp3->data);
                temp2->next=_new2;
                temp2=temp2->next;
            }
            i++;
            temp3=temp3->next;
        }
        // Pushing the nodes into result vector
        result.push_back(_dummy1->next);
        result.push_back(_dummy2->next);
        return result;
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends