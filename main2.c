
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
/*
void *calloc2(size_t nmemb, size_t size) {
    size_t totsize = nmemb * size;
    if ( totsize == 0 ) return NULL;
    return malloc(totsize);
}

void *sleepy_malloc(size_t s) {
    void * ptr = NULL;
    for (int i=0; i<10; i++) {
        ptr = malloc(s);
        if ( ptr != NULL) return ptr;
        sleep(5);
    }
    return NULL;
}
*/
/**
* Structure node
*
* @next: pointer to the next node in the list, NULL if last node_t
* @value: value stored in the node
*/
/*
typedef struct node {
  struct node *next;
  int value;
} node_t;
*/
/**
* Structure list
*
* @first: first node of the list, NULL if list is empty
* @size: number of nodes in the list
*/
/*
typedef struct list {
  struct node *first;
  int size;
} list_t;

node_t *init_node(int value) {
    node_t * ptr = (node_t *)malloc(sizeof(node_t));
    if ( ptr == NULL ) return NULL;
    (* ptr).next = NULL;
    (* ptr).value = value;
    return ptr;
}

int add_node(list_t *list, int value) {
    if ( list == NULL) return 1;
    node_t * first = (* list).first;
    node_t * ptr = init_node(value);
    if ( ptr == NULL) return 1;
    (* list).size++;
    (* ptr).next = first;
    (* list).first = ptr;
    return 0;
}
*/
typedef struct node
{
    int value;
    struct node* left; // to smaller values
    struct node* right; // to larger values
} node_t;

typedef struct bt
{
    struct node* root;
} bt_t;


int nodecontains( node_t * node, int value)
{
    if ( node == NULL) return 0;
    if ( (* node).value == value) return 1;
    if ( value < (* node).value)
    {
        return nodecontains((* node).left, value);
    }
    else
    {
        return nodecontains((* node).right, value);
    }
}
/*
* Return 1 if there is a node containing @value in @tree and 0 otherwise.
*/
int contains(bt_t* tree, int value)
{
    if ( tree == NULL ) return 0;
    node_t * node = (* tree).root;
    return nodecontains(node, value);
}

int main2()
{
    /*
    // Exercice calloc2
    // ****************
        long test = 0;
        int nbrelem = 4;
        long * ptr = NULL;
        ptr = (long *)calloc2((size_t)nbrelem, sizeof(test));
        long arr[4] = {0,0,0,0};
        for (int i =0; i < nbrelem; i++) {
          * ptr = (long)i*100;
          arr[i] = * ptr;
          printf("Element du tableau %ld\n", arr[i]);
          ptr++;
        }

    */

    /*
    // Exercice linked list
    // ********************
        node_t * node1 = init_node(1);

        list_t list = {node1, 0};
        int rc = add_node(&list, 2);
        printf("Return code :%d\n", rc);
        printf("Size of the list :%d\n", list.size);

        rc = add_node(NULL, 2);
        printf("Return code :%d\n", rc);
        printf("Size of the list :%d\n", list.size);


        node_t * current = list.first;
        while ( current != NULL ) {
            printf("Value in the list :%d\n", (* current).value);
            current = (* current).next;
        }
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
    int rc = contains(&tree, 23);
    printf("Return code :%d\n", rc);

    return 0;
}
