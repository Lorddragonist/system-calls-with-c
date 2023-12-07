#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char numStr[3];
    int i;

    // Abrir o crear el archivo con permisos de escritura
    fd = creat("prueba_ejercicio_3", 0600);
    
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Escribir los números del 1 al 10 en el archivo
    for (i = 1; i <= 10; i++) {
        sprintf(numStr, "%d\n", i);
        write(fd, numStr, sizeof(numStr));
    }

    // Cerrar el archivo
    close(fd);

    return 0;
}
