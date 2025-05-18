#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAX 100

struct Node {
    int data;
    Node* next;
};
typedef Node* node;

struct List {
    node head;
    void init() {
        head = NULL;
    }

    void insert(int val) {
        node newNode = (node)malloc(sizeof(Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode; return;
        } 
        
        node temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    node getHead() {
        return head;
    }
};

struct Stack {
    int top;
    int arr[MAX];

    void init() {
        top = -1;
    }

    void push(int val) {
        if (top < MAX - 1)
            arr[++top] = val;
    }

    int pop() {
        if (top >= 0)
            return arr[top--];
        return -1;
    }

    bool isEmpty() {
        return top == -1;
    }
};

void dfs(List graph[], bool vis[], int start) {
    Stack st;
    st.init();
    st.push(start);

    while (!st.isEmpty()) {
        int curr = st.pop();
        if (!vis[curr]) {
            cout << curr << " ";
            vis[curr] = true;
        }

        node temp = graph[curr].getHead();
        while (temp != NULL) {
            int adj = temp->data;
            if (!vis[adj]) {
                st.push(adj);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    List graph[vertices];
    bool vis[vertices] = {false};

    for (int i = 0; i < vertices; i++) {
        graph[i].init();
    }

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    dfs(graph, vis, 0);

    return 0;
}
