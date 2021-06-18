#include<bits/stdc++.h>
using namespace std;



int LongestRepeatingSubSeq(char *a , char *b,int x, int y,vector<vector<int>> &t){
    
    for(int i=0;i<x+1;i++){
    for(int j=0;j<y+1;j++){
        
        if(i==0 || j==0)
            t[i][j]=0;
            
        else if(a[i-1]==b[j-1] && i!=j)
        
            t[i][j]=1+t[i-1][j-1];
        else
            t[i][j]=max(t[i-1][j],t[i][j-1]);
    }
    }
return t[x][y];
}

int main(){
    char X[] = "AABEBCDD"; 
    char Y[] = "AABEBCDD";
      
    int m = strlen(X); 
    int n = strlen(Y); 
    vector<vector<int>> t(m+1,vector<int>(n+1));
    cout<<"Length of LCS is " ; 
    cout<<LongestRepeatingSubSeq(X,Y,m,n,t);
  
    return 0;
}
