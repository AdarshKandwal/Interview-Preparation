#include<bits/stdc++.h>
using namespace std;

int lCS(string a , string b , int n , int m , vector<vector<int>> &t){
    
    for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){
      if(i==0 || j==0)
        t[i][j]=0;
      else if( a[i-1]==b[j-1])
        t[i][j]=1+t[i-1][j-1];
      else
        t[i][j]=max(t[i-1][j],t[i][j-1]);
        
    }}
    return t[n][n];
}



int main(){
    string X= "ab"; 
    string Y=X;
    reverse(Y.begin(),Y.end());
    int m = X.length(); 
    int n = Y.length(); 
    vector<vector<int>> t(m+1,vector<int>(n+1));
    int x=lCS(X,Y,m,n,t);
    cout<<"Min number of insertion are : "<< m-x; 
    return 0;
}
