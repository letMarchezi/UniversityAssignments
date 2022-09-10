#include <stdio.h>
typedef struct noh{
    int chave;
    int conteudo;
    int tam;
    struct noh *pai;
    struct noh *esq;
    struct noh *dir;
} Noh;

typedef Noh *Arvore;

int altura(Arvore r){
    int hesq, hdir;
    if(r == NULL )
        return -1;
    hesq=altura(r->esq);
    hdir=altura(r->dir);
    if(hesq>hdir)
        return hesq+1;
    return hdir+1;
}

Noh *novoNoh(int conteudo, int chave){
    Noh *novo = (Noh *)malloc(sizeof(Noh));
    novo->chave = chave;
    novo->conteudo = conteudo;
    novo->pai = NULL;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

Arvore *insereR(Arvore r, Noh *novo){
    if(r == NULL)
        return novo;
    if(novo->chave <= r->chave){
        r->esq=insereR(r->esq, novo);
        r->esq->pai=r;
    }else{
        r->dir = insereR(r->dir, novo);
        r->dir->pai = r;
    }
    return r;
}


int main(){
    printf("deu td certo!!!");
    return 0;
}