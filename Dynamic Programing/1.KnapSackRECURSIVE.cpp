#include<bits/stdc++.h>
using namespace std;



int knapsack(int val[],int wt[],int N, int W)
{
    
    if(N==0 || W==0)
        return 0;
    else if(wt[N-1]<=W){
        return max( (val[N-1] + knapsack(val,wt,N-1,W-wt[N-1])), (knapsack(val,wt,N-1,W))  ); 
    }
    else
        return(val,wt,N-1,W);
}


int main(){
    
    int val[] ={ 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(val, wt, n, W);
    return 0;
}
