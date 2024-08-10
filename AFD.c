#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FAFD.h"

int main(int argc, char *argv[])
{
    // Automata por defecto
    if (argc == 1)
    {
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
