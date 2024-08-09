#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define fl(i,a,b) for(i=a; i<b; i++)
#define scan(a) scanf("%d", &a)
#define leer(a) fscanf(archivo, "%d", &a)
#define leers(a) fscanf(archivo, "%s", a)
#define leerc(a) fgets(a, 1000, archCadenas)
#define nline printf("\n")
#define MAX 1000

int AFDomision() {
    int states, symdir[20], estados_de_aceptacion, mark[20], mat[20][127];
    char symbols[50]; // hasta 50 simbolos
    char cadena[20];  // Cadena de maximo 20 simbolos

    char fileName[256] = "adefault1.txt";
    char stringsFileName[256] = "cadenasdefault1.txt";

    FILE *archivo = NULL;
    FILE *archCadenas = NULL;

    archivo = fopen(fileName, "r");
    archCadenas = fopen(stringsFileName, "r");
    if (archivo == NULL || archCadenas == NULL) {
        printf("Error al abrir los archivos.\n");
        return 1;
    }

    int i, j, n; 
    leers(symbols);   
    n = strlen(symbols);
 
     fl(i,0,n) {
        symdir[i] = (int) symbols[i];
    }  

    // Primero leemos del archivo el numero de estados
    leer(states);

    // Ahora vamos por los estados de aceptación
    leer(estados_de_aceptacion); 

    fl(i,0,estados_de_aceptacion) {
        int temp;
        leer(temp);
        mark[temp] = 1;
    }

    // Defina Delta
    fl(i,0,states) {
        fl(j,0,n) {
            leer(mat[i][symdir[j]]);
            //printf("%d -> %c -> %d\n", i, symdir[j], mat[i][symdir[j]]);
        }
    }

    //--------------------------------------------------------//

    char str1[MAX];
    while (leerc(str1) != NULL) {
        int curr = 0;
        int limit = strlen(str1) - 1;

        fl(i,0,limit) {
            if (strchr(symbols, str1[i]) == NULL) {
                printf("ERROR! En la cadena %s, %c no es un elemento del alfabeto\n", str1, str1[i]);
                curr = -1;
                break;
            }

            int ele = (int)(str1[i]);
            curr = mat[curr][ele];

            if (curr == -1) {
                printf("ERROR! Regla invalida!\n");
                break;
            }
        } 

        if (curr != -1) {
            if (mark[curr] == 1)
                printf("La cadena %s es ACEPTADA\n", str1);
            else
                printf("La cadena %s es RECHAZADA\n", str1);

            nline;
        }
    }

    fclose(archivo);
    fclose(archCadenas);

    return 0;
}

int AFDmanual() {
    printf("Automata de ingreso manual\n");

    int states, symbols, symdir[20], final_states, mark[20], mat[20][20];
    int i, j, k;

    printf("Ingrese el numero de estados: ");
    scan(states);

    printf("Ingrese el numero de simbolos: ");
    scan(symbols);
    char A[symbols];

    printf("Ingrese los simbolos:\n");
    nline;

    fl(i,0,symbols) {
        printf("Ingrese el simbolo número %d: ", i);
        scanf(" %c", &A[i]);  // Espacio antes de %c para ignorar espacios en blanco
        symdir[i] = i;
    }

    printf("Ingrese el numero de estado(s) de aceptacion: ");
    scan(final_states);

    printf("Ingrese el estado de aceptacion: ");
    fl(i,0,final_states) {
        int temp;
        scan(temp);
        mark[temp] = 1;
    }

    printf("Defina delta:\n");
    nline;

    fl(i,0,states) {
        fl(j,0,symbols) {
            printf("Defina la relacion entre el estado delta (%d, %c) = ", i, A[j]);
            scan(mat[i][symdir[j]]);
        }
    }

    //--------------------------------------------------------//

    while (1) {
        printf("Ingrese las cadenas solución: ");
        char str1[MAX];
        char str2[MAX];

        scanf("%s", str1);

        int limit = strlen(str1);
        int limit2 = strlen(A);

        fl(i,0,limit) {
            fl(j,0,limit2) {
                if (str1[i] == A[j]) {
                    str2[i] = j;
                }
            }
        }

        int curr = 0;
        fl(i,0,limit) {
            int ele = (int)(str2[i]);
            curr = mat[curr][ele];
        }

        if (mark[curr] == 1)
            printf("Verdadera\n");
        else
            printf("Falsa\n");

        nline;
    }

    return 0;
}

int AFDautomatacadena() {
    // Implementar la función según tus necesidades
    return 0;
}