#include "clist.h"

int main()
{
    int m, n;
    printf("Input (N, M): ");
    scanf("%d%d", &n, &m);

    struct node_t *s = NULL;

    int err = create_list(&s, n);
    if (err != 0)
    {
        printf("Error #1: List was not created!\n");
        return -1;
    }

    s = last_element(s, m);
    printf("\nLast person is [%d]\n", s->info);

    free(s);

    return 0;
}
