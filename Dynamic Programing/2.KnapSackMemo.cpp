#include<bits/stdc++.h>
using namespace std;


int knapsackMemoized(int val[],int wt[],int W,int N , vector<vector<int>> &t){
    
    if(N==0||W==0)
        return 0;
    if(t[N][W]!=-1)
        return t[N][W];
        
    if( wt[N-1]<=W){
        t[N][W]=max((val[N-1]+knapsackMemoized(val,wt,W-wt[N-1],N-1,t)),(knapsackMemoized(val,wt,W,N-1,t)));
        return t[N][W];
    }
    else if(wt[N-1]>W){
       t[N][W]=(knapsackMemoized(val,wt,W,N-1,t));
       return t[N][W];
    }
    
}

int main(){
        
    int val[] ={ 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    
    vector<vector<int>> t( n+1, vector<int> (W+1, -1));
    
    cout<<knapsackMemoized(val,wt,W,n,t);
    
}
