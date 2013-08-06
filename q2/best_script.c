/* Run on OS X 10.8.4                     */
/* $ gcc -O3 -o best_script best_script.c */
/* $ time ./best_script                   */
/* real  0m58.125                         */
/* user  0m58.080s                        */
/* sys   0m0.042s                         */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    char val[7];
    int freq;
    struct list *next;
};

struct list *append_list(struct list *, char *);
struct list *search_list(struct list *, char *);

int main(void)
{
    struct list *l = NULL, *element, *old;
    char str[7];
    FILE *numbers, *run_result;

    if ((numbers = fopen("numbers.txt", "r")) == NULL)
        return 1;
    if ((run_result = fopen("run_result.txt", "w")) == NULL)
        return 1;

    while (fscanf(numbers, "%s", str) == 1)
        if ((element = search_list(l, str)) == NULL)
            l = append_list(l, str);
        else
            (element->freq)++;

    while (l != NULL) {
        if (l->freq > 1)
          fprintf(run_result, "\"%s\", %d\n", l->val, l->freq);
        old = l;
        l = l->next;
        free(old);
    }

    fclose(run_result);
    fclose(numbers);

    return 0;
}

struct list *append_list(struct list *l, char *val)
{
    struct list *new = (struct list *) malloc(sizeof (struct list));
    if (new == NULL) {
        exit(1);
        puts("error: append_list");
    }
    strncpy(new->val, val, 7);
    new->freq = 1;
    new->next = l;
    return new;
}

struct list *search_list(struct list *l, char *val)
{
    while (l != NULL && strncmp(l->val, val, 7))
        l = l->next;
    return l;
}
