#include<bits/stdc++.h>
using namespace std;


int knapsack(int val[],int wt[],int W,int N,vector<vector<int>> &t){
    
    for(int i=0;i<N+1;i++){
    for(int j=0;j<W+1;j++){
        if(i==0||j==0)
            t[i][j]=0;
        else if(wt[i-1]<=j)
            t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]] , t[i-1][j]);
        else
            t[i][j]=t[i-1][j];        
    }
    }
return t[N][W];
}


int main(){
    int val[] ={ 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    vector<vector<int>> t(n+1 ,vector<int>(W+1));
    cout<<knapsack(val,wt,W,n,t);
}

