#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int i, j;
    
    // Se realiza una llamada a fork() para crear un nuevo proceso
    if (fork() != 0) {
        // Este bloque de código es ejecutado por el proceso padre
        // El proceso padre entrará en este bucle si fork() devuelve un valor distinto de 0 (el PID del proceso hijo)
        for (i = 0; i < 100; i++) {
            // Bucle interno para simular una carga de trabajo. No realiza ninguna operación útil.
            for (j = 0; j < 100000; j++);
            // Imprime el valor del índice i junto con un mensaje que indica que es el proceso padre
            printf("Proceso padre. Indice i=%d\n", i);
        }
    } else {
        // Este bloque de código es ejecutado por el proceso hijo
        // El proceso hijo entrará en este bucle si fork() devuelve 0
        for (i = 0; i < 100; i++) {
            // Bucle interno para simular una carga de trabajo, igual que en el proceso padre
            for (j = 0; j < 100000; j++);
            // Imprime el valor del índice i junto con un mensaje que indica que es el proceso hijo
            printf("Proceso hijo. Indice i=%d\n", i);
        }
        // Es importante que el proceso hijo finalice su ejecución para evitar que se convierta en un proceso zombi
        // exit(0) cierra el proceso hijo una vez que ha completado su bucle
        exit(0); 
    }
    // El proceso padre finaliza su ejecución normalmente y termina el programa
    return 0;
}
