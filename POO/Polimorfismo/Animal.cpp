/*
Autor(es): 
Leticia Bossato Marchezi
João Otavio Martini Korczovei
Luana de Queiroz Garcia
Luís Augusto Simas do Nascimento
Vitor Caligaris Figueira

Data de Criação: 12/04/2021
Data de Atualização: 12/04/2021

Objetivos: Métodos de Animal
*/

#include <iostream>
#include <string.h>
#include "Animal.h"

using namespace std;

namespace poo {
  
  Animal::Animal(const string &n, double p){//Construtor para Animal
    nome = n;
    setPeso(p);
  }

  Animal::~Animal(){}//Destrutor para Animal
  
  string Animal::getNome() const{//Obtem nome do animal
    return nome;
  }
  double Animal::getPeso() const{//Obtem peso do animal
    return peso;
  }

  void Animal::setNome(string n){//Ajusta nome do animal
    nome = n;
  }
  
  void Animal::setPeso(double p){//Ajusta peso do animal
    peso = (p > 0.0) ? p : 0.0;
  }

  void Animal::imprime() const{//Imprime os dados do animal
    cout << "Nome: " << this->nome << endl;
    cout << "Peso: " << this->peso << endl;
    cout << "Especie: " << this->getEspecie() << endl;
  }
  
}