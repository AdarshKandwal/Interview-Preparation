#include<bits/stdc++.h>
using namespace std;

#define NIL INT_MAX-1

int LongestCommonSubsequence(char *a , char *b ,int i,int j,vector<vector<int>> &t){
    if(i==0 || j==0)
        return 0;
    if(t[i][j]!=-1)
        return t[i][j];
    if(a[i-1]==b[j-1]){
        t[i][j]=1+LongestCommonSubsequence(a,b,i-1,j-1,t);
        return t[i][j];
    }
    else{
        t[i][j]=max(LongestCommonSubsequence(a,b,i,j-1,t),LongestCommonSubsequence(a,b,i-1,j,t));
        return t[i][j];
    }
}

int main(){
    char X[] = "AGGTAB"; 
    char Y[] = "GXTXAYB"; 
    int m = strlen(X); 
    int n = strlen(Y); 
    vector<vector<int>> t(m+1,vector<int>(n+1,-1));
    cout<<"Length of LCS is "<< LongestCommonSubsequence( X, Y, m, n,t ) ; 
  
    return 0;
}
