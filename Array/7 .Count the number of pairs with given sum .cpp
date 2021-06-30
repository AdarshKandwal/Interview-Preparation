int getPairSum(int arr[],int n ,int sum){
    int c=0;
    unordered_map<int,int> m;
    
    for(int i=0;i<n;i++){
        
        int temp=sum-arr[i];
        
        if(m[temp]==0){
            m[arr[i]]++;
        }
        else{
            c+=m[temp];
            m[arr[i]]++;
        }
        
    }
    
    return c;
}
