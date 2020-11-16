#include <stdio.h>
#include "funcs.h"

int main()
{
    int autenticado;
    autenticado = login();
    if(autenticado) {
         home();
    }else {
        printf("Problemas no login.");
    }
    return 0;
}
