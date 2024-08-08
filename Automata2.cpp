#include <stdio.h>
#include <conio.h>
#include <string.h>
#define fl(i,a,b) for(i=a; i<b; i++)
#define scan(a) scanf("%d", &a)
#define leer(a) fscanf(archivo, "%d", &a)
#define leers(a) fscanf(archivo, "%s", a)
#define leerc(a) fgets(a, 1000, archCadenas)
#define nline printf("\n")
#define MAX 1000



int states, symdir[20], estados_de_aceptacion, mark[20], mat[20][127];
char symbols[50]; // hasta 50 sÃ­mbolos
char cadena[20];  // Cadena de maximo 20 simbolos

char fileName[256] = "";
char stringsFileName[256] = "";

FILE *archivo = NULL;
FILE *archCadenas = NULL;

void init() {
    int i, j;

    fl(i, 0, 20) {
        fl(j, 0, 127) {
            mat[i][j] = -1;
        }
    }
}


void processArgs(int argc, char *argv[]) {
    int n = 1;

    archivo = stdin;
    archCadenas = stdin;

    while (n < argc) {
        if (strcmp(argv[n], "-A") == 0 || strcmp(argv[n], "-a") == 0) {
            n++;
            if (n != argc) {
                strcpy(fileName, argv[n]);
                if ((archivo = fopen(fileName, "rt")) == NULL) {
                    printf("Error al abrir el archivo %s\n", fileName);
                    printf("Tomando informacion desde el teclado\n");
                    archivo = stdin;
                }
            }
            else {
                printf("Falto argumento para la opcion -A.\n");
                printf("Tomando informacion desde el teclado.\n");    
            }
            
        }
        else if (strcmp(argv[n], "-F") == 0 || strcmp(argv[n], "-f") == 0) {
            n++;
            if (n != argc) {
                strcpy(stringsFileName, argv[n]);
                if ((archCadenas = fopen(stringsFileName, "rt")) == NULL) {
                    printf("Error al abrir el archivo de cadenas %s\n", stringsFileName);
                    printf("Tomando informacion desde el teclado\n");
                    archCadenas = stdin;
                }
            }
            else {
                printf("Falto argumento para la opcion -F.\n");
                printf("Tomando informacion desde el teclado.\n");    
            }

        }
        n++;
    }
}


int main(int argc, char *argv[])
{
    int i, j, n;

    // Procesar los argumentos
    processArgs(argc, argv);
    init();
// Ahora leemos cada uno de los simbolos

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

        mark[temp]=1;
    }

    
    //Defina Delta

    fl(i,0,states) {

        fl(j,0,n) {

            leer(mat[i][symdir[j]]);
            //printf("%d -> %c -> %d\n", i, symdir[j], mat[i][symdir[j]]);

        }

    }

    //--------------------------------------------------------//

    char str1[MAX];

    while(leerc(str1) != NULL) {

        int curr=0;

        int limit= strlen(str1) - 1;

        fl(i,0,limit) {

            if (strchr(symbols,str1[i]) == NULL) {
                printf("ERROR! En la cadena %s, %c no es un elemento del alfabeto\n", str1, str1[i]);
                curr = -1;
                break;
            }

            int ele=(int)(str1[i]);

            curr=mat[curr][ele];

            if (curr == -1) {
                printf("ERROR! Regla invalida!\n");
                break;
            }
        } 

        if (curr != -1) {
            printf("La cadena %s es", str1);

            if(mark[curr]==1)

                printf("aceptada");

            else

                printf("rechazada");

            nline;
        }
    }

    
    return 0;

}

