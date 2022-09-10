#ifndef CLASSIFICACAOCANDIDATOS_H
#define CLASSIFICACAOCANDIDATOS_H
#include "listaCandidato.h"


typedef Celula ClassificacaoCandidato;

void insereClassificacao(ClassificacaoCandidato *, ListaCandidato *);
void ordenaClassificacao(ClassificacaoCandidato *);
void imprimeClassificados(ClassificacaoCandidato *);  


#endif