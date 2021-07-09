#include<bits/stdc++.h>
using namespace std;

int leftmostRepeatingChar1(string &str){
    for(int i=0;i<str.length();i++){
        for(int j=i+1;j<str.length();j++){
            if(str[i]==str[j])
                return i;
        }
    }
    return -1;
}

int charconst=256;
int leftmostRepeatingChar2(string &str){
    int count[charconst]={0};
    for(int i=0;i<str.length();i++)
        count[str[i]]++;
    for(int i=0;i<str.length();i++)
        if(count[str[i]]>1)
            return i;
    return -1;
    
}

const int CHAR=256;
int leftMost3(string &str) 
{
    bool visited[CHAR];
    fill(visited,visited+CHAR,false);
    int res=-1;
    for(int i=str.length()-1;i>=0;i--){
        if(visited[str[i]])
        res=i;
        else
        visited[str[i]]=true;
    }
    
    return res;
}
int main(){
    string s1="dffggg";
    cout<<leftMost3(s1);
    return 0;
}
