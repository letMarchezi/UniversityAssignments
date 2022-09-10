/*
Autor(es): 
Leticia Bossato Marchezi
João Otavio Martini Korczovei
Luana de Queiroz Garcia
Luís Augusto Simas do Nascimento
Vitor Caligaris Figueira

Data de Criação: 12/04/2021
Data de Atualização: 12/04/2021

Objetivos: Métodos de Cachorro
*/

#include <iostream>
#include<string.h>

using namespace std;

#include "Cachorro.h"

namespace poo {
  Cachorro::Cachorro(const string &n, double p,  const string &r) : Animal(n, p){//Construtor para Cachorro
    setRaca(r);
  }

  Cachorro::~Cachorro(){//Destrutor para Cachorro

  }

  string Cachorro::getRaca() const{//Obtem raca
    return raca;
  }

  void Cachorro::setRaca(const string &r){//Ajusta a raca
    raca = r;
  }

  string Cachorro::getEspecie() const{//Obtem a especie
    return "Cachorro";
  }

  void Cachorro::imprime() const{//Imprime dados de cachorro
    Animal::imprime();
    cout << "Raca: " << getRaca() << endl << endl;
  }
}