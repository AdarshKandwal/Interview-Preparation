#include<bits/stdc++.h>
using namespace std;

int LCS(char *a , char *b , int n , int m ,vector<vector<int>> &t){
    
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
    char X[] = "axyz"; 
    char Y[] = "adxcpy"; 
      
    int m = strlen(X); 
    int n = strlen(Y); 
    vector<vector<int>> t(m+1,vector<int>(n+1));
    int L=LCS(X,Y,m,n,t);
    int lenInput=min(m,n);
    
    if(L==lenInput)
        cout<<"Sequence Matched";
    else
        cout<<"Not matched";
    
  
return 0;
}
