#include<bits/stdc++.h>
using namespace std;


int TargetSum(int arr[],int sum,int n,vector<vector<int>> &t){
    
    t[0][0]=1;
    for(int i=1;i<n+1;i++)
        t[i][0]=1;
    for(int j=1;j<sum+1;j++)
        t[0][j]=0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
        if(arr[i-1]<=j)
            t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
        else
            t[i][j]=t[i-1][j];
        }
    }
    
    
    return t[n][sum];
}

int main(){
    int arr[]={1,1,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int diff=1;
    int sum=0;
    for(int x:arr)
        sum+=x;
    int final=(sum+diff)/2;
    vector<vector<int>> t(n+1 ,vector<int>(final+1));
    cout<<TargetSum(arr,final,n,t);
}
