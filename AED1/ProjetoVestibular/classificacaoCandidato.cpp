#include "classificacaoCandidato.h"


// Criacao 
// Usa o mesmo método de criacao que a lista de candidatos
// Celula *criaLista();

// Lista Vazia 
// Usa o método listaVazia() de listaCandidatos.h
// bool listaVazia(Celula *);


// Insercao
// Lista cadastral ordenada de forma decrescente de acordo com a nota
void insereClassificacao(ListaCandidato *lista, ClassificacaoCandidato *fila){
  ListaCandidato *auxiliar;
  ClassificacaoCandidato *nova;
  Celula *cel;
  // Lista não possui elementos 
  if(fila->prox==NULL){
    auxiliar = lista->prox;
    nova = fila;
    // Insere todos os candidatos
    while(auxiliar!=NULL){
      cel = new Celula;
      cel->prox = NULL;
      cel->dados = auxiliar->dados;
      nova->prox = cel;

      auxiliar=auxiliar->prox;
      nova=nova->prox;
    
    }
    // Função de ordenação
    ordenaClassificacao(fila);
  }
}

// Ordenação
// Função de ordenação bubble sort
void ordenaClassificacao(ClassificacaoCandidato *atual){
  ClassificacaoCandidato *index;
  Candidato auxcand;

  // Loop de ordenação  
  if(listaVazia(atual)==0){
    atual = atual->prox; // Aponta para o primeiro elemento válido
    while(atual!=NULL){
      index=atual->prox; 

      while(index!=NULL){ // Compara o anterior com o atual para trocar
        if((index->dados.nota)>(atual->dados.nota)){
          auxcand = atual->dados;
          atual->dados=index->dados;
          index->dados=auxcand;
        }else{
          index=index->prox;
        }
      }
      atual=atual->prox;
    }
  }
}



// Mostra todos os candidatos da lista 
void imprimeClassificados(ClassificacaoCandidato *fila){
  int cont = 1;
  ClassificacaoCandidato *aux;
  if(listaVazia(fila)==0){
    cout << " ------ ALUNOS DISPUTANDO ------" << "\n\n";
    aux = fila->prox;
    while(aux!=NULL){
      cout<<"Posicao: "<<cont<<"º Colocado"<<endl;
      cout << "Nome: "                << aux->dados.nome << endl;
      cout << "Numero da inscricao: " << aux->dados.numInscricao << endl;
      cout << "Nota: "                << aux->dados.nota << endl;
      cout << "Curso: "               << aux->dados.cursoCandidato.nomeCurso << endl;
      if(!aux->dados.matriculado){
        cout << "Ainda não matriculado!"<< endl;
      }else{
        cout << "Ja esta matriculado!"<< endl;
      }
      
      cout << endl;
      aux=aux->prox;
      cont++;
    }
  }else{
    cout<<"A classificacao dos candidatos nao esta disponivel"<<endl;
  }
}

