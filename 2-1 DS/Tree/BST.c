/*
Write a program to insert an element in a Binary search tree; if the element already inserted before then
display the location.
*/
#include<stdio.h>
#include<stdlib.h>

struct Tree
{
    int val;
    struct Tree* left;
    struct Tree* right;
};

typedef struct Tree* tree;

void insert(tree *root, int val) {
    if(*root==NULL) {
        tree new_node = (tree)(malloc(sizeof(struct Tree)));
        new_node->val=val;
        (new_node)->left=NULL;
        (new_node)->right=NULL;
        *root=new_node;
        return;
    }
    if(val==(*root)->val) {
        printf("Found in location %p and value is %d",*root, (*root)->val);
        printf("\n");
        return;
    }
    if(val<((*root)->val)) {
        insert(&(*root)->left, val);
    }
    if(val>(*root)->val) insert(&(*root)->right, val);

}


void Inorder(tree root) {
    if(root==NULL) return;
    Inorder((root)->left);
    printf("%d ",(root)->val );
    Inorder((root)->right);
}

int main() {
    tree root = NULL;
insert(&root, 5);
Inorder(root); printf("\n");
insert(&root, 5);
 Inorder(root); printf("\n");
insert(&root, 3);
Inorder(root); printf("\n");
insert(&root, 8);
Inorder(root); printf("\n");
insert(&root, 1);
Inorder(root); printf("\n");
insert(&root, 4);
Inorder(root); printf("\n");
insert(&root, 7);
Inorder(root); printf("\n");
insert(&root, 9);
Inorder(root); printf("\n");

    
    
}
