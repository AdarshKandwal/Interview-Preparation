#include<bits/stdc++.h>
using namespace std;

unordered_map<string,bool> mp; 

bool isScrambled(string s1 , string s2){
    if(s1.length() != s2.length())
        return false;
    int n=s1.length();
    if(n==0)
        return true;
    if(s1==s2)
        return true;
    string key=s1;
    key.push_back(' ');
    key.append(s2);
    
    if(mp.find(key) != mp.end())
        return mp[key];
    
    bool flag=false;
    for(int k=1;k<=n-1;k++){
        
        if(isScrambled(s1.substr(0,k),s2.substr(0,k)) && isScrambled(s1.substr(k,n-k),s2.substr(k,n-k))){
            flag =true;
            break;
        }  
        
        if(isScrambled(s1.substr(0,k),s2.substr(n-k,k)) && isScrambled(s1.substr(k,n-k),s2.substr(0,n-k))){
            flag =true;
            break;
        }
        
    }
    
    return flag;
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
