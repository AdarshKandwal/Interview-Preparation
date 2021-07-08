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


Node *insert(Node *root,int x){
    if(root ==  NULL)
        return new Node(x);
    if(x<root->key)
        root->left= insert(root->left,x);
    else if(x>root->key)
        root->right=insert(root->right,x);
 return root;   
}

void search(Node *root,int x){
    if(root==NULL){
        cout<<"is bst";
        return ;
    }
    else if(root->key==x){
        cout<<"found";
        return;
    }
    else if(root->key>x){
        search(root->left,x);
    }
    else{
        search(root->right,x);
    }
}

Node *getSuccessor(Node *curr){
    curr=curr->right;
    while(curr!=NULL && curr->left != NULL)
        curr=curr->left;
    return curr;
}

Node *delNode(Node *root , int x){
    if(root==NULL)  
        return root;
    if(root->key>x)
        root->left=delNode(root->left,x);
    else if(root->key<x)
        root->right=delNode(root->right,x);
    else{
        if(root->left==NULL){
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node *succ=getSuccessor(root);
            root->key=succ->key;
            root->right=delNode(root->right,succ->key);
        }
    }
    return root;
}

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
}

int main(){
    
    Node* root = NULL;
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };
 
    for (int x : keys)
        root = insert(root, x);
    //search(root,8);
    root=delNode(root,12);
    inorder(root);
    return 0;
}
