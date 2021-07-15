#include<bits/stdc++.h>
using namespace std;

int KthSmallestElement(int arr[],int n,int k){
set<int> s(arr,arr+n);
auto temp=s.begin();
for(int i=0;i<k-1;i++)
        temp++;
return *temp;
}

void sort012(int arr[],int n){
    int mid=0,low=0,high=n-1;


    while(mid<=high){
    switch(arr[mid]){

        case 0:
            swap(arr[low++],arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid],arr[high--]);
            break;
    }
    }


for(int i=0;i<n;i++)
        cout<<arr[i];
}

void KadanesAlgo(int arr[],int n){
    int max_ending_here=INT_MIN;
    int max_curr_here=0;
    for(int i=0;i<n;i++){
        max_curr_here+=arr[i];
        if(max_ending_here<max_curr_here)
            max_ending_here=max_curr_here;
        else if(max_curr_here<0)
            max_curr_here=0;
    }
    cout<<max_ending_here;
}

void rearrangeElement(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            if(i!=j)
                swap(arr[i],arr[j]);
            j++;
        }
    } 
    for(int i=0;i<n;i++)
        cout<<arr[i];
}

vector<vector<int>>merge_interval(vector<vector<int>> &intervals){
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> merged_interval;
    vector<int> temp=intervals[0];
    for(auto x: intervals)
    {
        if(temp[1]>=x[0]){
            temp[1]=max(temp[1],x[1]);
   
        }
        else{
         
            merged_interval.push_back(temp);
            temp=x;
        }
    }
    merged_interval.push_back(temp);
    return merged_interval;
}


int merge(int arr[],int l,int mid,int r){
    int res=0;
    int n1=(mid-l)+1;
    int n2=r-mid;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)
        left[i]=arr[l+i];
    for(int j=0;j<n2;j++)
        right[j]=arr[mid+j+1];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<right[j]){
            arr[k++]=left[i++];
        }
        else{
            arr[k++]=right[j++];
            res+=(n1-i);
        }
    }
    while(i<n1){
        arr[k++]=left[i++];
    }
    while(j<n2){
        arr[k++]=left[j++];
    }
    return res;
}

int merge_sort(int arr[],int i,int j){
    int res=0;
    if(j>i){
    int mid=i+(j-i)/2;
    res+=merge_sort(arr,i,mid);
    res+=merge_sort(arr,mid+1,j);
    res+=merge(arr,i,mid,j);
    }
return res;
}

int main(){
int arr[]={1,2,3,5,4};
cout<<merge_sort(arr,0,4);


return 0;
}
