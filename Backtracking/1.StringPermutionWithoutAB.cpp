#include<bits/stdc++.h>
using namespace std;


bool isSafe(string str,int l ,int i, int r){
    if(l!=0 && str[l-1]=='a' && str[i]=='b')
        return false;
    if(r==(l+1) && str[i]=='a' && str[l]=='b')
        return false;
    return true;
}

void PrintSubstring(string str,int l , int r){
    if(l==r){
        cout<<str<<endl;
        return;
    }
    for(int i=l;i<=r;i++){
        if(isSafe(str,l,i,r)){
        swap(str[i],str[l]);
        PrintSubstring(str,l+1,r);
        swap(str[i],str[l]);
        }
    }
}

int main(){
    string a="abc";
    PrintSubstring(a,0,a.length()-1);
    return 0;
}
