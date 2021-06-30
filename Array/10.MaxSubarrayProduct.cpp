int maxSubArrayProduct(int arr[],int n){
    int max_end_here=1;
    int min_end_here=1;
    int max_so_far=0;
    int flag=0;
    for(int i=0;i<n;i++){
        
        if(arr[i]>0){
            max_end_here=max_end_here*arr[i];
            min_end_here=min(min_end_here*arr[i],1);
            flag=1;
        }
        else if(arr[i]==0)
            max_end_here=min_end_here=1;
        else{
            int temp=max_end_here;
            max_end_here=max(min_end_here*arr[i],1);
            min_end_here=temp*arr[i];
        }
        if(max_so_far<max_end_here)
            max_so_far=max_end_here;
    }
    if(flag==0 && max_so_far==0) return 0;
    return max_so_far;
}
