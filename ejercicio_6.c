#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Imprime un mensaje inicial en la salida estándar que indica el comienzo del test
    printf("Inicio del test\n");

    // Se realiza una llamada a fork() para crear un nuevo proceso
    if (fork() == 0) {
        // Este bloque de código es ejecutado únicamente por el proceso hijo
        // fork() devuelve 0 en el proceso hijo
        printf("Yo soy el hijo\n");
    } else {
        // Este bloque de código es ejecutado únicamente por el proceso padre
        // fork() devuelve el PID del proceso hijo al proceso padre, que es un valor positivo
        printf("Yo soy el padre\n");
    }

    // El programa termina. Ambos procesos, el padre y el hijo, imprimirán su mensaje correspondiente antes de finalizar.
    return 0;
}
