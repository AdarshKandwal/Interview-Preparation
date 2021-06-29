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
 

bool CheckLoop(Node *head){
    Node *temp=new Node(0);
    Node *curr=head;
    while(curr!=NULL){
        
        if(curr->next == NULL)
            return false;
        if(curr->next == temp)
            return true;
            
        Node *currnext=curr->next;
        curr->next=temp;
        curr=currnext;
    }
    return false;
}

bool CheckLoopHashing(Node *head){
    unordered_set<Node *> s;
    for(Node *curr=head;curr!=NULL;curr=curr->next)
    {
        if(s.find(curr)!=s.end())
            return true;
        s.insert(curr);
    }
    return false;
}

int main(){
    
    Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    head->next->next->next->next = head;
      if (CheckLoopHashing(head))
        cout << "Loop found";
    else
        cout << "No Loop";
    return 0;
    return 0;
}
