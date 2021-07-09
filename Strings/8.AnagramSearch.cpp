#include<bits/stdc++.h>
using namespace std;

int charx=256;
bool areAnagram(string &pat,string &txt,int j){
    int count[charx]={0};
    for(int i=0;i<pat.length();i++){
        count[pat[i]]++;
        count[txt[i+j]]--;
    }
    for(int i=0;i<charx;i++)
        if(count[i]!=0)
            return false;
return true;    
}

bool isPresent(string &str,string &pat){
    int n=str.length();
    int m=pat.length();
    for(int i=0;i<=n-m;i++){
        if(areAnagram(pat,str,i))
            return true;
            
    }
    return false;
}

//Method 2

bool areSame(int CT[],int CP[]){
    
    for(int i=0;i<charx;i++){
        if(CT[i]!=CP[i])return false;
    }
    return true;
}

bool isPresent2(string &txt,string &pat){
    int ct[charx]={0};
    int cp[charx]={0};
    for(int i=0;i<pat.length();i++){
        ct[txt[i]]++;
        cp[pat[i]]++;
    }
    for(int i=pat.length();i<txt.length();i++){
        if(areSame(ct,cp))
            return true;
        ct[txt[i]]++;
        cp[txt[i-pat.length()]]--;
    }
}
int main(){
    string s1="geeksforgeeks";
    string s2="frog";
    cout<<isPresent(s1,s2);
    return 0;
}
