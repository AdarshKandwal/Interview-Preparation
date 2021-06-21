#include<bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2 , int n , int m){
    
    if(n==0)
        return m;
    if(m==0)
        return n;
    if(s1[n-1]==s2[m-1])
        return editDistance(s1,s2,n-1,m-1);
    else
        return 1+min(editDistance(s1,s2,n,m-1),min(editDistance(s1,s2,n-1,m),editDistance(s1,s2,n-1,m-1)));
    
}


int main(){
    string str1 = "sunday";
    string str2 = "saturday";
 
    cout << editDistance(str1, str2, str1.length(),
                     str2.length());
    
    return 0;
}
