#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main()
{

    int fd;

    fd = creat("prueba_ejercicio_4",0600);

    if (fd == -1)
    {
        perror("Error al crear el archivo");
        return 1; //Terminar programa con código de error 
    }
    

    int vector[9];

    for (int i = 0; i < 10; i++)
    {
        vector[i] = i + 1;
        printf("\n%d",vector[i]);
    }

    write(fd,vector,sizeof(vector));

    close(fd);

    return 0; //Terminar programa con código de éxito
}
