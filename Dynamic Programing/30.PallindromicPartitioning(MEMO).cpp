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

int minPallindrome(string a,int i, int j,vector<vector<int>> &t){
    if(i>=j)
        return 0;
    if(ispallindrome(a,i,j))
        return 0;
    if(t[i][j]!=-1)
        return t[i][j];
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=minPallindrome(a,i,k,t)+minPallindrome(a,k+1,j,t)+1;
          ans = min(ans, temp);
    }
    return t[i][j]=ans;
}


int main(){
    
    string str = "ababbbabbababa";
    vector<vector<int>> t(str.length(),vector<int>(str.length(),-1));
    cout << "Min cuts needed for " <<"Palindrome Partitioning is " << minPallindrome(str, 0, str.length()-1,t) << endl;
  
    return 0;
}
