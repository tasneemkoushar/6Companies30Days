/*
    Phone Directory
    Question Link: https://practice.geeksforgeeks.org/problems/phone-directory4628/1/
*/

class Solution{
public:
    class Trie{
    public:
    class Node{
        public:
        bool end;
        Node *next[26];
        Node()
        {
            end = false;
            for(int i=0; i<26; i++)
            {
                next[i] = NULL;
            }
        }
    };
    Node *trie;
    Trie()
    {
        trie = new Node();
    }
    void insert(string word)
    {
        
        Node *start = trie;
        for(int i=0; i<word.size();i++)
        {
            if(start->next[word[i]-'a']==NULL)
            {
                start->next[word[i]-'a'] = new Node();
            }
            start = start->next[word[i]-'a'];
        }
        start->end = true;
    }
    
    void code(Node* start, string s, vector<string> &vec)
    {
        if(start->end)
        {
            if(s.size())
            {
                vec.push_back(s);
            }
        }
        for(int i=0; i<26; i++)
        {
            if(start->next[i]!=NULL)
            {
                char c = 'a'+i;
                code(start->next[i], s+c, vec);
            }
        }
    }
    void search(string word, vector<string> &vec)
    {
        Node *start = trie;
        string s = "";
        for(int i=0; i<word.size();i++)
        {
            if(start->next[word[i]-'a']!=NULL)
            {
                s += word[i];
                start = start->next[word[i]-'a'];
            }
            else{
                return;
            }
        }
            code(start, s, vec);
    }
};
    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
       Trie wrd;
       vector<vector<string>> ans;
       for(int i=0; i<n; i++)
       {
           wrd.insert(contact[i]);
       }
       vector<string> vec;
       string str = "";
       
       for(int i=0; i<s.size(); i++)
       {
           str += s[i];
           wrd.search(str, vec);
           if(vec.size())
           {
                ans.push_back(vec);
           }
           else{
               ans.push_back({"0"});
           }
           vec.clear();
       }
       return ans;
    }
};
