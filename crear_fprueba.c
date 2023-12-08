#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int numbers[10];

    // Llenar el arreglo con los números del 0 al 9
    for(int i = 0; i < 10; i++) {
        numbers[i] = i;
    }

    // Abrir el archivo para escritura, crear si no existe con permisos 0644
    fd = open("fprueba", O_WRONLY | O_CREAT, 0644);
    if(fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Escribir los números en el archivo
    if(write(fd, numbers, sizeof(numbers)) == -1) {
        perror("Error al escribir en el archivo");
        close(fd);
        return 2;
    }

    // Cerrar el archivo
    close(fd);
    return 0;
}
