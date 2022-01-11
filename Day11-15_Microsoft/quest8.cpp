/*
    Connect nodes at same level
    Question Link: https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/#
*/

class Solution
{
    public:
    //Function to connect nodes at same level.
    void code(Node* root)
    {
         if(!root)
        {
            return;
        }
        // root->nextRight = NULL;
        if(root->left)
        {
            if(root->right)
            {
                root->left->nextRight = root->right;
            }
            else if(root->nextRight)
            {
                if(root->nextRight->left)
                {
                    root->left->nextRight = root->nextRight->left;
                }
                else if(root->nextRight->right)
                {
                    root->left->nextRight = root->nextRight->right;
                }
            }
            else{
                root->left->nextRight = NULL;
            }
            
        }
        if(root->right)
        {   
            if(root->nextRight)
            {
                if(root->nextRight->left)
                {
                    root->right->nextRight = root->nextRight->left;
                }
                else if(root->nextRight->right)
                {
                    root->right->nextRight = root->nextRight->right;
                }
            }
            else{
                root->right->nextRight = NULL;
            }
            
        }
        code(root->left);
        code(root->right);
    }
    void connect(Node *root)
    {
       if(!root)
       {
           return;
       }
       root->nextRight = NULL;
       code(root);
    }    
      
};