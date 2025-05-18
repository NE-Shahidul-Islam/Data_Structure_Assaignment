/*
Traverse the tree in preorder, inorder, postorder.....
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
    if(val<((*root)->val)) {
        insert(&(*root)->left, val);
    }
    if(val>=(*root)->val) insert(&(*root)->right, val);

}

void Preorder(tree root) {
    if(root==NULL) return;
    printf("%d ",(root)->val );
    Preorder((root)->left);
    Preorder((root)->right);
}

void Inorder(tree root) {
    if(root==NULL) return;
    Inorder((root)->left);
    printf("%d ",(root)->val );
    Inorder((root)->right);
}

void Postorder(tree root) {
    if(root==NULL) return;
    Postorder((root)->left);
    Postorder((root)->right);
    printf("%d ",(root)->val );
}

int main() {
    tree root = NULL;
insert(&root, 5);
insert(&root, 5);
insert(&root, 3);
insert(&root, 8);
insert(&root, 1);
insert(&root, 4);
insert(&root, 7);
insert(&root, 9);
printf("Preorder Traversal is: ");
Inorder(root); printf("\n");
printf("Inorder Traversal is: ");
Preorder(root); printf("\n");
printf("Postorder Traversal is: ");
Postorder(root); printf("\n");

    
    
}
