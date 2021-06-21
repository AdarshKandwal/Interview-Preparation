#include<bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2 , int n , int m,vector<vector<int>> &dp){

    for(int  i=0;i<n+1;i++)
        dp[i][0]=i;
    for(int j=0;j<m+1;j++)
        dp[0][j]=j;
    for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){
     
     if(s1[i-1]==s2[j-1])
        dp[i][j]=dp[i-1][j-1];
     else
        dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        
    }}
 return dp[n][m];
}


int main(){
    string str1 = "sunday";
    string str2 = "saturday";
    vector<vector<int>> t(str1.length()+1,vector<int>(str2.length()+1));
    cout << editDistance(str1, str2, str1.length(),str2.length(),t);
    
    return 0;
}
