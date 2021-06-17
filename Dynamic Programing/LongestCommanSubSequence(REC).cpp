#include<bits/stdc++.h>
using namespace std;

#define NIL INT_MAX-1

int LongestCommonSubsequence(char *a , char *b ,int i,int j){
    if(i==0 || j==0)
        return 0;
    if(a[i-1]==b[j-1])
        return 1+LongestCommonSubsequence(a,b,i-1,j-1);
    else
        return max(LongestCommonSubsequence(a,b,i,j-1),LongestCommonSubsequence(a,b,i-1,j));
}

int main(){
    char X[] = "AGGTAB"; 
    char Y[] = "GXTXAYB"; 
      
    int m = strlen(X); 
    int n = strlen(Y); 
      
    cout<<"Length of LCS is "<< LongestCommonSubsequence( X, Y, m, n ) ; 
    return 0;
}
