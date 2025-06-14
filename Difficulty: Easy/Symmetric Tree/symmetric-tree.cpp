/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
   bool isMirror(Node* leftSub, Node* rightSub) {
    if (leftSub == nullptr && rightSub == nullptr) 
        return true;
        
        
    if (leftSub == nullptr || rightSub == nullptr || 
        			leftSub->data != rightSub->data) {
        return false;
    }
    

    return isMirror(leftSub->left, rightSub->right) &&
           isMirror(leftSub->right, rightSub->left);
}

bool isSymmetric(Node* root) {
    
    
    if (root == nullptr) 
        return true;
    return isMirror(root->left, root->right);
}
};