#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node  *left;
    Node *right;
    
    Node (int x){
        key=x;
        left=right=NULL;
    }
};

void spiralFormPrint(Node *root){
    
    stack<int> s;
    queue<Node *> q;
    q.push(root);
    bool reverse=false;
    while(q.empty() == false){
        int count=q.size();
        for(int i=0;i<count;i++){
            Node *curr=q.front();
            q.pop();
            if(reverse){
                s.push(curr->key);
            }
            else{
                cout<<curr->key;    
            }
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
        if(reverse){
            while(s.empty()==false)
                cout<<s.top()<<" ",s.pop();
        }
    reverse=!reverse;
    }
}



int main()
{   
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	
	spiralFormPrint(root);
    return 0;
}
