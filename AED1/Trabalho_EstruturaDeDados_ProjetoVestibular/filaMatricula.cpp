#include "filaMatricula.h"

// Criacao 
// Usa o mesmo método de criacao de listaCandidatos.h
// Celula *criaLista();

// Lista Vazia 
// Usa o método listaVazia() de listaCandidatos.h
// bool listaVazia(Celula *);


// Insere o candidato(se existir) com numero de inscricao passado 
// por parametro na lista de matriculados.
void insereMatriculado(FilaMatricula *f, ClassificacaoCandidato *classif, int inscricao, bool &erro){
  double notaCorte;
  Candidato *candInserir;
  
  // Encontra o candidato na lista de classfificacao
  candInserir = buscaCandidato(classif, inscricao);
  notaCorte = calcularNotaCorte(f, classif);
  
  if(candInserir!=NULL){
    // Se o candidato vai se matricular e sua nota é >= nota de corta, então insere
    if(candInserir->matriculado == false && candInserir->nota >= notaCorte){
      erro = 0;
      Celula *nova = new Celula;
      FilaMatricula *percorreFila = f;
      candInserir->matriculado=true;
      nova->dados=*candInserir;

      while (percorreFila->prox != NULL)
      {
        percorreFila = percorreFila->prox;
      }
      percorreFila->prox = nova;
      nova->prox = NULL;
    }
  }
  else{
    erro = 1;
  }
    
}

void mostrarMatriculados(FilaMatricula *f)
{
  Celula *aux = f->prox;
  if(listaVazia(f)==0){
    while (aux != NULL){
      cout << "Nome:"                << aux->dados.nome << endl;
      cout << "Numero da inscricao:" << aux->dados.numInscricao << endl << endl;
      aux = aux->prox;
    }
  }else{
    cout<<"Não há candidatos matriculados ainda."<<endl << endl;
  }
  cout<<endl;
}

// Calcula a nota de corte contando quantos alunos estão matriculados e quantas vagas estão disponíveis
double calcularNotaCorte(FilaMatricula *matricula, ClassificacaoCandidato *classif)
{
  FilaMatricula *f;
  ClassificacaoCandidato *c;
  double nota = 1001;
  int contador = 0;

  // Contar pessoas matriculadas já
  if(listaVazia(matricula)==0){
    f = matricula->prox;
    while (f != NULL)
    {
      contador++;
      nota = f->dados.nota;
      f = f->prox;
    }
  }
  
  // Outras chamadas
  if(listaVazia(classif)==0){
    c=classif->prox;
    while (c != NULL && contador < (c->dados.cursoCandidato.qtdVagas))
    {
      if(c->dados.nota < nota){
        nota = c->dados.nota;
        contador++;
      }
      c=c->prox;
    }
  }
  return nota;
}