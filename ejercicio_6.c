#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    printf("Inicio del test\n");

    if (fork() == 0)
    {
        // Proceso hijo
        printf("Yo soy el hijo\n");
    }
    else
    {
        // Proceso padre
        printf("Yo soy el padre\n");
    }

    return 0;
}
