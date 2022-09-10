/*
Autor(es): 
Leticia Bossato Marchezi
João Otavio Martini Korczovei
Luana de Queiroz Garcia
Luís Augusto Simas do Nascimento
Vitor Caligaris Figueira

Data de Criação: 12/04/2021
Data de Atualização: 12/04/2021

Objetivos: Interface de Pessoa
*/

#ifndef PESSOA_H
#define PESSOA_H

// Bibliotecas
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Animal.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

namespace poo {

  class Pessoa {
    private:
      string nome;
      int idade;

      // Vetor de animais de estimação (relação de associação)
      vector <Animal*> animais;

    public:
      // Construtor único
      Pessoa(const string &, int = 0);

      // Setters
      void setNome(const string &);
      void setIdade(int _idade);

      // Getters
      string getNome() const;
      int getIdade() const;

      // Adiciona um animal na lista de animais de estimação
      bool adicionaAnimal(Animal* animal);

      // Remove um animal da lista de animais de estimação
      bool removeAnimal(string _nomeAnimal);

      // Retorna um animal da lista de animais de estimação,
      // caso não haja nenhum correspondende retorna um ponteiro nulo
      Animal* obtemAnimal(string _nomeAnimal);

      // Retorna a quantidade de animais de estimação da pessoa
      int qtdeAnimais();

      // Retorna a quantidade de peixes de estimação da pessoa
      int qtdePeixes();

      // Retorna a quantidade de cachorros de estimação da pessoa
      int qtdeCachorros();

      // Imprime as informações e animais da pessoa de acordo com o critério.
      // Critério padrão = 0 (imprime todos os animais)
      void imprime(int criterio = 0);

  };
}

#endif
