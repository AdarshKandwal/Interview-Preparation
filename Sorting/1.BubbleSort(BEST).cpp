#include<bits/stdc++.h>
using namespace std;

void bubleSort(vector<int> &arr){
    for(int i=0;i<arr.size()-1;i++){
        bool swapped=false;
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){
                swapped=true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(swapped==false)
            break;
    }
}

int main(){
    vector<int> arr={5,4,1,2,3};
    bubleSort(arr);
    for(auto x:arr)
        cout<<x<<" ";
    return 0;
}
