/*
    Print Anagrams Together
    Question Link : https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/
*/

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        
        map<string,vector<int>>m;
        for(int i=0; i<string_list.size(); i++)
        {
            string s = string_list[i];
            sort(s.begin(),s.end());
            m[s].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto i:m)
        {
            vector<string> vec;
            for(int j=0; j<i.second.size(); j++)
            {
                vec.push_back(string_list[i.second[j]]);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};