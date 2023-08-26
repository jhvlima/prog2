#include <stdio.h>
typedef struct 
{
    int qnt;
}tLivro;


int main()
{
    int qntLivros, x, flag = 0;
    scanf("%d", &qntLivros);
    tLivro livro[qntLivros];

    for (int  id = 0; id < qntLivros; id++)
    {
        livro[id + 1].qnt = 0;
    }
    
    for (int id = 0; id < qntLivros; id++)
    {
        scanf("%d", &x);
        livro[x].qnt++;
    }
    
    for (int id = 0; id < qntLivros; id++)
    {
        if((livro[id+1].qnt == 1))
        {
            printf("%d ", id);
            flag = 1;
        }
    }
    if (!flag)
    {
        printf("NENHUM");
    }
    
    return 0;
}