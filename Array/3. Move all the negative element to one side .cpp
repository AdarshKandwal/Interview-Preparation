void moveNegative(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        
        if(arr[i]<0){
            
            if(i!=j) 
              swap(arr[i],arr[j]);  
            
            j++;
        }
    }
   cout<<endl;
   for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}

int main(){
  
   int arr3[]={-1,3,4,-2,5,6,-1};
    moveNegative(arr3,7);
  
}
