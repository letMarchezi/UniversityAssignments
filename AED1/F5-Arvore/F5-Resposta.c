/*
Nome: Leticia Bossatto Marchezi
Matéria: Algoritmo e Estrutura de Dados 1
Data: 08/06/2021
Assunto: Árvore binária

*/

#include <stdio.h>
#include <stdlib.h>


typedef int Chave;


typedef struct no{
    Chave chave;
    int tam;
    struct no *esq, *dir, *pai;

} No;

typedef struct arvore{
     No * raiz;
}Arvore;

void em_ordem(No * raiz){
    if(raiz != NULL){
        em_ordem(raiz->esq);
        printf("%d ", raiz->chave);
        em_ordem(raiz->dir);
    }
}

void pre_ordem(No * raiz){
    if(raiz != NULL){
        printf("%d ", raiz->chave);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}


void pos_ordem(No * raiz){
    if(raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->chave);
    }
;
}


/**
* Aloca um novo no com chave ch e conteudo inf e retorna-o
**/

No * criaNo(Chave ch){
    No * novono;
    novono = malloc(sizeof(No));
    novono->chave = ch;
    novono->pai = NULL;
    novono->dir = NULL;
    novono->esq = NULL;
    novono->tam = 1;
    return novono;
}

/**
* Insere o nocriado na arv, retornando um ponteiro para ele
* Ordem da altura da arvore
**/
No * insererec(No * raiz, No * novo){
     if(raiz == NULL){
        novo->pai = NULL;
        return novo;
     }
     raiz->tam ++;//ao passar pelo no significa o novo eh descendente dele
     if(novo->chave <= raiz->chave){
        raiz->esq = insererec(raiz->esq,novo);
        raiz->esq->pai = raiz;
     }else{
        raiz->dir = insererec(raiz->dir,novo);
        raiz->dir->pai = raiz;
     }
     return raiz;
 }


/**
* apaga todos os nos apontados por raiz
**/
No * destroi(No * raiz){
     if(raiz == NULL)
        return NULL;
     if(raiz->dir == NULL && raiz->esq ==NULL){
        free(raiz);
        return NULL;
     }
     if(raiz->esq != NULL)
        raiz->esq = destroi(raiz->esq);
     if(raiz->dir != NULL)
        raiz->dir = destroi(raiz->esq);
     return destroi(raiz);
}

/**
* retorna um ponteiro para o no com chave ch ou NULL
**/
No * busca (No * raiz, Chave ch){
    if (raiz == NULL)
        return NULL;
    if (raiz->chave == ch)
        return raiz;
    if (ch <=raiz->chave )
        return busca(raiz->esq,ch);
    else
        return busca(raiz->dir,ch);

}


/**
* retorna um ponteiro para o no com chave ch ou NULL
* vai decrementando o valor do tamanho
**/
No * diminuirtam(No * raiz, Chave ch){
    if (raiz == NULL)
        return NULL;
    raiz->tam--;
    if (raiz->chave == ch)
         return raiz;
    if (ch <=raiz->chave )
        return diminuirtam(raiz->esq,ch);
    else
        return diminuirtam(raiz->dir,ch);

}


int main(){
    Arvore * arv = malloc(sizeof(Arvore));

    //entrada 1 numero de elementos da arvore
    //entrada 2 lista de elementos a ser inserido em sequencia na árvore
    int i, n;
    scanf("%d",&n);
    int * v = (int *)malloc(n*sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d",&v[i]);

    No * novono;
    arv->raiz = criaNo(v[0]);
    for (i = 1; i < n; i++){
        novono = criaNo(v[i]);
        insererec(arv->raiz,novono);
    }

    printf("\nEm-ordem: ");
    em_ordem(arv->raiz);
    printf("\nPre-ordem: ");
    pre_ordem(arv->raiz);
    printf("\nPos-ordem: ");
    pos_ordem(arv->raiz);
    printf("\n");

    destroi(arv->raiz);
    arv->raiz = NULL;
    free(arv);
    return 0;
}


