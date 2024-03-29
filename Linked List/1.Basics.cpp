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


void printLinkedList(Node *head){
    
    Node *curr=head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

void printLinkedListRec(Node *head){
    if(head==NULL)
        return;
    cout<<head->data;
    printLinkedListRec(head->next);
}


Node *InsertAtBeg(Node *head,int datax){
    Node *temp=new Node(datax);
    temp->next=head;
    return temp;
    
}

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

Node *deleteFirstNode(Node *head){
    
    if(head==NULL) return NULL;
    else{
        Node *curr=head;
        head=head->next;
        delete(curr);
        return head;
    }
}

Node *deleteLastNode(Node *head){
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next->next !=NULL)
        curr=curr->next;
    delete(curr->next);
    curr->next=NULL;
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

int main(){
    
    Node *head = NULL;
    head=InsertAtEnd(head,30);
    head=InsertAtEnd(head,20);
    head=InsertAtEnd(head,10);
    head=InsertAtEnd(head,5);
    head=insertAtNthPos(head,1,100);
    printLinkedListRec(head);
    return 0;
}
