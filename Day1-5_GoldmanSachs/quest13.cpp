/*
    Decode String
    Question Link: https://practice.geeksforgeeks.org/problems/decode-the-string2444/1
*/
string decodedString(string s)
    {
        string num = "";
        string ans = "";
        int n;
        string temp = "";
        string temp2 = "";
        stack<char> st;
        int p = 0;

        while (p < s.size())
        {
            if (s[p] == ']')
            {
                while (st.top() != '[')
                {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                while (isdigit(st.top()))
                {
                    num = st.top() + num;
                    st.pop();
                    if (st.empty())
                    {
                        break;
                    }
                }
                n = stoi(num);
                for (int i = 1; i <= n; i++)
                {
                    temp2 = temp2 + temp;
                }
                if (st.empty())
                {
                    ans = temp2;
                    break;
                }
                for (int i = 0; i < temp2.size(); i++)
                {
                    st.push(temp2[i]);
                }

                temp = "";
                temp2 = "";
                num = "";
            }
            else
            {
                st.push(s[p]);
            }
            p++;
        }
        return ans;
    }