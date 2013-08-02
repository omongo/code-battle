/* $ gcc -Ofast -o best_script best_script.c      */
/* $ ./best_script < numbers.txt > run_result.txt */

#include <stdio.h>
#include <stdlib.h>

int compare(const void *, const void *);

int main(void)
{
    int *x = NULL, j;
    register int i, val, ctr;

    for (i = 0; scanf("%d", &j) == 1; i++) {
        if ((x = (int *) realloc(x, (i + 1) * sizeof (int))) == NULL)
            return 1;
        x[i] = j;
    }

    qsort(x, i, sizeof (int), compare);

    for (val = x[0], ctr = 1, j = i, i = 0; i < j; i++) {
        if (x[i] == val)
            ctr++;
        else {
            if (ctr > 1)
                printf("\"%d\", %d\n", val, ctr);
            val = x[i];
            ctr = 1;
        }
    }

    free(x);

    return 0;
}

int compare(const void *a, const void *b)
{
    return * (int *) a - * (int *) b;
}
