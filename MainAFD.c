#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcmp
#include "FAFD.h"

#define fl(i,a,b) for(i=a; i<b; i++)
#define scan(a) scanf("%d", &a)
#define leer(a) fscanf(archivo, "%d", &a)
#define leers(a) fscanf(archivo, "%s", a)
#define leerc(a) fgets(a, 1000, archCadenas)
#define nline printf("\n")
#define MAX 1000

int main(int argc, char *argv[]) 
{ 
    // Automata por defecto   
    if (argc == 1) {
        AFDmanual();
    }
    
    if (argc == 2 && (strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "-M") == 0)) {
        AFDmanual();
    }
    
    if (argc > 2) {
        AFDautomatacadena();
    }

    return 0;
}
