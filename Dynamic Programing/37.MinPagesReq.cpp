#include<bits/stdc++.h>
using namespace std;

int sumx(int arr[],int b, int e){
    int n=0;
    for(int i=b;i<=e;i++)
        n+=arr[i];
    return n;
}

int minPages(int arr[],int n ,int k){
    
    if(k==1)
        return sumx(arr,0,n-1);
    if(n==1)
        return arr[0];
    int result=INT_MAX;
    
    for(int i=1;i<n;i++){
        
        int temp_ans=max(minPages(arr,i,k-1),sumx(arr,i,n-1));
        result=min(result,temp_ans);
    }
    return result;
}

int main(){
    int arr[] = {12, 34, 67, 90};
    int n = sizeof arr / sizeof arr[0];
    int m = 2; //No. of students
 
    cout << "Minimum number of pages = "
         << minPages(arr, n, m) << endl;
    return 0;
}
