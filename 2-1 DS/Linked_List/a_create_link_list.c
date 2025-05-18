#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int  data;
    struct Node* next;
};
typedef struct Node* node;
void insert(node *head, int val) {
    node new_node = (node)malloc(sizeof(struct Node));
    new_node->data=val;
    new_node->next=NULL;

    if(*head==NULL) {
        *head=new_node; return;
    }
    node temp = *head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=new_node;
}

void print(node head) {
    while(head!=NULL) {
        printf("%d ", head->data);
        head=head->next;
    }
    printf("\n");
}


int main() {
    node head = NULL;
   for(int i=0; i<n; i++) {
    cin >> a[i];
    insert(&head, a[i]);
   }
    print(head);    


}
