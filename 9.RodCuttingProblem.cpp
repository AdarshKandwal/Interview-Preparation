#include<bits/stdc++.h>
using namespace std;


int RodCuttingProblem(int val[],int wt[],int N,vector<vector<int>> &t){
    
    for(int i=0;i<N+1;i++){
    for(int j=0;j<N+1;j++){
        if(i==0||j==0)
            t[i][j]=0;
        else if(wt[i-1]<=j)
            t[i][j]=max(val[i-1]+t[i][j-wt[i-1]] , t[i-1][j]);
        else
            t[i][j]=t[i-1][j];        
    }
    }
return t[N][N];
}


int main(){
    int wt[] ={1, 2, 3,4,5,6,7,8};
    int val[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(val) / sizeof(val[0]);
    vector<vector<int>> t(n+1 ,vector<int>(n+1));
    cout<<RodCuttingProblem(val,wt,n,t);
}
