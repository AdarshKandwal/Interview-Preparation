//Problem 15 Maximum Difference B/W element

int maxDiff(int arr[],int n ){
    int res=arr[1]-arr[0];
    int minval=arr[0];
    for(int i=1;j<n;j++)
    {
        res=max(res,arr[j]-minval);
        minval=min(minval,arr[j]);
    }
    
    return res;
}
