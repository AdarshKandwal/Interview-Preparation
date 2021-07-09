#include<bits/stdc++.h>
using namespace std;

void CheckSubSeq(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    int len=0;
    for(int i=0;i<n&&i<m;i++){
        if(s1[i]==s2[i])
            len++;
    }
    if(len=m)
        cout<<"It is a subseq";
    else
        cout<<"not";
}

int main(){
    string s1="ABADVCX";
    string s2="X";
    CheckSubSeq(s1,s2);
    return 0;
}
