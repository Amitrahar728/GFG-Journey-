/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
  void  func(Node* root , vector<int> &arr , int level){
        if(root == NULL){
            return;
        }
        if(level == arr.size()) arr.push_back(root->data);
        func(root->left, arr, level+1);
        func(root->right,arr, level+1);
    }

    
    vector<int> leftView(Node *root) {
        int level = 0;
        vector<int> arr;
        func(root,arr,level);
            
        return arr;
    }
};