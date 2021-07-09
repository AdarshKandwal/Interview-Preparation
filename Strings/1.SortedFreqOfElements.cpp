#include<bits/stdc++.h>
using namespace std;

void SortedFreq(string s1){
    int arr[26]={0};//for 26 alphabet;
    for(int i=0;i<s1.length();i++)
        arr[s1[i]-'A']++;
        
    for(int i=0;i<26;i++){
        if(arr[i]>0)
            std::cout << (char)(i+'A') <<" "<<arr[i] <<std::endl;
    }
}

int main(){
    string s1="ABCDDDBBC";
    SortedFreq(s1);
    return 0;
}
