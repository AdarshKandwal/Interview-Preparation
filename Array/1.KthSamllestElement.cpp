#include<bits/stdc++.h>
using namespace std;

//Problem 1. Kth smallest element in array
int ksmallest(int arr[] ,int k,int n){
    
    set<int> s;
    for(int i=0;i<n;i++)s.insert(arr[i]);
    
    auto itr=s.begin();
    for(int i=0;i<k-1;i++)
        itr++;
    return *itr;
    }
    
int main(){
int arr[]={4,3,1,2,5,6};
int n=6;
int k=4;
cout<<ksmallest(arr,k,n);
return 0;
}
