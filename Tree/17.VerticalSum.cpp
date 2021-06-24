#include<bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left;
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};


void VsumR(Node *root,int hd,map<int,int> &mp){
    
    if (root == NULL)   return ;
    VsumR(root->left,hd-1,mp);
    mp[hd]=mp[hd]+root->key;
    VsumR(root->right,hd+1,mp);
}

void VsumRhelper(Node *root){
    map<int,int> mp;
    VsumR(root,0,mp);
    for(auto sum:mp) 
        cout<<sum.second<<" ";
}

int main(){
    
	Node *root = new Node(10);  
    root->left = new Node(20);  
    root->right = new Node(50);  
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    
    VsumRhelper(root);
    return 0;
}
