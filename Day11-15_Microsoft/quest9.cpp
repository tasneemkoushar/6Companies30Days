/*
    Number of subtrees with given sum
    Question Link: https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/
*/
int  value(Node* root, int X, int &cnt)
{
    if(!root)
    {
        return 0;
    }
    root->data += value(root->left, X, cnt);
    root->data += value(root->right, X, cnt);
    if(root->data == X)
    {
        cnt++;
    }
    return root->data;
}
int countSubtreesWithSumX(Node* root, int X)
{
	int ans = 0;
	value(root, X, ans);
	return ans;
}