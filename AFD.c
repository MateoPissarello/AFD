#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FAFD.h"

#define for(i,a,b) for(i=a; i<b; i++)
#define scan(a) scanf("%d", &a)
#define leer_num_archivo(nombre_archivo,a) fscanf(archivo, "%d", &a)
// #define leer_str_archivo(nombre_archivo, a) fscanf(archivo, "%s", a)
#define leerc(a) fgets(a, 1000, archCadenas)
#define line_break printf("\n")

int main(int argc, char *argv[]) 
{ 
    // Automata por defecto   
    if (argc == 1) {
        DefaultAFD();
    }
    
    // if (argc == 2 && (strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "-M") == 0)) {
    //     AFDmanual();
    // }
    
    // if (argc > 2) {
    //     AFDautomatacadena();
    // }

    return 0;
}

