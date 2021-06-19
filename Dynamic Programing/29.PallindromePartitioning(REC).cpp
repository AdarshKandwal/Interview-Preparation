#include<bits/stdc++.h>
using namespace std;

bool ispallindrome(string a,int i , int j){
     while(i < j)
    {
      if(a[i] != a[j])
        return false; 
      i++;
      j--;
    }
    return true;
}

int minPallindrome(string a,int i, int j){
    if(i>=j)
        return 0;
    if(ispallindrome(a,i,j))
        return 0;
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=minPallindrome(a,i,k)+minPallindrome(a,k+1,j)+1;
          ans = min(ans, temp);
    }
    return ans;
}


int main(){
    string str = "ababbbabbababa";
    cout << "Min cuts needed for " <<"Palindrome Partitioning is " << minPallindrome(str, 0, str.length()-1) << endl;
    
    return 0;
}
