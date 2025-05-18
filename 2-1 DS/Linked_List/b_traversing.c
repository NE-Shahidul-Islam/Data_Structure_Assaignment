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

    node temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void print(node head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void Traversing(node head) {
    if (head == NULL) return;

    int maximum = INT_MIN, minimum = INT_MAX, tot = 0;
    int len = 0;

    printf("Sin values:\n");
    node temp = head;
    while (temp != NULL) {
        int val = temp->data;
        if (val > maximum) maximum = val;
        if (val < minimum) minimum = val;
        tot += val;
        printf("sin(%d) = %.2f\n", val, sin(val));
        temp = temp->next;
        len++;
    }

    printf("Maximum Value: %d\n", maximum);
    printf("Minimum Value: %d\n", minimum);
    printf("Total Value: %d\n", tot);
    printf("Average Value: %.2f\n", (double)tot / len);
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
    Traversing(head);

    return 0;
}
