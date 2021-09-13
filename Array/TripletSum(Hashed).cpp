#include<bits/stdc++.h>
using namespace std;

bool findTripletsum(vector<int> arr,int sum){
    int n=arr.size();
  
    for(int i=0;i<n-2;i++){
        unordered_set<int> s;
        int curr=sum-arr[i];
        for(int j=i+1;j<n;j++){
            if(s.find(curr-arr[j])!= s.end()){
                return true;
            }
            s.insert(arr[j]); 
        }
    }
    return false;
}
int main(){
    vector<int> arr={1 ,4 ,45 ,6 ,10 ,8};
    cout<<findTripletsum(arr,13); 
}
