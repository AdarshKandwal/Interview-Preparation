#include<bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int min_ind=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_ind])
                min_ind=j;
        }
        swap(arr[min_ind],arr[i]);
    }
}

int main(){
    vector<int> arr={5,4,1,2,3};
    SelectionSort(arr);
    for(auto x:arr)
        cout<<x<<" ";
    return 0;
}
