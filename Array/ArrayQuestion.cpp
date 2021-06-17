#include<bits/stdc++.h>
using namespace std;

//Problem 1. Kth smallest element in array
int ksmallest(int arr[] ,int k,int n){
    
    set<int> s;
    for(int i=0;i<n;i++)s.insert(arr[i]);
    
    auto itr=s.begin();
    for(int i=0;i<k-1;i++)
        itr++;
    return *itr;
    
}
//problem 2. Sort array of 012

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

//problem 3. Move all the negative element to one side 

void moveNegative(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        
        if(arr[i]<0){
            
            if(i!=j) swap(arr[i],arr[j]);  
            
            j++;
        }
    }
   cout<<endl;
   for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}

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

//problem 5. merge interval problem

vector<vector<int>> merege ( vector<vector<int>> &interval){
    
    vector<vector<int>> meregedinterval;
    if(interval.size()==0) return meregedinterval;
    sort(interval.begin(),interval.end());
    vector<int> temp= meregedinterval[0];
    
    for(auto it:interval){
        if(it[0]<=temp[1])
            temp[1]=max(it[1],temp[1]);
        else 
            meregedinterval.push_back(temp),temp=it;
    }
    
    meregedinterval.push_back(temp);
    return meregedinterval;
    
}

//problem 6 . Count inversion problem


int merge(int arr[],int temp[],int left, int mid,int right){
    int i,j,k;
    int inv_count=0;
    i=left,j=mid,k=left;  //k is the number of temp array 
    
    while((i<=mid-1) && (j<=right)){
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            inv_count=inv_count+(mid-i);
        }
    }
    while(i<= mid-1)temp[k++]=arr[i++];
    while(j<=right)temp[k++]=arr[j++];
    
    for(int i=left ; i<=right ; i++) arr[i]=temp[i];
    
    return inv_count;
}



int mergesort(int arr[], int temp[], int left, int right){
    int mid , inv_count=0;
    if(right>left){
        mid=(right+left)/2;
        inv_count+= mergesort(arr,temp,left,mid);
        inv_count+= mergesort(arr,temp,mid+1,right);
        inv_count+=merge(arr,temp,left,mid+1,right);
    }
    
    return inv_count;
}


int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

//problem 7 : Count the number of pairs with given sum :-

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

//problem 8 : Number of subarray having sum equal to ksmallest

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

//problem 9 : minimum number of jumps to reach end of an array 
int minJumps(int arr[], int n)
{
    // jumps[n-1] will hold the result
    int* jumps = new int[n];
    int i, j;
 
    if (n == 0 || arr[0] == 0)
        return INT_MAX;
 
    jumps[0] = 0;
 
    // Find the minimum number of jumps to reach arr[i]
    // from arr[0], and assign this value to jumps[i]
    for (i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++) {
            if (i <= j + arr[j] && jumps[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}
//problem 10 : maximum subarray product 
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

//problem 11 : Trapping water problem:

int trap(vector<int> & height){
    int n=height.size();
    int trapped=0;
    if(n<=2) return 0;
    int left=1;
    int right=n-2;
    int maxRight=height[0];
    int maxLeft=height[n-1];
    while(left <=right){
        if(maxLeft<maxRight){
            
            if(height[left]>maxLeft){
                maxLeft=height[left];
            }
            else{
                trapped=trapped+(maxLeft-height[left]);
            }
            
        left+=1;
        }
        else{
          if(height[right]>maxRight)
            maxRight=height[right];
          else
              trapped =trapped+ (maxRight-height[right]);
          
          right=right-1;
        }
    }
    return trapped;
}

//problem 12 Longest Consecutive Sequence 

int LongestConsecutive(vector<int> & nums)
{
 set<int> hasset;
 for(int num : nums) hasset.insert(num);
 int LongestStreak=0;
for(int num : nums){
    if(!hasset.count(num-1))
    {
        int currentNum=num;
        int currentStreak=1;
        while(hasset.count(currentStreak+1)){
            currentNum+=1;
            currentStreak+=1;
        }
        LongestStreak=max(LongestStreak,currentStreak);
    }
}
return LongestStreak;
}

//problem 13 Left rotate array by k

void leftRotate(int arr[],int n ,int d){
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }
    for(int i=0;i<d;i++){
        arr[n-d+i]=temp[i];
    }
}

//Problem 14 Leader of the array 

void leaders(int arr[],int n){
    int currldr=arr[n-1];
    cout<<(currldr);
    for(int i=n-2;i>=0;i--){
        if(currldr<arr[i])
            currldr=arr[i],cout<<(currldr);
    }
}

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

int main(){
    
    /*
    int arr[]={4,3,1,2,5,6};
    int n=6;
    int k=4;
    cout<<ksmallest(arr,k,n);\
    int arr2[]={1,0,1,2,0};
    sort012(arr2,5);
    int arr3[]={-1,3,4,-2,5,6,-1};
    moveNegative(arr3,7);
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout<<endl;
    cout<<maxcontigousSum(a,8);
    int arrx[]={1, 20, 6, 4, 5 };
    int temp[5];
    cout<<endl;
    cout<<mergesort(arrx,temp,0,5-1);
    cout<<getSubarraySum(arrx,5,15);
    int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
    cout << "Maximum Sub array product is "<< maxSubArrayProduct(arr, 7);
    cout<<trap(arr);
    
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(10);
    arr.push_back(4);
    arr.push_back(20);
    cout<<LongestConsecutive(arr);
     
    leftRotate(arr,5,2);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
 
    */
    int arr[]={7,10,4,10,6,5,2};
    leaders(arr,7);

}
