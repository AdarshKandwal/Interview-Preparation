//problem 4.Maximum contigous sum 

int maxcontigousSum(int arr[],int n){
    
    int maxendinghere=0;
    int maxcontsum=INT_MIN;
    
    for(int i=0;i<n;i++)
    {
    maxendinghere+=arr[i];
    
    if(maxcontsum<maxendinghere) 
        maxcontsum=maxendinghere;
    
    if(maxendinghere<0)
        maxendinghere=0;
    }
    
    return maxcontsum;
}

int main(){
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout<<endl;
    cout<<maxcontigousSum(a,8);
 return 0; 
}
