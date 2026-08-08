#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    // We are storing data in the stack, and we can't use free function for stack-based allocation.

    struct node n5 = {5, NULL};
    struct node n4 = {4, &n5};
    struct node n3 = {3, &n4};
    struct node n2 = {2, &n3};
    struct node n1 = {1, &n2};

    struct node *p = &n1;
    while (p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }

    puts("--------------------------");

    // Dynamically allocate nodes
    struct node *l1 = malloc(sizeof(struct node));
    struct node *l2 = malloc(sizeof(struct node));
    struct node *l3 = malloc(sizeof(struct node));
    struct node *l4 = malloc(sizeof(struct node));
    struct node *l5 = malloc(sizeof(struct node));

    // Initialize the nodes
    l1->data = 1; l1->next = l2;
    l2->data = 2; l2->next = l3;
    l3->data = 3; l3->next = l4;
    l4->data = 4; l4->next = l5;
    l5->data = 5; l5->next = NULL;

    // Wrong - first free then access the next element which is freed up => use-after-free
    // for (struct node *x = l1; x != NULL; x = x->next) {
    //     printf("%d\n", x->data);
    //     free(x);
    // }
    // Correct:
    // struct node *z;
    // for (struct node *x = l1; x != NULL; x = z) {
    //     printf("%d\n", x->data);
    //     z = x->next;
    //     free(x);
    // }
    // Correct:
    struct node *x, *y;
    for (x = l1; x != NULL; x = y) {
        y = x->next;
        printf("%d\n", x->data);
        free(x);
    }
    // Correct:
    // struct node *z;
    // for (struct node *x = l1; x != NULL; z = x->next, free(x), x = z) {
    //     printf("%d\n", x->data);
    // }
}