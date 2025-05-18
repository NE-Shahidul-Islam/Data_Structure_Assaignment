#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node* node;

void insert(node *head, int val) {
    node new_node = (node)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node temp = (*head);
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void print(node head) {
    while(head!=NULL) {
        printf("%d ", head->data);
        head=head->next;
    }
    printf("\n");
}


void sortList(node head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    for (node i = head; i != NULL; i = i->next) {
        for (node j = i->next; j != NULL; j = j->next) {
            if (j->data < i->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main() {
    node head = NULL;
    insert(&head, 5);
    insert(&head, 3);
    insert(&head, 9);
    insert(&head, 42);
    insert(&head, 0);    
    insert(&head, 10);

    print(head);

    sortList(head);
    printf("Sorted list: ");
    print(head);

    return 0;
}
