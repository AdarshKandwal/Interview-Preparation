#include<bits/stdc++.h>
using namespace std;


int CountOfSubset(int arr[],int sum,int n,vector<vector<int>> &t){
    
    for(int i=0;i<n+1;i++)
        t[i][0]=1;
    for(int i=1;i<sum+1;i++)
        t[0][i]=0;
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
    int set[] = { 3,5,1,2 };
    int sum=8;
    int n = sizeof(set) / sizeof(set[0]);
    vector<vector<int>>t(n+1,vector<int>(sum+1));
    cout<<CountOfSubset(set,sum,n,t);
    return 0;
}
