/* $ gcc -Ofast -o best_script best_script.c      */
/* $ ./best_script < numbers.txt > run_result.txt */

#include <stdio.h>

int main(void)
{
    int x[10000] = {0}, j;
    register int i;

    while (scanf("%d", &j) == 1)
        x[j] = 1;
    for (i = 0; i < 10000; i++)
        if (x[i] == 0)
            printf("%04d\n", i);

    return 0;
}
