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
/* Link list Node:

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

// Deletes middle of linked list and returns head of the modified list
class Solution {
  public:
     Node* deleteNode(Node* head, int x) {
        if(head == NULL) return head;
        if(x == 1){
            Node* temp = head;
            head = head->next;
            free(temp);
            return head;
        }
        int cnt =0;
        Node* temp = head;
        Node* prev = NULL;
        while(temp != NULL){
            cnt++;
            if(cnt == x){
                prev->next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        print(head);
    }
    Node* print(Node*head){
        Node* temp = head;
        while(temp!= NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    
    Node* deleteMid(Node* head) {
        int cnt =0;
        Node* tem = head;
        while(tem!= NULL ){
            cnt++;
            tem = tem->next;
        }
        if(cnt%2==0){
        deleteNode(head,(cnt/2)+1);
        }
        else{
            deleteNode(head,(cnt+1)/2);
        }
        
    }
};

//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
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
        Solution obj;
        head = obj.deleteMid(head);
        printList(head);
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends