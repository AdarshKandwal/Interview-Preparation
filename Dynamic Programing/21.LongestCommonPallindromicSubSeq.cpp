#include<bits/stdc++.h>
using namespace std;

int LCS(string a ,string b , int n , int m,vector<vector<int>> &t){
    
    for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){
        
        if(i==0 || j==0)
            t[i][j]=0;
        else if(a[i-1]==b[j-1])
            t[i][j]=1+t[i-1][j-1];
        else
            t[i][j]=max(t[i-1][j],t[i][j-1]);
        
    }}
return t[n][m];
}


int main(){
    string  X= "GEEKSFORGEEKS";
    int m = X.length(); 
    string Y=X;
    reverse(X.begin(),X.end());
    vector<vector<int>> t(m+1,vector<int>(m+1));
    cout<<"Length of LCS is "; 
    cout<<LCS(X,Y,m,m,t);
    
    return 0;
}
