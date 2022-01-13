/*
    Print all Binary from 1 to N
    Question Link: https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/#
*/

vector<string> generate(int N)
{
	queue<int> q;
	vector<string> ans;

	q.push(1);
	int val;
	int i=0;
	while(i<N)
	{
	    val = q.front();
	    ans.push_back(to_string(val));
	    val*=10;
	    q.pop();
	    q.push(val+0);
	    q.push(val+1);
	    i++;
	}
	return ans;
}