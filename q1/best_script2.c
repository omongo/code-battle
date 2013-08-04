/* $ gcc -Ofast -o best_script best_script.c */
/* $ ./best_script                           */

#include <stdio.h>

int main(void)
{
    int x[10000] = {0}, j;
    register int i;
    FILE *numbers, *run_result;

    if ((numbers = fopen("numbers.txt", "r")) == NULL)
      return 1;
    if ((run_result = fopen("run_result.txt", "w")) == NULL)
      return 1;

    while (fscanf(numbers, "%d", &j) == 1)
        x[j] = 1;
    for (i = 0; i < 10000; i++)
        if (x[i] == 0)
            fprintf(run_result, "%04d\n", i);

    fclose(run_result);
    fclose(numbers);

    return 0;
}
