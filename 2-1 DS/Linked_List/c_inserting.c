#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    struct Node* next;
};
typedef struct Node* node;

void insert_at_end(node *head, int val){
    node new_node = (node)malloc(sizeof(struct Node));
    new_node->val=val;
    new_node->next=NULL;

    if(*head==NULL) {
        *head = new_node;
        return;
    }
    node temp = *head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=new_node;
}

void insert_at_head(node *head, int val){
    node new_node = (node)malloc(sizeof(struct Node));
    new_node->val=val;
    new_node->next=NULL;
    if(*head==NULL) {
        *head = new_node; return;
    }
    new_node->next=*head;
    *head=new_node;
}

void insert_at_any_position(node *head, int pos, int val) {
     node new_node = (node)malloc(sizeof(struct Node));
    new_node->val=val;
    new_node->next=NULL;

    node temp = *head;
    for(int i=1; i<=pos-2; i++) temp=temp->next;

    new_node->next=temp->next;
    temp->next=new_node;
}


void print(node head) {
    while(head!=NULL) {
        printf("%d ", head->val);
        head=head->next;
    }
    printf("\n");
}



int main() {
    node head = NULL;
    insert_at_end(&head, 5);
    insert_at_end(&head, 6);
    insert_at_end(&head, 7);
    insert_at_any_position(&head, 2, 2);

    print(head);
   
    
}