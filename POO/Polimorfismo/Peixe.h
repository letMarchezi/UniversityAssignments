/*
Autor(es): 
Leticia Bossato Marchezi
João Otavio Martini Korczovei
Luana de Queiroz Garcia
Luís Augusto Simas do Nascimento
Vitor Caligaris Figueira

Data de Criação: 12/04/2021
Data de Atualização: 12/04/2021

Objetivos: Interface de Peixe
*/

#ifndef Peixe_h
#define Peixe_h

#include <iostream>
#include <string.h>

using namespace std;

#include "Animal.h"

namespace poo{

  class Peixe : public Animal{
    //definicao da classe Peixe
      private:
        string tipoHabitat;

      public:
        Peixe( string , double, string);
        virtual ~Peixe();

        string getTipoHabitat() const;
        void setTipoHabitat(const string &);

        virtual string getEspecie() const;
        virtual void imprime() const;
  };
}

#endif