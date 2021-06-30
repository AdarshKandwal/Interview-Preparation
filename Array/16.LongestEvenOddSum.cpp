#include<bits/stdc++.h>
using namespace std;

int maxEvenOddSum(int arr[],int n){
    int curr=1,res=0;
    
    for(int i=1;i<n;i++){
        if( (arr[i]%2==0 && arr[i-1]%2!=0) || (arr[i]%2!=0 && arr[i-1]%2==0) )
        {
            curr++;
            res=max(res,curr);
        }
        else{
            curr=1;
        }
        
    }
    return res;
}

int main(){
    int  a[] = {1, 2, 3, 4, 5, 7, 9};
    cout<<maxEvenOddSum(a,7);
    return 0;
}
