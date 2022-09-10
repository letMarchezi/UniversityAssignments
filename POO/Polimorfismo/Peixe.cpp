/*
Autor(es): 
Leticia Bossato Marchezi
João Otavio Martini Korczovei
Luana de Queiroz Garcia
Luís Augusto Simas do Nascimento
Vitor Caligaris Figueira

Data de Criação: 12/04/2021
Data de Atualização: 12/04/2021

Objetivos: Métodos de Peixe
*/

#include <iostream>
#include <string.h>

using namespace std;

#include "Peixe.h"

namespace poo {
  Peixe::Peixe( string n, double p, string h) : Animal(n, p){//Construtor para Peixe
    setTipoHabitat(h);
  }

  Peixe::~Peixe(){//Destrutor para peixe
  }

  string Peixe::getTipoHabitat() const{//Obtem o tipo de habitat
    return tipoHabitat;
  }

  void Peixe::setTipoHabitat(const string &s){//Ajusta o tipo de habitat
    tipoHabitat= s;
  }

  string Peixe::getEspecie() const{//Obtem a especie
    return "Peixe";
  }

  void Peixe::imprime() const{//Imprime os dados de peixe
    cout << "Peixe: " << endl;
    Animal::imprime();
    cout << "Tipo Habitat: " << getTipoHabitat() << endl<< endl;
  }
}