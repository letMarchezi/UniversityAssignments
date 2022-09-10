#ifndef LISTACANDIDATO_H
#define LISTACANDIDATO_H
#include <iostream>
#include <string>
using namespace::std;


// Dados do curso
typedef struct curso {
  // acho q precisa colocar um ponteiro pra lista de candidatos
  string nomeCurso;
  int codCurso;
  double notaDeCorte;
  int qtdVagas;
} Curso;


// Dados do candidato, conteudo da celula
typedef struct candidato {
  int numInscricao;
  double nota;
  string nome;
  bool matriculado = false;
  Curso cursoCandidato;
} Candidato;

// No de candidato
typedef struct celula {
  Candidato dados;
  struct celula *prox;
} Celula;
typedef Celula ListaCandidato;

// Criação
Candidato criarCandidato(int, string, double, Curso);
Celula *criaLista();

// Listas
Candidato removeUm(ListaCandidato *, int, bool &);
void removeTodos(ListaCandidato *l, bool &);
void destroi(ListaCandidato *l, bool &);
Candidato *buscaCandidato(ListaCandidato *, int);
void imprimeCandidatos(ListaCandidato *);
void insereCandidato(ListaCandidato *, Candidato);
bool listaVazia(ListaCandidato *);


#endif