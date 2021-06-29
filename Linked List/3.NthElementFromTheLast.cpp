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


void PrintNthElementFromLast(Node *head,int n){
    int len=0;
    for(Node *curr=head;curr!=NULL;curr=curr->next)
        len++;
    if(len<n)
        return;
    Node *curr=head;
    for(int i=1;i<len+1-n;i++)
        curr=curr->next;
    cout<<endl<<"Nth Element from the last :" <<curr->data<<" ";
}

void PrintNthElementFromLastOptimal(Node *head,int n){
    if(head==NULL)  return;
    Node *second=head,*first=head;
    for(int i=1;i<=n;i++){
        if(second==NULL)return;
        second=second->next;
    }
    while(second!=NULL){
        first=first->next;
        second=second->next;
    }
    cout<<first->data;
}

int main(){
    
    Node *head = NULL;
    head=InsertAtEnd (head,30);
    head=InsertAtEnd(head,20);
    head=InsertAtEnd(head,10);
    head=InsertAtEnd(head,5);
    head=insertAtNthPos(head,1,100);
    PrintNthElementFromLastOptimal(head,3);
    return 0;
}
