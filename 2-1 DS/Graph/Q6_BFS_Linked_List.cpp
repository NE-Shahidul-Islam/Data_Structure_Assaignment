#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAX 100

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

typedef Node* node;

// List to represent adjacency list
struct List {
    node head=nullptr;

    void insert(int val) {
        node newNode = (node)malloc(sizeof(Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
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

// Queue using array
struct Queue {
    int front = -1, rear = -1;
    int arr[MAX];

    void enqueue(int data) {
        if ((rear + 1) % MAX == front) return; // Queue full
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = data;
    }

    int dequeue() {
        if (front == -1) return -1; // Queue empty
        int data = arr[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
        return data;
    }

    bool isEmpty() {
        return front == -1;
    }
};

// Breadth-First Search
void bfs(List graph[], bool vis[], int start) {
    Queue q;
    q.enqueue(start);
    vis[start] = true;

    while (!q.isEmpty()) {
        int curr = q.dequeue();
        cout << curr << " ";
        node temp = graph[curr].getHead();
        while (temp != NULL) {
            int adj = temp->data;
            if (!vis[adj]) {
                q.enqueue(adj);
                vis[adj] = true;
            }
            temp = temp->next;
        }
    }
}

// Main function
int main() {
    int vertex, edges;
    cin >> vertex >> edges;

    List graph[MAX]; // Use MAX for safe bounds
    bool vis[MAX] = {false};


    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u); // Undirected graph
    }

    int start;
    cin >> start; // Read starting node
    bfs(graph, vis, start);

    return 0;
}
