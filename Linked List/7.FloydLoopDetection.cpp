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
 

bool isLoop(Node *head){
    
    Node *slow_P=head,*fast_p=head;
    while(fast_p->next !=NULL && fast_p != NULL){
        slow_P=slow_P->next;
        fast_p=fast_p->next->next;
        if(slow_P->next == fast_p->next)
            return true;
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
      if (isLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
    return 0;
}
