int getSubarraySum(int arr[],int n ,int sum){
    
    unordered_map<int,int> prefsum;
    int res=0;
    int cursum=0;
    
    for(int i=0;i<n;i++){
        
        cursum+=arr[i];
        
        if(cursum==sum)res++;
        
        if(prefsum.find(cursum-sum)!=prefsum.end()) 
            res+=prefsum[cursum-sum];
        prefsum[cursum]++;
    }
    
    return res;
}
