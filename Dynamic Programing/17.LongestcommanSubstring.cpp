#include<bits/stdc++.h>
using namespace std;



int LongestCommonSubsequenceDP(char *a , char *b,int x, int y,vector<vector<int>> &t){
    
    for(int i=0;i<x+1;i++){
    for(int j=0;j<y+1;j++){
        
        if(i==0 || j==0)
            t[i][j]=0;
            
        else if(a[i-1]==b[j-1])
        
            t[i][j]=1+t[i-1][j-1];
        else
            t[i][j]=0;
    }
    }
return t[x][y];
}

int main(){
    char X[] = "AGGTAB"; 
    char Y[] = "GXTXAB"; 
      
    int m = strlen(X); 
    int n = strlen(Y); 
    vector<vector<int>> t(m+1,vector<int>(n+1));
    cout<<"Length of LCS is " ; 
    cout<<LongestCommonSubsequenceDP(X,Y,m,n,t);
  
    return 0;
}
