#include<stdio.h>
#define MAX 100

typedef struct Stack
{
    int top;
    int arr[MAX];
} stack;

void push( stack *st, int val) {
    if((*st).top==MAX-1) {
        printf("Overflow"); return;
    }
    st->arr[++(st->top)]=val;
}

void display(stack st) {
    for(int i=st.top; i>=0; i--) printf("%d ", st.arr[i]);
}
void pop(stack *st) {
    if(st->top==-1) {
         printf("Underflow"); return;
    }
    st->top--;
}



int main(){
    stack st;
    st.top=-1;
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 10);
    pop(&st);
    display(st);
    return 0;
}

