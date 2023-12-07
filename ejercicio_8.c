#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int i, j, fd;
    int dato;
    fd = open("fprueba", O_RDONLY);

    if (fork() != 0)
    {
        // Proceso padre
        while (read(fd, &dato, sizeof(int) > 0))
        {
            for (j = 0; j < 100000; j++)
            {
                // espera
                printf("Proceso padre. Dato = %d\n", dato);
            }
        }
    }else
    {
        //Proceso hijo
        while (read(fd, &dato, sizeof(int) > 0))
        {
            for (j = 0; j < 100000; j++)
            {
                // espera
                printf("Proceso padre. Dato = %d\n", dato);
            }
        }
        
    }
    

    return 0;
}
