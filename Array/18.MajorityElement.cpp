#include<bits/stdc++.h>
using namespace std;

int majority(int arr[],int n){
    int res=0,count=1;
    for(int i=1;i<n;i++){
        if(arr[res]==arr[i])
            count++;
        else
            count--;
        if(count ==0) res=i,count=1;
    }
    count=0;
    for(int i=0;i<n;i++)
        if(arr[res]==arr[i])
            count++;
        if(count<=n/2)
            res=-1;
    return res;
}

int main(){
    int arr[] = {8, 8, 6, 6, 6, 4, 6}, n = 7;
    cout<<majority(arr,n);
    return 0;
}

//MY Approch
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={8,3,4,8,8};
    unordered_map<int,pair<int,int>> m;
    for(int i=0;i<5;i++){
        if(m.find(arr[i])!=m.end()){
            m[arr[i]].first=m[arr[i]].first+1;
        }
        else{
             m[arr[i]].first=m[arr[i]].first+1;
             m[arr[i]].second=i;
        }
    }
    for(int i=0;i<5;i++){
        cout<<m[arr[i]].first<<"->"<<m[arr[i]].second;
        cout<<endl;
    }
    return 0;
}
