#include<bits/stdc++.h>
using namespace std;

int solve(int e , int f,vector<vector<int>> &t){
    
    if(f==0 || f==1)
        return f;
    if(e==1)
        return f;
        
    if(t[e][f]!=-1)
        return t[e][f];
    int mn=INT_MAX;
    
    for(int k=1;k<=f;k++){
        int temp=1+max(solve(e-1,k-1,t),solve(e,f-k,t));
        mn=min(mn,temp);
    }
return t[e][f]=mn;
}

int main(){
    int n = 2, k = 36;
    vector<vector<int>>t(n+1,vector<int>(k+1,-1));
    cout<<solve(n,k,t);
    return 0;
}
