#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char *filename = "prueba_ejercicio_5";
    char vector[10][2];
    ssize_t bytes_written;

    // Vector de 10 X 2 para agregar salto de línea
    for (int i = 0; i < 10; ++i) {
        vector[i][0] = '0' + i; // Convertir el número a su representación en char
        vector[i][1] = '\n';    // Añadir un salto de línea
    }

    // Abrir el archivo para escritura, crear si no existe con permisos 0644
    fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1; // Terminar el programa con código de error
    }

    // Escribir el vector en el archivo
    for (int i = 0; i < 10; ++i) {
        bytes_written = write(fd, vector[i], sizeof(vector[i]));
        if (bytes_written == -1) {
            perror("Error al escribir en el archivo");
            close(fd); // Intentar cerrar el archivo si hay un error
            return 2; // Terminar el programa con código de error
        }
    }

    // Cerrar el archivo
    if (close(fd) == -1) {
        perror("Error al cerrar el archivo");
        return 3; // Terminar el programa con código de error
    }

    return 0; // Terminar el programa con éxito
}
