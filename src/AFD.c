#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FAFD.h"

/**
 * @brief Función principal del programa.
 * 
 * @param argc Cantidad de argumentos pasados al programa.
 * @param argv Arreglo de cadenas de caracteres que representan los argumentos pasados al programa.
 * @return int Valor de retorno del programa.
 */
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        DefaultAFD();
    }

    return 0;
}
