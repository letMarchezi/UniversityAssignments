/*
Autor(es): 
Leticia Bossato Marchezi
João Otavio Martini Korczovei
Luana de Queiroz Garcia
Luís Augusto Simas do Nascimento
Vitor Caligaris Figueira

Data de Criação: 12/04/2021
Data de Atualização: 12/04/2021

Objetivos: Interface de Cachorro
*/

//impede multiplas inclusoes de arquivo de cabeçalho
#ifndef CACHORRO_H
#define CACHORRO_H

#include <string>
using namespace std;

#include "Animal.h"

namespace poo {
  // definição classe Cachorro
  class Cachorro : public Animal {
      private:
        string raca;

      public:
          Cachorro(const string &, double, const string &);
          virtual ~Cachorro();

          string getRaca() const;
          void setRaca(const string &);

          virtual string getEspecie() const;
          virtual void imprime() const;
  };
};

#endif