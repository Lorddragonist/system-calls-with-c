#include <stdio.h>

int main(void)
{
    // Declara una variable de tipo int y la inicializa con el valor entero 10
    int varA = 10;
    // Declara otra variable de tipo int y la inicializa con el valor entero 150
    int varB = 150;
    // Declara una variable de tipo double y la inicializa con el valor de punto flotante 1.25
    double varC = 1.25;

    // Imprime el valor de varA. %d es el especificador de formato para enteros.
    printf("El valor de varA es: %d \n", varA);
    // Imprime el valor de varB. %d es también el especificador de formato para enteros.
    printf("El valor de varB es: %d \n", varB);
    // Imprime el valor de varC. %.3f es el especificador de formato para números de punto flotante
    // con 3 dígitos después del punto decimal.
    printf("El valor de varC es: %.3f \n", varC);

    // Finaliza la función main y retorna 0, indicando que el programa terminó con éxito.
    return 0;
}
