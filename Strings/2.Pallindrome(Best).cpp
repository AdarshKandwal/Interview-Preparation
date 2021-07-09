#include<bits/stdc++.h>
using namespace std;

void CheckPallindrome(string str){
    int i=0,j=str.length()-1;
    int flag=0;
    while(i<j){
        if(str[i]!=str[j]){
            flag=1;
            break;
        }
        i++,j--;
    }
    if(flag==0)
        cout<<"pallindrome";
    else
        cout<<"NOT";
} 

int main(){
    string s1="ABA";
    CheckPallindrome(s1);
    return 0;
}
