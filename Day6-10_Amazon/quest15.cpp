/*
    Delete N nodes after M nodes
    Question Link: https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1/#

*/

class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        struct Node* curr = head;
        int i=0, j=0;
        while(curr)
        {
            i++;
            if(i==M)
            {
                Node* sam = curr;
                j=0;
                while(j<N && sam->next)
                {
                    sam = sam->next;
                    j++;
                }
                if(sam)
                {
                    curr->next = sam->next;
                }
                i=0;
            }
            curr = curr->next;
        }
    }
};