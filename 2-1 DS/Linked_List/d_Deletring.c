#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};
typedef struct Node* node;

void insert_at_end(node *head, int val) {
    node new_node = (node)malloc(sizeof(struct Node));
    new_node->val = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_at_position(node *head, int pos) {
    if (*head == NULL) return;

    if (pos == 1) {
        node to_delete = *head;
        *head = (*head)->next;
        free(to_delete);
        return;
    }

    node temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;

    node to_delete = temp->next;
    temp->next = temp->next->next;
    free(to_delete);
}

void delete_by_value(node *head, int val) {
    if (*head == NULL) return;

    node temp = *head;

    if (temp->val == val) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp->next != NULL && temp->next->val != val) {
        temp = temp->next;
    }

    if (temp->next == NULL) return;

    node dele = temp->next;
    temp->next = temp->next->next;
    free(dele);
}

void print(node head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node head = NULL;
    insert_at_end(&head, 5);
    insert_at_end(&head, 6);
    insert_at_end(&head, 7);
    insert_at_end(&head, 8);
    insert_at_end(&head, 9);
    insert_at_end(&head, 10);

    delete_by_value(&head, 5);
    delete_by_value(&head, 6);
     delete_at_position(&head, 1);

    print(head);

    return 0;
}
