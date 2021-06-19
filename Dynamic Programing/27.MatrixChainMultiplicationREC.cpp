#include<bits/stdc++.h>
using namespace std;

int SolveMcm(int arr[],int i, int j){
    if(i>=j)
        return 0;
    int minans=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int count=SolveMcm(arr,i,k)+SolveMcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if (count < minans)
            minans = count;
    }
    return minans;
}

int main(){
    int arr[] = { 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of multiplications is "<< SolveMcm(arr, 1, n-1 ); 
    return 0;
}
