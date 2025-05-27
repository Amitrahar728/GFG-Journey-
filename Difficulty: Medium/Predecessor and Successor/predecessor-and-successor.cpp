/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = nullptr;
Node* suc = nullptr;

        Node*temp = root;
        while(temp!= NULL){
            if(key>=temp->data){
                temp = temp->right;
            }
            else{
                suc = temp;
                temp = temp->left;
            }
        }
        temp = root;
        while(temp!= NULL){
            if(key<=temp->data ){
                temp = temp->left;
            }
            else{
                pre = temp;
                temp = temp->right;
            }
        }
        vector<Node*> ans;
        ans.push_back(pre);
        ans.push_back(suc);
        return ans;
        
        
    }
};