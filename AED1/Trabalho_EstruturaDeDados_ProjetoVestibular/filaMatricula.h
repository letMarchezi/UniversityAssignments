#ifndef FILAMATRICULA_H
#define FILAMATRICULA_H
#include "classificacaoCandidato.h"


typedef Celula FilaMatricula;

void insereMatriculado(FilaMatricula *f, ClassificacaoCandidato *classif, int inscricao, bool &);
void mostrarMatriculados(FilaMatricula *);  
double calcularNotaCorte(FilaMatricula *matricula, ClassificacaoCandidato *classif);

#endif