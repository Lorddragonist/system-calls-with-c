#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int i, j;

    if (fork() != 0)
    {
        // Proceso padre
        for (i = 0; i < 100; i++)
        {
            for (j = 0; j < 100000; j++)
            {
                printf("Proceso padre. Indice i=%d\n", i);
            }
        }
    }
    else
    {
        // Proceso hijo
        for (i = 0; i < 100; i++)
        {
            for (j = 0; j < 100000; j++)
            {
                printf("Proceso hijo. Indice i=%d\n", i);
            }
        }
    }

    return 0;
}
