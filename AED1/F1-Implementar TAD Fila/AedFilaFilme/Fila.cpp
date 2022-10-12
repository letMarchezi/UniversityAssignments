#include "Fila.h"
#include <string>
#include <cstring>


// Construtor que inicializa a fila com 0 elementos
Fila::Fila(){
    qtdElementos=0;
}

// Testa se a fila esta vazia
bool Fila::Vazia(){
    // Se nao ha elementos na fila, retorna true
    if (qtdElementos==0){
        return true;
    }else{
        return false;
    }
}
// Testa se a fila esta cheia
bool Fila::Cheia(){
    // Se a quantidade de elementos inseridos for igual a constante TAM_MAX, retorna true
    if (qtdElementos==TAM_MAX){
        return true;
    }else{
        return false;
    }
    
}

// Retira um filme da fila passando como parametro o elemento excluido e o resultado da operacao
void Fila::Retira(string &saida, bool &deuCerto){
    // Se a fila esta vazia não é possivel retirar elementos
    if(Vazia()){
        deuCerto = false;
    }else{
        // O filme a ser retornado é atribuido ao ponteiro saida
        saida = filmes[0];
        // define o resultado da operacao como true
        deuCerto = true;
        // Laco de repeticao para mover os elementos para as primeiras posicoes
        for (int i = 0; i < qtdElementos; i++)
        {   
            // Move os elementos para o inicio e atribui para a ultima posicao uma string vazia
            if(i!=qtdElementos-1){
                filmes[i]=filmes[i+1];
            }else{
                filmes[i]="";
            }
            
        }
        // Diminui a quantidade de elementos do vetor
        qtdElementos=qtdElementos-1;
    }
    
}

// Insere o elemento passado como parametro
void Fila::Insere(string &entrada,bool &deuCerto){
    // Testa se a fila esta cheia
    if(Cheia()){
        deuCerto = false;
    }else{
        // Aumenta a quantidade de elementos da fila e adiciona o novo filme à ultima posicao
        deuCerto = true;
        qtdElementos++;
        filmes[qtdElementos-1]=entrada;
    }
}

