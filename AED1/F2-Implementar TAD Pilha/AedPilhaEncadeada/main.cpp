/*
Nome: Leticia Bossatto Marchezi
RA: 791003
Turma: Bacharelado em Ciência da Computacao 020
Prof. Dr. Roberto Ferrari Junior
Materia: Algoritmo e Estrutura de Dados
Objetivo: Programa principal para testar pilha com alocacao encadeada e dinamica
*/

#include "Pilha.h"

// Metodo para impressao dos elementos da pilha
void imprimirPilha(Modulo *pilha){
    string titulo;
    Modulo *pilhaAux=criaPilha();
    bool resultado;
    cout << "\nImprimindo a pilha: "<<endl;
    cout << "------ TOPO ------" << endl;
    // Loop para retirar elementos da pilha principal e passa-los para a pilha auxiliar
    while (pilhaVazia(pilha) == false){
      titulo = Desempilha(pilha);
      // Imprime os titulos
      cout << titulo << endl;
      resultado=Empilha(pilhaAux, titulo);
    }
    cout << "------ FIM ------" <<endl<<endl;
    // Loop para devolver os elementos para a pilha principal
    while (pilhaVazia(pilhaAux) == false) {
      titulo = Desempilha(pilhaAux);
      resultado=Empilha(pilha, titulo);
    } 
    // Libera a memoria alocada para pilhaAux
    liberaPilha(pilhaAux);
}

// Programa principal
int main() {
    
  string nome;
  Modulo *colecao;
  colecao=criaPilha();
  // INSERINDO FILMES
  cout<<"------------------INSERCAO------------------"<<endl;
  cout<<"Inserindo..."<<endl;
  nome = "Princesa Mononke";
  if(Empilha(colecao, nome)){
    cout<<"filme "<<nome<<" inserido."<<endl;
  }  
  nome = "O Servico de Entregas de Kiki";
  if(Empilha(colecao, nome)){
    cout<<"filme "<<nome<<" inserido."<<endl;
  }
  nome = "Castelo Animado";
  if(Empilha(colecao, nome)){
    cout<<"filme "<<nome<<" inserido."<<endl;
  }
  cout<<"--------------------------------------------"<<endl;
    
  // Mostra se a pilha esta vazia
  cout<<"Pilha "<<(pilhaVazia(colecao) ? "esta vazia":"nao esta vazia")<<endl;

  // Impressao dos elementos
  cout<<"------------------IMPRIMIR------------------"<<endl;
  imprimirPilha(colecao);
  cout<<"--------------------------------------------"<<endl;

  // Teste de desempilhar
  cout<<"\n------------------DESEMPILHAR------------------"<<endl;
  cout<<"Desempilhando..."<<endl;
  for(int i=0; i<3; i++){
    cout<<"Titulo do filme: "<<Desempilha(colecao)<<endl;
  }
  
  // Mostra se a pilha esta vazia
  cout<<"-----------------------------------------------"<<endl;
  cout<<"Pilha "<<(pilhaVazia(colecao) ? "esta vazia":"nao esta vazia")<<endl<<endl;

  cout<<"Tentando desempilhar sem elementos na pilha..."<<endl;
  nome=Desempilha(colecao);

  return 0;
}
