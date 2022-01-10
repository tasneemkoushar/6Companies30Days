/*
    Burning Tree
    Question Link: https://practice.geeksforgeeks.org/problems/burning-tree/1/
*/

class Solution {
  public:
    void level_order(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()!=0){
        Node* t = q.front();
        q.pop();
        cout<<t->data<<" ";
        if(t->left){
            q.push(t->left);
        }
        if(t->right){
            q.push(t->right);
        }
    }
}

void parentpointers(Node* root,map<Node*,Node*>& mp){
        queue<Node*>q;
        q.push(root);
        mp[root] = NULL;
        while(q.size()!=0){
            Node* temp = q.front();
            q.pop();
            if(temp->left){
                mp[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                mp[temp->right] = temp;
                q.push(temp->right);
            }
            
        }
    }
    Node* findpointer(Node* root,int target){
        queue<Node*> q;
        q.push(root);
        while(q.size()!=0){
            Node* temp = q.front();
            q.pop();
            if(temp->data == target){
                return temp;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
       return NULL ; 
    }
    int minTime(Node* root, int target) 
    {
        if(root == NULL){
            return 0;
        }
        Node* element = findpointer(root,target);
        map<Node*,Node*> mp;
        parentpointers(root,mp);
        if(element == NULL){
            return 0;
        }
        map<Node*,bool>visited;
        queue<Node*> q;
        q.push(element);
        visited[element] = 1;
        int time = 0;
 
        while(q.size()!=0){
            int s = q.size();
             time++;
            for(int i = 0;i<s;i++){
                Node* temp = q.front();
                q.pop();
                visited[temp] = 1;
                if(mp[temp] && !(visited[mp[temp]])){
                    q.push(mp[temp]);
                }
                if(temp->left && !(visited[temp->left])){
                    q.push(temp->left);
                }
                if(temp->right && !(visited[temp->right])){
                    q.push(temp->right);
                }
            }
           
        }
        
        return time-1 ;
    }
};