#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

Node *InsertAtEnd(Node *head,int datax){
    Node *curr=head;
    Node *temp=new Node(datax);
    if(head==NULL)
        return temp;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=temp;
    return head;
}

Node *insertAtNthPos(Node *head,int pos,int datax){
        Node *temp=new Node(datax);
    if(pos==1){
    temp->next=head;
    return temp;
    }
    Node *curr=head;
    for(int i=1;i<=pos-2 && curr != NULL ; i++){
        curr=curr->next;
    }
    if(curr==NULL)
        return head;
    temp->next=curr->next;
    curr->next=temp;
    return head;
}


Node *reversenthNodes(Node *head , int n){
   Node *curr=head,*next=NULL,*prev=NULL;
   int count=0;
   while(curr!=NULL && count<n){
       next=curr->next;
       curr->next=prev;
       prev=curr;
       curr=next;
       count++;
   }
   if(next!=NULL){
       Node *rest_head=reversenthNodes(next,n);
       head->next=rest_head;
   }
   return prev;
}

void printLinkedList(Node *head){
    
    Node *curr=head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main(){
    
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
	head->next->next->next->next->next=new Node(60);
	head->next->next->next->next->next->next=new Node(70);
    head=reversenthNodes(head,3);
    printLinkedList(head);
    return 0;
}
