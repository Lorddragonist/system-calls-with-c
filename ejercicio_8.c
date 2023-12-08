#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int j, fd;
    int dato;

    // Abrir el archivo en modo de solo lectura
    fd = open("fprueba", O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1; // Terminar con un código de error si no se puede abrir el archivo
    }

    if (fork() != 0) {
        // Proceso padre
        while (read(fd, &dato, sizeof(int)) > 0) {
            // Bucle para simular carga de trabajo
            for (j = 0; j < 100000; j++);
            // Imprime el dato leído
            printf("Proceso padre. Dato = %d\n", dato);
        }
    } else {
        // Proceso hijo
        // Es una buena práctica cerrar y volver a abrir el archivo para que el proceso hijo tenga su propio descriptor de archivo
        close(fd);
        fd = open("fprueba", O_RDONLY);
        if (fd == -1) {
            perror("Error al abrir el archivo en el proceso hijo");
            exit(1); // Terminar con un código de error si no se puede abrir el archivo
        }
        while (read(fd, &dato, sizeof(int)) > 0) {
            // Bucle para simular carga de trabajo
            for (j = 0; j < 100000; j++);
            // Imprime el dato leído
            printf("Proceso hijo. Dato = %d\n", dato);
        }
        // Cerrar el archivo en el proceso hijo
        close(fd);
        exit(0); // Terminar el proceso hijo correctamente
    }

    // Cerrar el archivo en el proceso padre
    close(fd);
    return 0;
}
