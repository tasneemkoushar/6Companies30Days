/*
    Find latest version
*/
#include<bits/stdc++.h>
using namespace std;

int Code(string s1, string s2) {
        
        int i = 0,  j= 0;
        int n = s1.size() , m  =s2.size();
        
        while(i < n || j < m){
            int num1 = 0, num2 = 0;
            while(i < n && s1[i] != '.'){
                num1 = num1*10 + s1[i]-'0';
                i++;
            }
            
            while(j < m && s2[j] != '.'){
                num2 = num2*10 + s2[j]-'0';
                j++;
            }
            
            if(num1 > num2) return 1;
            else if(num2 > num1) return -1;
            
            i++; j++;
        }
        
        
        return 0;
    }

int main(){
    string str1,str2;
    cin>>str1>>str2;
    cout<<(Code(str1,str2)==1)?str1:str2;
    return 0;
}