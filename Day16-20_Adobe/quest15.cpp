/*
    Find latest version
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str1,str2;
    cin>>str1>>str2;
    for(int i=0; i<str1.size() && i<str2.size(); i++)
    {
        if(str1[i]>str2[i] && str1[i]!='.' && str2[i]!='.'){
            cout<<str1<<endl;
            break;
        }
        else if(str2[i]>str1[i] && str1[i]!='.' && str2[i]!='.')
        {
            cout<<str2<<endl;
            break;
        }
        else if(str1[i]=='.' && str2[i]!='.')
        {
            cout<<str1<<endl;
        }
        else if(str2[i]=='.' && str2[i]!='.')
        {
            cout<<str2<<endl;
            break;
        }

    }
    return 0;
}