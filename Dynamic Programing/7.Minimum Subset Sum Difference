#include<bits/stdc++.h>
using namespace std;


bool subsetSum(int arr[],int n,int sum,vector<vector<bool>> &t){
   t[0][0]=true;
   for (int i = 1; i < n+1; i++)
        t[i][0] = true;
   for (int i = 1; i <sum+1; i++)
        t[0][i] = false;
        
   for(int i=1;i<n+1;i++){
   for(int j=1;j<sum+1;j++){
       
       if(arr[i-1]<=j)
            t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j] ;
       else{
           t[i][j]=t[i-1][j];
       }
       
   }}
  return t[n][sum];
}


int main(){
    int set[] = {1,2,7};
    int sum=0;
    int n = sizeof(set) / sizeof(set[0]);
    vector<vector<bool>>t(n+1,vector<bool>(sum+1));
    for(int x: set)sum+=x;
    subsetSum(set,n,sum,t);
    vector<int>result;
    int finl=INT_MAX;
     for (int i = 0; i <(sum+1)/2; i++)
    {
         if(t[n][i]==true)
            finl=min(finl,sum-2*i);
            
    }
    cout<<finl;
    return 0;
}
