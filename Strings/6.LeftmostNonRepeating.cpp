#include<bits/stdc++.h>
using namespace std;

int nonRep1(string &str){
    for(int i=0;i<str.length();i++){
        bool flag=false;
        for(int j=0;j<str.length();j++){
            //logic for repeating character
            if(i!=j && str[i]==str[j]){
                flag=true;
                break;
            }
        }
        //if not  in above logic then its not repeating
        if(flag==false)
            return i;
    }
    return -1;
}
int CHAR=256;
int NonRep2(string &str){
    vector<int> fi(CHAR,-1);
    for(int i=0;i<str.length();i++){
        if(fi[str[i]]==-1)
            fi[str[i]]=i;
        else
            fi[str[i]]=-2;
    }
    int res=INT_MAX;
    for(int i=0;i<CHAR;i++){
        if(fi[i]>=0)
            res=min(res,fi[i]);
    }
    return (res==INT_MAX)?-1:res;
}


int main(){
    string str = "geeksforgeeks";
    cout<<"Index of leftmost non-repeating element:"<<endl;
    cout<<NonRep2(str)<<endl;  
    
    return 0;
}
