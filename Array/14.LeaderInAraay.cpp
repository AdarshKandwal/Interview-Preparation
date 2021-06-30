void leaders(int arr[],int n){
    int currldr=arr[n-1];
    cout<<(currldr);
    for(int i=n-2;i>=0;i--){
        if(currldr<arr[i])
            currldr=arr[i],cout<<(currldr);
    }
}
