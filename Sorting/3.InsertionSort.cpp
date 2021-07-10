#include<bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    vector<int> arr={5,4,1,2,3};
    InsertionSort(arr);
    for(auto x:arr)
        cout<<x<<" ";
    return 0;
}
