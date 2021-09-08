#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &arr){
    int i=arr.size()-2;
    while(i>=0 && arr[i]>=arr[i+1]){
        i--;
    }
    if(i>0){
        int j=arr.size()-1;
        while(arr[j]<=arr[i]){
            j--;
        }
        swap(arr[i],arr[j]);
    }
    reverse(arr.begin()+i+1,arr.end());
    
    for( int x : arr){
        cout<<x<<" ";
    }
}


int main(){
    vector<int> arr={1,3,5,4,2};
    nextPermutation(arr);
    
    return 0;
}
