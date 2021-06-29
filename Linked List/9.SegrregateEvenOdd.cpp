
#include<bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
        
};
 
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

Node *segregate(Node *head){
    Node *evenStart=NULL,*evenEnd=NULL,*oddStart=NULL,*oddEnd=NULL;
    for(Node *curr=head;curr!=NULL;curr=curr->next){
        int x=curr->data;
        if(x%2==0){
            if(evenStart==NULL) evenStart=curr,evenEnd=evenStart;
            else evenEnd->next=curr, evenEnd=evenEnd->next;
        }
        else{
            if(oddStart==NULL) oddStart=curr,oddEnd=oddStart;
            else oddEnd->next=curr,oddEnd=oddEnd->next;
        }
    }
    if(oddStart==NULL || evenStart==NULL)
        return head;
    evenEnd->next=oddStart;
    oddEnd->next=NULL;
    return evenStart;
}

void printLinkedList(Node *head){
    
    Node *curr=head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
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


int main(){
    
    Node* head = NULL;
    
    head=InsertAtEnd(head,1);
    head=InsertAtEnd(head,20);
    head=InsertAtEnd(head,10);
    head=InsertAtEnd(head,5);
    printLinkedList(head);
    cout<<endl;
    head=segregate(head);
    printLinkedList(head);
    
    return 0;
}

