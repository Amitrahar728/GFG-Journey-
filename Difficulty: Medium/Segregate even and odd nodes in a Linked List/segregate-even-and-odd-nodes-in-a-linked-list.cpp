//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function template for C++

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
    Node* divide(Node* head) {
        if (!head || !head->next) return head;
        
        Node *evenHead = NULL, *evenTail = NULL, *oddHead = NULL, *oddTail = NULL;
        Node* current = head;
        
        while (current) {
            if (current->data % 2 == 0) {
                if (!evenHead) {
                    evenHead = evenTail = current;
                } else {
                    evenTail->next = current;
                    evenTail = evenTail->next;
                }
            } else {
                if (!oddHead) {
                    oddHead = oddTail = current;
                } else {
                    oddTail->next = current;
                    oddTail = oddTail->next;
                }
            }
            current = current->next;
        }
        
        if (evenTail) evenTail->next = oddHead;
        if (oddTail) oddTail->next = NULL;
        
        return evenHead ? evenHead : oddHead;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty())
            continue;

        int data = arr[0];
        int N = arr.size();
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < N; ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(head);
        printList(ans);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends