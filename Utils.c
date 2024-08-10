/**
 * Archivo: Utils.c
 * 
 * Descripción: Este archivo contiene funciones de utilidad para el manejo de autómatas finitos deterministas (AFD).
 * 
 * Funciones:
 *  - buffer_a_arr: Convierte los caracteres de un buffer en un arreglo de enteros.
 *  - guardar_estado_inicial: Verifica y guarda el estado inicial en la variable `initial_state`.
 *  - guardar_estados_de_aceptacion: Guarda los estados de aceptación en un arreglo de estados de aceptación.
 *  - guardar_en_matriz_de_transicion: Guarda la transición en la matriz de transiciones.
 *  - check_str: Verifica si una cadena cumple con los estados de aceptación de un AFD.
 *  - DefaultAFD: Función principal para ejecutar un AFD por defecto.
 */
#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include "FAFD.h"

#define ASCII_DIGITS 127
const char tests_folder[256] = "tests/";
/**
 * Convierte los caracteres de un buffer en un arreglo de enteros.
 *
 * @param buffer El buffer que contiene los caracteres a convertir.
 * @param arr El arreglo de enteros donde se almacenarán los resultados.
 */
void buffer_a_arr(char *buffer, int *arr)
{
    int i;
    for (i, 0, strlen(buffer))
    {
        int c = (int)buffer[i];
        arr[c] = 1;
    }
}

/**
 * Función para guardar el estado inicial.
 *
 * Esta función verifica si el estado inicial es válido y lo guarda en la variable `initial_state`.
 *
 * @param buffer El buffer que contiene los datos.
 * @param states Un arreglo que representa los estados.
 * @param initial_state Un puntero a la variable donde se guardará el estado inicial.
 */
void guardar_estado_inicial(char *buffer, int *states, int *initial_state)
{
    int c = (int)buffer[0];
    if (states[c] == 1)
    {
        *initial_state = c;
    }
    else
    {
        printf("\033[0;31mError: El estado inicial no es valido, revise el archivo.\033[0m\n");
        exit(1);
    }
}

/**
 * Guarda los estados de aceptación en un arreglo de estados de aceptación.
 *
 * @param buffer El buffer que contiene los estados de aceptación.
 * @param states El arreglo de estados.
 * @param states_of_acceptance El arreglo de estados de aceptación.
 */
void guardar_estados_de_aceptacion(char *buffer, int *states, int *states_of_acceptance)
{
    int i;
    for (i, 0, strlen(buffer))
    {
        int c = (int)buffer[i];
        if (states[c] == 1)
        {
            states_of_acceptance[c] = 1;
        }
        else
        {
            printf("\033[0;31mError: El estado de aceptacion no es valido, revise el archivo.\033[0m\n");
            exit(1);
        }
    }
}

/**
 * Guarda la transición en la matriz de transiciones.
 *
 * @param buffer El buffer que contiene la información de la transición.
 * @param states Un arreglo que indica si un estado es válido o no.
 * @param alphabet Un arreglo que indica si un símbolo es válido o no.
 * @param matrix_of_transitions La matriz de transiciones.
 */
void guardar_en_matriz_de_transicion(char *buffer, int *states, int *alphabet, int matrix_of_transitions[127][127])
{
    int first_state = (int)buffer[0];
    int destination_state = (int)buffer[2];
    int symbol = (int)buffer[1];
    if (states[first_state] == 1 && states[destination_state] == 1)
    {
        if (alphabet[symbol] == 1)
        {
            matrix_of_transitions[first_state][symbol] = destination_state;
        }
        else
        {
            printf("\033[0;31mError: El simbolo no es valido, revise el archivo.\033[0m\n");
            exit(1);
        }
    }
    else
    {
        printf("\033[0;31mError: Los estados no son validos, revise el archivo.\033[0m\n");
        exit(1);
    }
}

/**
 * Verifica si una cadena cumple con los estados de aceptación de un autómata finito determinista (AFD).
 *
 * @param chain La cadena a verificar.
 * @param initial_state El estado inicial del AFD.
 * @param states_of_acceptance Los estados de aceptación del AFD.
 * @param matrix_of_transitions La matriz de transiciones del AFD.
 */
void check_str(char *chain, int *initial_state, int *states_of_acceptance, int matrix_of_transitions[127][127])
{
    int curr = *initial_state;
    int limit = strlen(chain);
    int i;
    for (i, 0, limit)
    {
        int c = (int)chain[i];
        curr = matrix_of_transitions[curr][c];
    }
    if (states_of_acceptance[curr] == 1)
    {
        printf("Resultado: La cadena fue aceptada.\n");
    }
    else
    {
        printf("Resultado: La cadena fue rechazada.\n");
    }
}
/**
 * Función para ejecutar un Autómata Finito Determinista (AFD) por defecto.
 * Lee un archivo de configuración que contiene la información necesaria para construir el AFD,
 * y luego permite ingresar cadenas para evaluar si son aceptadas por el AFD.
 *
 * @return 0 si la ejecución fue exitosa.
 */
int DefaultAFD()
{
    int alphabet[ASCII_DIGITS], initial_state;
    int states_of_acceptance[ASCII_DIGITS]; 
    int matrix_of_transitions[ASCII_DIGITS][ASCII_DIGITS];
    int states[ASCII_DIGITS];
    char cadena[256];
    char fileName[256];
    char path[50];
    char buffer[50];

    // FILE *archCadenas = NULL;
    printf("Ingrese el nombre del archivo de configuracion (debe estar ubicado en la carpeta %s): ", tests_folder);
    scan_str(fileName);
    sprintf(path, "%s%s", tests_folder, fileName);
    // leer_str_archivo(path, states, sizeof(states));
    FILE *archivo = fopen(path, "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    int contador = 1;
    // Leer el contenido del archivo línea por línea
    while (fgets(buffer, sizeof(buffer), archivo) != NULL)
    {
        // Elimina el salto de línea si existe
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }
        // Procesar el contenido de la línea
        if (contador == 1)
        {
            buffer_a_arr(buffer, states);
        }
        else if (contador == 2)
        {
            buffer_a_arr(buffer, alphabet);
        }
        else if (contador == 3)
        {
            guardar_estado_inicial(buffer, states, &initial_state);
        }
        else if (contador == 4)
        {
            guardar_estados_de_aceptacion(buffer, states, states_of_acceptance);
        }
        else
        {
            guardar_en_matriz_de_transicion(buffer, states, alphabet, matrix_of_transitions);
        }
        contador++;
    }

    fclose(archivo);
    printf("Ingrese la cadena a evaluar: ");
    scan_str(cadena);
    while (strlen(cadena) != 0)
    {
        printf("%s\n", cadena);
        check_str(cadena, &initial_state, states_of_acceptance, matrix_of_transitions);

        printf("Ingrese la cadena a evaluar: ");
        scan_str(cadena);
    }
    return 0;
}
