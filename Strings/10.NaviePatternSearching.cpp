#include<bits/stdc++.h>
using namespace std;

void patsearching(string &txt,string &pat){
    int m=pat.length();
    int n=txt.length();
    int flag=0;
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(pat[j]!=txt[i+j])
                break;
        }
        if(j==m){
            flag=1;
            cout<<i<<" ";}
    }
    if(flag==0)
        cout<<"nothing found here";
}

int main(){
    string x="abcabcd";
    string pat="abcd";
    patsearching(x,pat);
    return 0;
}
