#include <stdio.h>
#include <stdlib.h>

void f2()
{
    int i = 0;
    printf("++i = %d\n", ++i);
}

int main()
{

    int *v = (int *)malloc(10 * sizeof(int));
    v[0] = 10;
    printf("v[0] = %d\n", v[0]);
    f2();
    free(v);

    return 0;
}
