/*
Autor(es): 
Leticia Bossato Marchezi
João Otavio Martini Korczovei
Luana de Queiroz Garcia
Luís Augusto Simas do Nascimento
Vitor Caligaris Figueira

Data de Criação: 12/04/2021
Data de Atualização: 12/04/2021

Objetivos: Interface de Animal
*/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
using namespace std;

namespace poo {
  //definicao de classe abstrata Animal
  class Animal {
    private:
      string nome;
      double peso;

    public:
      Animal(const string &, double = 0.0);
      virtual ~Animal();

      string getNome() const;
      double getPeso() const;

      void setNome(string);
      void setPeso(double);

      virtual string getEspecie() const = 0;
      virtual void imprime() const;
  };

};

#endif
