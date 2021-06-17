#include<bits/stdc++.h>
using namespace std;
#define NIL INT_MAX-1

int MinCoinChangeProblem(int arr[],int sum,int n,vector<vector<int>> &t){
    
    t[0][0]=NIL;
    
    for(int i=1;i<n+1;i++)
        t[i][0]=0;
    for(int i=1;i<sum+1;i++)
        t[0][i]=NIL;
    
    for(int i=1;i<sum+1;i++){
        if(i%arr[0]==0)
            t[1][i]=i/arr[0];
        else
            t[1][i]=NIL;
    }
    
    for(int i=2;i<n+1;i++){
    for(int j=1;j<sum+1;j++){
        if(arr[i-1]<=j)
            t[i][j]=min(1+t[i][j-arr[i-1]],t[i-1][j]);
        else
            t[i][j]=t[i-1][j];
    }
    }
return t[n][sum];
}

int main(){
    int arr[]={9, 6, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int>> t(n+1 ,vector<int>(11+1));
    cout<<MinCoinChangeProblem(arr,11,n,t);  
    return 0;
}
