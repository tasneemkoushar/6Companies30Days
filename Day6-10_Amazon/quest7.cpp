/*
    First Non-Repeating Character in a stream
    Question Link: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#
*/

class Solution {
	public:
		string FirstNonRepeating(string A){
		    string ans = "";
		    ans+=A[0];
		    int n = A.size();
		    int arr[26];
		    for(int i=0; i<26; i++)
		    {
		        arr[i] = n;
		    }
		    arr[A[0]-'a'] = 0;
		    int index = 0;
		    for(int i=1; A[i]; i++)
		    {
		        if(arr[A[i]-'a']<n || arr[A[i]-'a']==INT_MAX)
		        {
		            if(arr[A[i]-'a'] == index && index<A.size())
		            {
		                index = n;
		            }
		            arr[A[i]-'a'] = INT_MAX;
		        }
		        else{
		             arr[A[i]-'a'] = i;
		        }
	            if(index<A.size())
	            {
	                ans+=A[index];
	            }
	            else{
	                 for(int j=0; j<26; j++)
	                 {
	                    index = min(index,arr[j]);
	                 }
	                 if(index >= A.size())
	                 {
	                     ans+='#';
	                 }
	                 else{
	                     ans+=A[index];
	                 }
	                 
	            }
		    }
		    return ans;
		}

};