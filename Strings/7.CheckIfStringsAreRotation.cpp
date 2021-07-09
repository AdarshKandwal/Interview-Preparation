#include<bits/stdc++.h>
using namespace std;

bool areRotation(string &s1,string &s2){
    if(s1.length() != s2.length())
        return false;
    return ((s1+s2).find(s2) != string::npos);
}

int main(){
    string s1="ABCD";
    string s2="CDAB";
    cout<<areRotation(s1,s2);
    return 0;
}
