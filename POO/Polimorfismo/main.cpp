/*
Autor(es): 
Leticia Bossato Marchezi
João Otavio Martini Korczovei
Luana de Queiroz Garcia
Luís Augusto Simas do Nascimento
Vitor Caligaris Figueira

Data de Criação: 12/04/2021
Data de Atualização: 12/04/2021

Objetivos: Arquivo principal para o trabalho P04
*/

// Bibliotecas
#include <iostream>
#include <string>

#include "Peixe.h"
#include "Pessoa.h"
#include "Cachorro.h"

using namespace poo;
using namespace std;

// Função principal
int main(int argc, char *argv[])
{
  Pessoa* pessoa = new Pessoa("Joao", 12);

  Peixe* nemo = new Peixe("Nemo", 0.15, "Água salgada");

  pessoa->adicionaAnimal(nemo);

  Peixe* dory = new Peixe("Dory", 0.2, "Água doce");

  pessoa->adicionaAnimal(dory);

  Cachorro* teo = new Cachorro("Teo", 6.2, "pug");

  pessoa->adicionaAnimal(teo);

  cout << "================== TODOS ==================" << endl << endl;

  pessoa->imprime();

  cout << "================== PEIXES ==================" << endl << endl;

  pessoa->imprime(1);

  cout << "================== CACHORROS ==================" << endl << endl;

  pessoa->imprime(2);

  cout << "================== REMOÇÃO DE UM ELEMENTO ==================" << endl << endl;

  pessoa->removeAnimal("Dory");

  pessoa->imprime();

  return 0;
}
