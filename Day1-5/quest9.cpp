/*
    Number following a pattern
    Question Link: https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1
*/
string printMinNumberForPattern(string s){
         string x = "";
        int i = 0, j = 0;
        int count = 1;
        while (i <= s.size())
        {
            if (s[i] == 'I' || i == s.size())
            {
                while (count >= 1)
                {
                    if (count <= j)
                        break;
                    char ch = count + '0';
                    x.push_back(ch);
                    count--;
                }
                j = i + 1;
                count = i + 1;
            }
            count++;
            i++;
        }
        return x;
    }