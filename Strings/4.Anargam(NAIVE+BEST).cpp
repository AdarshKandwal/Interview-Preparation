#include<bits/stdc++.h>
using namespace std;
void checkAnagram1(string s1,string s2){
    if(s1.length() != s2.length()){
        cout<<"Not Anagram";
        return;
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2)
        cout<<"Anagram";
    else
        cout<<"NOT";
}

int flag=0;
void checkAnagram2(string s1,string s2){
     if(s1.length() != s2.length()){
        cout<<"Not Anagram";
        return;
    }
    int arr[256]={0}; //total char set
    for(int i=0;i<s1.length();i++)
        arr[s1[i]]++,arr[s2[i]]--;
    for(int i=0;i<256;i++)
        if(arr[i]!=0)
            flag=1;
    if(flag==0)
        cout<<"Anargam";
    else
        cout<<"Not Aargam";
            
}

int main(){
    string s1="food";
    string s2="doof";
    checkAnagram2(s1,s2);
    return 0;
}
