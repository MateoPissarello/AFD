#ifndef _FUNCION1_H_
#define _FUNCION1_H_

// Declaracion de macros
#define for(i,a,b) for(i=a; i<b; i++)
#define scan_number(a) scanf("%d", &a)
#define scan_str(a) scanf("%s", a)
#define leer_num_archivo(nombre_archivo,a) fscanf(archivo, "%d", &a)
// #define leer_str_archivo(nombre_archivo, a) fscanf(archivo, "%s", a)
#define leerc(a) fgets(a, 1000, archCadenas)
#define line_break printf("\n")

// Declaracion de funciones
// int AFDomision();
// int AFDmanual();
int DefaultAFD();
// int AFDautomatacadena();
void init();
void processArgs(int argc, char *argv[]);
#endif
