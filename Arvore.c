#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"


struct No *inserir(struct No * arv, int num){
    struct No *nwNo = (struct No*) malloc(sizeof(struct No));
    
    if(nwNo==NULL){
        printf("ERRO MEMORIA!");
        return NULL;
    }

    nwNo->num = num;
    nwNo->FB=0;
    nwNo->fdir=NULL;
    nwNo->fesq = NULL;

    if(arv==NULL)
        return nwNo;
    
    if(num>arv->num){
        if(arv->fdir!=NULL){
            arv->fdir = inserir(arv->fdir,num);
            arv = verificarBalanceamento(arv); 
        }
        else{
            arv->fdir = nwNo;
            arv->FB = CalcularBalanceamento(arv);
        }
    }
    else if(num<arv->num){
        if(arv->fesq!=NULL){
            arv->fesq = inserir(arv->fesq,num);
            arv = verificarBalanceamento(arv); 
        }else{
            arv->fesq = nwNo;
            arv->FB = CalcularBalanceamento(arv);
        }
    }
    return arv;
}
struct No* rotacionarDireita(struct No*arv){
    if(arv==NULL){
        printf("\nArvore é nula!");
        return NULL;
    }
    struct No* A=NULL;
    struct No* B=NULL;
    struct No* C=NULL;
    
    B=arv;
    A = B->fesq;
    if(A->FB<0){
        A = rotacionarEsquerda(A);
    }
    B->fesq = NULL;
    if(A->fdir!=NULL){
        C = A->fdir;
        B->fesq = C;
        A->fdir = NULL;
    }
    A->fdir=B;
    A->fdir->FB = CalcularBalanceamento(A->fdir);
    A->FB=CalcularBalanceamento(A);
    return A;
}
struct No* rotacionarEsquerda(struct No*arv){
    if(arv==NULL){
        printf("\nArvore é nula!");
        return NULL;
    }
    struct No* A=NULL;
    struct No* B=NULL;
    struct No* C=NULL;
    
    B=arv;
    A = B->fdir;
    if(A->FB>0){
        A = rotacionarDireita(A);
    }
    B->fdir = NULL;
    if(A->fesq!=NULL){
        C = A->fesq;
        A->fesq = NULL;
        B->fdir = C;
    }
    A->fesq = B;
    A->fesq->FB = CalcularBalanceamento(A->fesq);
    A->FB=CalcularBalanceamento(A);
    return A;
}
int CalcularBalanceamento(struct No* arv){
    if(arv==NULL)
        return 0;

    int qt=0,qtD=0,i=0,res=0;
    struct No *aux = NULL;

    while(i<2){
        if(i==0){ 
            aux = arv->fdir;
            if(aux!=NULL){qt++;}
        }
        if(i==1){
            aux= arv->fesq;
            qtD = qt;
            qt=0;
            if(aux!=NULL){qt++;}    
        }
        while(aux!=NULL){
            if(aux->FB>0){
                aux = aux->fesq;
                qt++;
            }
            else if( aux->FB<0){
                aux = aux->fdir;
                qt++;
            }
            else{
               aux = aux->fesq;
               if(aux!=NULL){qt++; }  
            }
        }
        i++;
    }
    res = qt-qtD;
    return res;
}
struct No* menorNoDireita(struct No *arv){
    if(arv->fesq!=NULL){
        return menorNoDireita(arv->fesq);
    }else{
        return arv;
    }
    
}
struct No* remover(struct No* arv, int num){
    if(arv==NULL)
        return NULL;
    struct No* aux=arv;
    
    if(arv->num==num){
        if(arv->fdir!=NULL && arv->fesq!=NULL){
            aux = menorNoDireita(arv->fdir);
            arv->num = aux->num;
            arv->fdir = remover(arv->fdir,aux->num);
            arv = verificarBalanceamento(arv); 
        }else{
            if(arv->fesq==NULL){
                arv=aux->fdir;
            }else{
                arv=aux->fesq;
            }
            free(aux);
        }

    }else if(num>arv->num){
        arv->fdir = remover(arv->fdir,num);
        arv = verificarBalanceamento(arv); 
    }
    else if(num<arv->num){
        arv->fesq = remover(arv->fesq,num);
        arv = verificarBalanceamento(arv); 
    }
    return arv;
}
struct No* verificarBalanceamento(struct No* arv){
    arv->FB = CalcularBalanceamento(arv);
    if(arv->FB<=-2){ 
        arv = rotacionarEsquerda(arv);
    }else if(arv->FB>=2){
        arv = rotacionarDireita(arv);
    }
    return arv;
}
//bruno
void ordem_central(struct No *arv) {
	if(arv == NULL)
		printf("()");
	else {
		printf("(");
		ordem_central(arv->fesq);
		printf(" N:%d /F:%d  ", arv->num,arv->FB);
		ordem_central(arv->fdir);
		printf(")");
	}
}
void imprimir(struct No *arv) {
	if(arv == NULL)
		printf("Árvore vazia!");
	ordem_central(arv);
	printf("\n");
}
