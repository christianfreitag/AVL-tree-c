#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

int main(){

    struct No * arvo=NULL;

    arvo=inserir(arvo,20);
    arvo=inserir(arvo,28);
    arvo=inserir(arvo,15);
    arvo=inserir(arvo,12);
    arvo=inserir(arvo,24);
    arvo=inserir(arvo,16);
    arvo=inserir(arvo,10);
    arvo=inserir(arvo,29);
    arvo=inserir(arvo,26);
    
    
    printf("\n Raiz: %d FBRaiz:%d\n",arvo->num,arvo->FB);
    imprimir(arvo);
    printf("\n");

    arvo = remover(arvo,20);

     printf("\n Raiz: %d FBRaiz:%d\n",arvo->num,arvo->FB);
    imprimir(arvo);
    printf("\n");
    

    return 0;
}