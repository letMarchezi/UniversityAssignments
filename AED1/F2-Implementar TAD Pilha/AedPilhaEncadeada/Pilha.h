/*
Nome: Leticia Bossatto Marchezi
RA: 791003
Turma: Bacharelado em Ciência da Computacao 020
Prof. Dr. Roberto Ferrari Junior
Materia: Algoritmo e Estrutura de Dados
Objetivo: Arquivo de interface da classe Pilha com alocacao encadeada e dinamica usando no cabeca
*/

#ifndef PILHA_H
#define PILHA_H
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

// Estrutura do tipo modulo
typedef struct modulo{
    string filme;
    struct modulo *proximo;
}Modulo;

// Protótipo das funções
Modulo *criaPilha();
bool Empilha(Modulo *pilha, string titulo);
string Desempilha(Modulo *pilha);
string buscaTopo(Modulo *pilha);
bool pilhaVazia(Modulo *pilha);
int tamPilha(Modulo *pilha);
Modulo *liberaPilha(Modulo *pilha);

// Função que aloca a memória e cria a pilha
Modulo *criaPilha(){
    Modulo *pilha;
    pilha = new Modulo;
    pilha->proximo=NULL;
    return pilha;
}

// Empilha um novo modulo criando um no e colocando apos o no cabeca
bool Empilha(Modulo *pilha, string titulo){
    Modulo *pilhaAux;
    bool resultado;
    pilhaAux=new Modulo;

    pilhaAux->filme = titulo;
    pilhaAux->proximo = pilha->proximo;

    // Altera o elemento do topo para o novo no criado
    pilha->proximo = pilhaAux;
    
    // Verifica se o endereco do elemento do topo eh o mesmo do novo no
    if(pilha->proximo==pilhaAux){
      resultado=true;
    }else{
      resultado=false;
    }

    return resultado;
}

// Desempilha o elemento do topo alterando o endereco do ponteiro pilha->proximo
string Desempilha(Modulo *pilha){
    string titulo;
    Modulo *pilhaAntiga;

    pilhaAntiga=pilha->proximo;
    titulo = pilhaAntiga->filme;
    // Altera o ponteiro 
    pilha->proximo=pilhaAntiga->proximo;
    free(pilhaAntiga);
    pilhaAntiga=NULL;

    return titulo;
}

// busca o elemento do topo
string buscaTopo(Modulo *pilha){
    return pilha->proximo->filme;

}

// testa se a pilha esta vazia
bool pilhaVazia(Modulo *pilha){
    return(pilha->proximo==NULL);
} 

// Retorna o tamanho da pilha ao percorrer todos os elementos ate 
// o endereco do ponteiro "proximo" ser NULL, ou seja, eh o ultimo elemento
int tamPilha(Modulo *pilha){
    int tamanho=0;
    Modulo *pilhaAux;

    pilhaAux=pilha->proximo;
    while(pilhaAux!=NULL){
        pilhaAux=pilhaAux->proximo;
        tamanho = tamanho + 1;
    }
    return tamanho;

}

// Desaloca a memoria usada pela pilha
Modulo *liberaPilha(Modulo *pilha){
    Modulo *pilhaAntiga, *pilhaAux;

    pilhaAux=pilha;

    
    while(pilhaAux!=NULL){
        pilhaAntiga = pilhaAux;
        pilhaAux=pilhaAux->proximo;
        free(pilhaAntiga);
        pilhaAntiga=NULL;
    }

    return NULL;
}


#endif