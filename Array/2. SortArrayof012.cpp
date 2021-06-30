void sort012(int arr[],int n){
    
   int low=0,mid=0;
   int high=n-1;
   
   while(mid <= high){
       switch(arr[mid]){
           
           case 0:
                swap(arr[low++],arr[mid++]);break;
                
           case 1:
                mid++;break;
                
           case 2:
                swap(arr[mid],arr[high--]);break;
                
       }
   }
   cout<<endl;
   for(int i=0;i<n;i++) cout<<arr[i]<<" ";
   
}

int main(){
  
  int arr2[]={1,0,1,2,0};
   sort012(arr2,5);
  return 0;
