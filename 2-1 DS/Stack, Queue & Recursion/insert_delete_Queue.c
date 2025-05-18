#include<stdio.h>
#define MAX 100
typedef struct Queue
{
    int front;
    int rear;
    int arr[MAX];
} queue;

void push(queue *q, int val) {
    if((q->rear+1)%MAX==q->front) {
        printf("Full"); return;
    }
    q->front=0;
    q->rear= (q->rear + 1)%MAX;
    q->arr[q->rear]=val;
    
}

void pop(queue *q) {
    if(q->front==-1 && q->rear==-1) {
        printf("Underflow"); return;
    }
    q->front= (q->front + 1)%MAX;
    if(q->front==q->rear) {
        q->front=-1;
        q->rear=-1;
    }
    
}
void display(queue q) {
    for(int i=q.front; i<=(q.rear)%MAX; i++) printf("%d ", q.arr[i]);
}


int main() {
    queue q;
    q.front=-1;
    q.rear=-1;
    push(&q, 10);
    push(&q, 20);
    push(&q, 30);
    push(&q, 40);
    display(q);
}