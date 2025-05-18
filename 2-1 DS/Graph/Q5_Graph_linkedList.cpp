#include <iostream>
#include <stdlib.h>
using namespace std;

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
            head = newNode;
        } else {
            node temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    node getHead() {
        return head;
    }
};

int main() {
    int vertices, edges;
    //Enter number of vertices and edges
    cin >> vertices >> edges;

    List graph[vertices];
    for (int i = 0; i < vertices; i++) {
        graph[i].init();
    }

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);  // If undirected graph
    }

    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        node temp = graph[i].getHead();
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    return 0;
}
