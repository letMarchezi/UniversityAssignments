/*
Nome: Leticia Bossatto Marchezi
RA: 791003
Turma: Bacharelado em Ciência da Computacao 020
Prof. Dr. Roberto Ferrari Junior
Materia: Algoritmo e Estrutura de Dados
Objetivo: arquivo de interface da classe Fila

*/

#ifndef FILA_H
#define FILA_H
#include <string>
#include <cstring>

#define TAM_MAX 300 // Constante que define o tamanho maximo do vetor da fila
using namespace std;

// Declaracao da classe Fila
class Fila{
    public:
        // Operacoes primitivas TAD 
        bool Vazia();
        bool Cheia();
        void Retira(string &, bool &);
        void Insere(string &, bool &); 
        Fila();
        
    
    //private:
        // Atributos da fila
        string filmes[TAM_MAX]; // Vetor de nome de filmes
        int qtdElementos; // Quantidade de elementos atual

};


#endif