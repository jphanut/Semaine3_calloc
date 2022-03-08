#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* left; // to smaller values
    struct node* right; // to larger values
} node_t;

typedef struct bt{
    struct node* root;
} bt_t;

/*
* Return 1 if there is a node containing @value in @tree and 0 otherwise.
* Recursive Helper function of int contains(bt_t* tree, int value)
*/
int nodecontains( node_t * node, int value) {
   if ( node == NULL) return 0;
   if ( (* node).value == value) return 1;
   if ( value < (* node).value) {
        return nodecontains((* node).left, value);
   }
   else {
        return nodecontains((* node).right, value);
   }
}
/*
* Return 1 if there is a node containing @value in @tree and 0 otherwise.
*/
int contains(bt_t* tree, int value){
    if ( tree == NULL ) return 0;
    node_t * node = (* tree).root;
    return nodecontains(node, value);
}

int main3()
{
/*
* Build of a sample binary tree.
*/
    node_t node13 = {13, NULL, NULL};
    node_t node17 = {17, NULL, NULL};
    node_t node16 = {16, &node13, &node17};
    node_t node07 = {7, NULL, NULL};
    node_t node11 = {11, &node07, &node16};
    node_t node23 = {23, NULL, NULL};
    node_t node35 = {35, &node23, NULL};
    node_t node19 = {19, &node11, &node35};
    bt_t tree = {&node19};

/*
* Test of contains function with search values 23 and 5
* 23 must give a return code of 1
* 5  must give a return code of 0
*/
    int rc = contains(&tree, 23);
    printf("Return code with search value 23: %d\n", rc);
	rc = contains(&tree, 5);
    printf("Return code with search value 5: %d\n", rc);

    return 0;
}
