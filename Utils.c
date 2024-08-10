#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include "FAFD.h"

const char tests_folder[256] = "tests/";


void buffer_a_arr(char *buffer, int *arr){
    int i;
    for(i,0,strlen(buffer)){
        int c = (int) buffer[i];
        arr[c] = 1;
    }
}

void guardar_estado_inicial(char *buffer, int *states, int *initial_state){
    int c = (int) buffer[0];
    if (states[c] == 1){
        *initial_state = c;
    } else {
        printf("\033[0;31mError: El estado inicial no es valido, revise el archivo.\033[0m\n");
        exit(1);
    }
}

void guardar_estados_de_aceptacion(char *buffer, int *states, int *states_of_acceptance){
    int i;
    for(i,0,strlen(buffer)){
        int c = (int) buffer[i];
        if (states[c] == 1){
            states_of_acceptance[c] = 1;
        } else {
            printf("\033[0;31mError: El estado de aceptacion no es valido, revise el archivo.\033[0m\n");
            exit(1);
        }
    }
}

void guardar_en_matriz_de_transicion(char *buffer, int *states, int *alphabet, int matrix_of_transitions[127][127]){
    int first_state = (int) buffer[0];
    int destination_state = (int) buffer[2];
    int symbol = (int) buffer[1];
    if (states[first_state] == 1 && states[destination_state] == 1){
        if (alphabet[symbol] == 1){
            matrix_of_transitions[first_state][symbol] = destination_state;
        } else {
            printf("\033[0;31mError: El simbolo no es valido, revise el archivo.\033[0m\n");
            exit(1);
        }
    } else {
        printf("\033[0;31mError: Los estados no son validos, revise el archivo.\033[0m\n");
        exit(1);
    }
}
void check_str(char *chain, int *initial_state, int *states_of_acceptance, int matrix_of_transitions[127][127]){
    int curr = *initial_state;
    int limit = strlen(chain);
    int i;
    for(i,0,limit){
        int c = (int) chain[i];
        curr = matrix_of_transitions[curr][c];
    }
    if (states_of_acceptance[curr] == 1){
        printf("Resultado: La cadena fue aceptada.\n");
    } else {
        printf("Resultado: La cadena fue rechazada.\n");
}
}
int DefaultAFD()
{
    int alphabet[127], initial_state;
    int states_of_acceptance[127];
    int  matrix_of_transitions[127][127];
    int states[127];
    char cadena[256];
    char fileName[256];
    char stringsFileName[256];
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
        printf("Contador: %d\n", contador);
        // Elimina el salto de línea si existe
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }
        // Procesar el contenido de la línea
        if (contador == 1)
        { 
            printf("Estados: %s\n", buffer);
            buffer_a_arr(buffer, states);
        }
        else if (contador == 2)
        {
            printf("Alfabeto: %s\n", buffer);
            buffer_a_arr(buffer, alphabet);
        }
        else if (contador == 3)
        {
            printf("Estado inicial: %s\n", buffer);
            guardar_estado_inicial(buffer, states, &initial_state);
            
        }
        else if (contador == 4)
        {
            printf("Estados de aceptacion: %s\n", buffer);
            guardar_estados_de_aceptacion(buffer, states, states_of_acceptance);
        }
        else
        {
            printf("Matriz de transicion de estados: %s\n", buffer);
            guardar_en_matriz_de_transicion(buffer, states, alphabet, matrix_of_transitions);
        }
        contador++;
    }

    fclose(archivo);
    
    printf("Ingrese la cadena a evaluar: ");
    scan_str(cadena);
    while(strlen(cadena) > 0){
        check_str(cadena, &initial_state, states_of_acceptance, matrix_of_transitions);
        printf("Ingrese la cadena a evaluar: ");
        scan_str(cadena);
    }

    // archivo = fopen(fileName, "r");
    // archCadenas = fopen(stringsFileName, "r");
    // if (archivo == NULL || archCadenas == NULL) {
    //     printf("Error al abrir los archivos.\n");
    //     return 1;
    // }

    // int i, j, n;
    // leers(symbols);
    // n = strlen(symbols);

    //  for(i,0,n) {
    //     symdir[i] = (int) symbols[i];
    // }

    // // Primero leemos del archivo el numero de estados
    // leer(states);

    // // Ahora vamos por los estados de aceptación
    // leer(estados_de_aceptacion);

    // fl(i,0,estados_de_aceptacion) {
    //     int temp;
    //     leer(temp);
    //     mark[temp] = 1;
    // }

    // // Defina Delta
    // fl(i,0,states) {
    //     fl(j,0,n) {
    //         leer(mat[i][symdir[j]]);
    //         //printf("%d -> %c -> %d\n", i, symdir[j], mat[i][symdir[j]]);
    //     }
    // }

    // //--------------------------------------------------------//

    // char str1[MAX];
    // while (leerc(str1) != NULL) {
    //     int curr = 0;
    //     int limit = strlen(str1) - 1;

    //     fl(i,0,limit) {
    //         if (strchr(symbols, str1[i]) == NULL) {
    //             printf("ERROR! En la cadena %s, %c no es un elemento del alfabeto\n", str1, str1[i]);
    //             curr = -1;
    //             break;
    //         }

    //         int ele = (int)(str1[i]);
    //         curr = mat[curr][ele];

    //         if (curr == -1) {
    //             printf("ERROR! Regla invalida!\n");
    //             break;
    //         }
    //     }

    //     if (curr != -1) {
    //         if (mark[curr] == 1)
    //             printf("La cadena %s es ACEPTADA\n", str1);
    //         else
    //             printf("La cadena %s es RECHAZADA\n", str1);

    //         nline;
    //     }
    // }

    // fclose(archivo);
    // fclose(archCadenas);

    return 0;
}


// int AFDmanual() {
//     printf("Automata de ingreso manual\n");

//     int states, symbols, symdir[20], final_states, mark[20], mat[20][20];
//     int i, j, k;

//     printf("Ingrese el numero de estados: ");
//     scan(states);

//     printf("Ingrese el numero de simbolos: ");
//     scan(symbols);
//     char A[symbols];

//     printf("Ingrese los simbolos:\n");
//     nline;

//     fl(i,0,symbols) {
//         printf("Ingrese el simbolo número %d: ", i);
//         scanf(" %c", &A[i]);  // Espacio antes de %c para ignorar espacios en blanco
//         symdir[i] = i;
//     }

//     printf("Ingrese el numero de estado(s) de aceptacion: ");
//     scan(final_states);

//     printf("Ingrese el estado de aceptacion: ");
//     fl(i,0,final_states) {
//         int temp;
//         scan(temp);
//         mark[temp] = 1;
//     }

//     printf("Defina delta:\n");
//     nline;

//     fl(i,0,states) {
//         fl(j,0,symbols) {
//             printf("Defina la relacion entre el estado delta (%d, %c) = ", i, A[j]);
//             scan(mat[i][symdir[j]]);
//         }
//     }

//     //--------------------------------------------------------//

//     while (1) {
//         printf("Ingrese las cadenas solución: ");
//         char str1[MAX];
//         char str2[MAX];

//         scanf("%s", str1);

//         int limit = strlen(str1);
//         int limit2 = strlen(A);

//         fl(i,0,limit) {
//             fl(j,0,limit2) {
//                 if (str1[i] == A[j]) {
//                     str2[i] = j;
//                 }
//             }
//         }

//         int curr = 0;
//         fl(i,0,limit) {
//             int ele = (int)(str2[i]);
//             curr = mat[curr][ele];
//         }

//         if (mark[curr] == 1)
//             printf("Verdadera\n");
//         else
//             printf("Falsa\n");

//         nline;
//     }

//     return 0;
// }

// int AFDautomatacadena() {
//     // Implementar la función según tus necesidades
//     return 0;
// }