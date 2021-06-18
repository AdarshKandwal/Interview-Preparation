#include<bits/stdc++.h>
using namespace std;

string LCS(string a ,string b , int n , int m,vector<vector<int>> &t){
    
    for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){
        
        if(i==0 || j==0)
            t[i][j]=0;
        else if(a[i-1]==b[j-1])
            t[i][j]=1+t[i-1][j-1];
        else
            t[i][j]=max(t[i-1][j],t[i][j-1]);
        
    }}
    int i=n;
    int j=m;
    string result;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            result.push_back(a[i-1]);
            i--;
            j--;
        }
        else if(t[i][j-1]>t[i-1][j]){
            result.push_back(b[j-1]);
            j--;
        }
        else{
            result.push_back(a[i-1]);
            i--;
        }
        
    }
    
    while(i>0)
        result.push_back(a[i-1]),i--;
    while(j>0)
        result.push_back(b[j-1]),j--;

reverse(result.begin(),result.end());
return result;
}


int main(){
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    int m = X.length();
    int n = Y.length(); 
    vector<vector<int>> t(m+1,vector<int>(n+1));
    cout<<LCS(X,Y,m,n,t); 
    return 0;
}
