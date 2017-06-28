#include "clist.h"

struct node_t *create(int n)
{
    struct node_t *tmp = malloc(sizeof(*tmp));
    if (tmp)
    {
        tmp->info = n;
        tmp->left = tmp->right = NULL;
    }

    return tmp;
}

int add_end(struct node_t **s, int n)       // Keep header
{
    struct node_t *new = create(n);
    if (!new)
        return 0;       // PUSH error

    if ((*s) == NULL)
    {
        *s = new;
        (*s)->left = (*s)->right = *s;
    }
    else
    {
        new->left = (*s)->left;
        new->right = (*s);

        (*s)->left->right = new;
        (*s)->left = new;
    }

    return 1;           // PUSH without errors
}

struct node_t *remov(struct node_t *need)
{
    struct node_t *next = need->right;
    (need->left)->right = next;
    next->left = need->left;

    free(need);
    return next;
}

int create_list(struct node_t **s, size_t nmemb)
{
    for (size_t i = 1; i <= nmemb; i++)
       if (!add_end(s, i))
            return i;
    return 0;
}

void display(const struct node_t *s)
{
    int save = s->left->info;
    while (s->info != save)
    {
        printf(" %d", s->info);
        s = s->right;
    }
    printf(" %d\n", save);
}

struct node_t *last_element(struct node_t *s, int m)
{
    struct node_t *cur_element = s;
    int n = 1;
    while (cur_element->right != cur_element)
    {
        for (int i = 1; i < m; i++)
            cur_element = cur_element->right;

        cur_element = remov(cur_element);

        printf("Step #%d:", n);
        display(cur_element);
        n++;
    }

    return cur_element;
}
