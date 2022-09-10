#include "listaCandidato.h"


Celula *criaLista(){
  Celula *novo;
  novo = new Celula;
  novo->prox = NULL;
  return novo;
}

void insereCandidato(ListaCandidato *l, Candidato cand){
  Celula *nova;
  ListaCandidato *aux=l;

  nova = new Celula;
  nova->dados = cand;
  while(aux->prox!=NULL){
    aux=aux->prox;
  }
  aux->prox=nova;
  nova->prox = NULL;
}

bool listaVazia(ListaCandidato *l){
  if(l->prox==NULL){
    return true;
  }else{
    return false;
  }
}

Candidato criarCandidato(int inscCand, string nomeCand, double notaCand, Curso cursoCand){
  Candidato c;

  c.numInscricao =   inscCand;
  c.nota =           notaCand;
  c.nome =           nomeCand;
  c.matriculado =    false;
  c.cursoCandidato = cursoCand;

  return c;
}

void imprimeCandidatos(ListaCandidato *l){
  Celula *aux;

  if(listaVazia(l)){
    cout << "Nenhum candidato concorrendo!" << "\n";
  }
  else{
    aux=l->prox;
    while(aux != NULL){
      cout << "Nome:"                << aux->dados.nome << endl;
      cout << "Numero da inscricao:" << aux->dados.numInscricao << endl;
      cout << "Nota:"                << aux->dados.nota << endl;
      cout << "Curso:"               << aux->dados.cursoCandidato.nomeCurso << endl;
      cout << "Ainda não matriculado!"<<endl;
      cout << endl << endl;
      aux = aux->prox;
    }
  }
}


Candidato removeUm(ListaCandidato *l, int numInscr, bool &erro){
  Celula *aux;
  Celula *ant=l;
  Candidato c;
  erro = true;

  if(listaVazia(l)==false){
    aux = l->prox;
    while (aux != NULL){
      if(numInscr == aux->dados.numInscricao){
        erro = false;
        c=aux->dados;
        ant->prox = aux->prox;
        delete aux;
        aux = NULL;
      }else{
        ant = aux;
        aux = aux->prox;
      }
    }
  }
  
  return c;
}

// usa auxiliar pra remover os nós exceto o header
void removeTodos(ListaCandidato *l, bool &erro){
  ListaCandidato *guardaProx, *inicioLista;
  inicioLista = l->prox;

  if(listaVazia(l)==false){

    while (inicioLista != NULL){
      guardaProx = inicioLista->prox;
      delete(inicioLista);
      inicioLista = guardaProx;
    }
  }
  l->prox=inicioLista; 

  if(l->prox==NULL){
    erro = 0;
  }else{
    erro = 1;
  }
}

// Busca um candidato de acordo com a sua inscricao
Candidato *buscaCandidato(ListaCandidato *l, int inscricao){
  ListaCandidato *percorreLista=l->prox;
  Candidato *candResultado;
  while(percorreLista!=NULL && percorreLista->dados.numInscricao != inscricao){
    percorreLista=percorreLista->prox;
    
  }
  if (percorreLista==NULL){
    candResultado=NULL;
  }
  else if(percorreLista->dados.numInscricao == inscricao){
    candResultado = &(percorreLista->dados);
  }
  
  return candResultado;
}


// destroi a lista ao desalocar todos os nós incluindo o header
void destroi(ListaCandidato *l, bool &erro){
  removeTodos(l, erro);
  if(erro == 0){
    delete(l);
    l = NULL;
  }
}