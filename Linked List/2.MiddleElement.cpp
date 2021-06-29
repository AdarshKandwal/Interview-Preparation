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


void PrintMiddle(Node *head){
    if(head ==NULL)return;
    Node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL ){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"Middle of linked list is :"<<slow->data;
    
}

int main(){
    
    Node *head = NULL;
    head=InsertAtEnd (head,30);
    head=InsertAtEnd(head,20);
    head=InsertAtEnd(head,10);
    head=InsertAtEnd(head,5);
    head=insertAtNthPos(head,1,100);
    PrintMiddle(head);
    return 0;
}
