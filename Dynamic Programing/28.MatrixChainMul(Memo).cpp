#include<bits/stdc++.h>
using namespace std;

int SolveMcm(int arr[],int i, int j,vector<vector<int>> &t){
    if(i>=j)
        return 0;
    if(t[i][j]!=-1)
        return t[i][j];
    int minans=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int count=SolveMcm(arr,i,k,t)+SolveMcm(arr,k+1,j,t)+arr[i-1]*arr[k]*arr[j];
        if (count < minans)
            minans = count;
    }
    return t[i][j]=minans;
}

int main(){
    int arr[] = { 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int>> t(n,vector<int>(n,-1));
    cout << "Minimum number of multiplications is "<< SolveMcm(arr, 1, n-1 ,t); 
    return 0;
}
