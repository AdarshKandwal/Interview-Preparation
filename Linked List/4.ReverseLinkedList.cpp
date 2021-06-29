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


Node *reverse(Node * head){
    if(head==NULL || head->next ==NULL)
        return head;
    Node *recHead=reverse(head->next);
    Node *recTail=head->next;
    recTail->next=head;
    head->next=NULL;
    return recHead;
        
}

Node *reverse2(Node *head){
    if(head==NULL || head->next == NULL)
        return head;
    Node *curr=head,*prev=NULL,*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
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
    
    Node *head = NULL;
    head=InsertAtEnd (head,30);
    head=InsertAtEnd(head,20);
    head=InsertAtEnd(head,10);
    head=InsertAtEnd(head,5);
    head=insertAtNthPos(head,1,100);
    head=reverse2(head);
    printLinkedList(head);
    return 0;
}
