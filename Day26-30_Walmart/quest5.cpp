/*
    Transform To sum Tree
    Question Link: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/#
*/
class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int code(Node* root){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right)
        {
            int k = root->data;
            root->data = 0;
            return k;
        }
        
        int a = code(root->left);;
        int b = code(root->right);      
        int c = root->data;
        root->data = a+b;
        return (c+root->data);
    }
    
    void toSumTree(Node *node)
    {
        if(!node) return;
        code(node);
        return;
    }
};