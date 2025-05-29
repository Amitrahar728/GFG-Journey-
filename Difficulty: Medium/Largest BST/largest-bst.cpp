/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	pair<int,pair<int,int>>p;
    	auto ans = solve(root,p);
    	return ans.first;
    }
    
    pair<int,pair<int,int>> solve(Node* root, pair<int,pair<int,int>>&p){
        if(!root){
            return {0,{INT_MAX,INT_MIN}};
        }
        
        auto lh = solve(root->left,p);
        auto rh = solve(root->right,p);
        
        // cheking for valid bst
        
        if(lh.second.second < root->data && root->data < rh.second.first){
            return {(lh.first+rh.first+1) , {min(root->data,lh.second.first) , max(root->data,rh.second.second)}};
        }
        
        return {max(lh.first,rh.first) , {INT_MIN,INT_MAX}};
    }
};