#ifndef CLIST_H_INCLUDED
#define CLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

struct node_t     /* Double circular linked list */
{
    int info;
    struct node_t *left;
    struct node_t *right;
};

struct node_t *create(int);

int add_end(struct node_t **, int);

struct node_t *remov(struct node_t *);

int create_list(struct node_t **, size_t nmemb);

void display(const struct node_t *);

struct node_t *last_element(struct node_t *, int);

#endif // CLIST_H_INCLUDED
