#include<bits/stdc++.h>
using namespace std;

void Printlcs(char *a , char *b , int x ,int y,vector<vector<int>> &t){
    
    for(int i=0;i<x+1;i++){
    for(int j=0;j<y+1;j++){
     if(i==0 || j==0)
        t[i][j]=0;
    else if(a[i-1] == b[j-1])
        t[i][j]=1+t[i-1][j-1];     
    else
        t[i][j]=max(t[i-1][j],t[i][j-1]);
    }}
    
    int j=y,i=x;
    string result;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            result.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j])
                j--;
            else
                i--;
        }
    }
    reverse(result.begin(),result.end());
    cout<<"the result is "<<result;
}


int main()
{
    char X[] = "AGGTAB"; 
    char Y[] = "GXTXAYB"; 
      
    int m = strlen(X); 
    int n = strlen(Y); 
    vector<vector<int>> t(m+1,vector<int>(n+1));
    Printlcs(X,Y,m,n,t);
  
    return 0;
    
}
