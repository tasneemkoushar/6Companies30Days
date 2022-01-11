/*
    Serialize and Deserialize
    Question Link: https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1#
*/

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    void code(Node* root, vector<int> &vec)
    {
        if(!root)
        {
            return;
        }
        if(root->left)
        {
            vec.push_back(root->left->data);
        }
        else{
            vec.push_back(0);
        }
        if(root->right)
        {
            vec.push_back(root->right->data);
        }
        else{
            vec.push_back(0);
        }
        code(root->left,vec);
        code(root->right,vec);
    }
    vector<int> serialize(Node *root) 
    {
       vector<int> vec;
       vec.push_back(root->data);
       code(root,vec);
       
       return vec;
       
    }
    
    //Function to deserialize a list and construct the tree.
    void code2(Node* root, vector<int> A, int &ind)
    {
        if(!root || ind  >= A.size())
        {
            return;
        }
        ind++;
        if(ind <A.size() && A[ind]!=0)
        {
            root->left = new Node(A[ind]);
        }
        ind++;
        if(ind<A.size() && A[ind]!=0)
        {
            root->right = new Node(A[ind]);
        }
        code2(root->left,A,ind);
        code2(root->right,A,ind);
    }
    
    Node * deSerialize(vector<int> &A)
    {
        Node* root = new Node(A[0]);
        int index = 0;
          code2(root,A,index);

          return root;
    }

};