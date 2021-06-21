#include<bits/stdc++.h>
using namespace std;

bool isScrambled(string s1 , string s2){
    
    if(s1.length() != s2.length())
        return false;
    int n=s1.length();
    if(n==0)
        return true;
    if(s1==s2)
        return true;
    
    for(int k=1;k<=n-1;k++){
        
        if(isScrambled(s1.substr(0,k),s2.substr(0,k)) && isScrambled(s1.substr(k,n-k),s2.substr(k,n-k))){
            return true;
        }  
        
        if(isScrambled(s1.substr(0,k),s2.substr(n-k,k)) && isScrambled(s1.substr(k,n-k),s2.substr(0,n-k))){
            return true;
        }
        
    }
    
    return false;
}

int main(){
    string S1 = "coder";
    string S2 = "ocred";
 
    if (isScrambled(S1, S2)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
return 0;
}
