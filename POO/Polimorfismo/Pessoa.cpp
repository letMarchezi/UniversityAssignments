/*
Autor(es): 
Leticia Bossato Marchezi
João Otavio Martini Korczovei
Luana de Queiroz Garcia
Luís Augusto Simas do Nascimento
Vitor Caligaris Figueira

Data de Criação: 12/04/2021
Data de Atualização: 12/04/2021

Objetivos: Métodos de Pessoa
*/

#include "Pessoa.h"

namespace poo {

  Pessoa::Pessoa(const string &_nome, int _idade) {
    setNome(_nome);
    setIdade(_idade);
  }

  void Pessoa::setNome(const string &_nome) {
    if (_nome.length() > 0) {
      nome = _nome;
    } else {
      nome = " ";
    }
  }

  void Pessoa::setIdade(int _idade) {
    if (_idade > 0) {
      idade = _idade;
    } else {
      idade = 0;
    }
  }

  string Pessoa::getNome() const { return nome; }

  int Pessoa::getIdade() const { return idade; }

  bool Pessoa::adicionaAnimal(Animal* _animal) {
    /* A função insert adiciona o elemento no vector e  retorna
     um iterator (que nada mais é que um ponteiro) apontando
     para o elemento adicionado, a partir disso podemos usar
     o operador * para acessar o elemento em si e verificar
     se ele não é nulo, ou seja, se ele existe e foi adicionado
     corretamente no vector*/
    if ((*animais.insert(animais.end(), _animal)) != NULL) {
      return true;
    } else {
      return false;
    }
  }

  bool Pessoa::removeAnimal(string _nomeAnimal) {
    // Caso o vetor esteja vazio
    if (animais.size() <= 0){
      return false;
    }

    unsigned int count = 0;
    bool encontrou = false;

    do {
      // Verifica se o nome é igual
      if (!(animais.at(count)->getNome().compare(_nomeAnimal))){
        // Remove o elemento do vetor na posição atual
        animais.erase(animais.begin() + count);

        encontrou = true;
      }else {
        count ++;
      }

    } while (!encontrou && (count < animais.size()));

    return encontrou;
  }

  Animal* Pessoa::obtemAnimal(string _nomeAnimal) {
    // Caso o vetor esteja vazio
    if (animais.size() <= 0){
      return nullptr;
    }

    unsigned int count = 0;
    bool encontrou = false;

    do {
      if (!(animais.at(count)->getNome().compare(_nomeAnimal))){

        encontrou = true;
      }else {
        count++;
      }
    } while (!encontrou && (count < animais.size()));

    // Caso tenha encontrado um animal com o nome correspondente
    // retorna o elemento (ponteiro para animal), caso contrário
    // retorna um ponteiro nulo
    if (encontrou) {
      return animais.at(count);
    }else{
      return nullptr;
    }

  }

  int Pessoa::qtdeAnimais() {
    return animais.size();
  }

  int Pessoa::qtdePeixes(){
    // Caso o vetor esteja vazio
    if (animais.size() <= 0) {
      return 0;
    }

    unsigned int quantidade = 0;

    for (unsigned int i = 0; i < animais.size(); i++) {
      if (animais.at(i)->getEspecie() == "Peixe"){
        quantidade++;
      }
    }

    return quantidade;
  }

  int Pessoa::qtdeCachorros() {
    // Caso o vetor esteja vazio
    if (animais.size() <= 0) {
      return 0;
    }

    unsigned int quantidade = 0;

    for (unsigned int i = 0; i < animais.size(); i++) {
      if (animais.at(i)->getEspecie() == "Cachorro"){
        quantidade++;
      }
    }

    return quantidade;
  }

  void Pessoa::imprime(int criterio) {
    cout << "Dono: " << endl << "Nome: " << nome << endl
      << "Idade: " << idade << endl << endl;

    // Verificando antes se o critério é válido, pois
    // a operação de ordenação é custosa
    if ((animais.size() > 0) && ((criterio >= 0) && (criterio <= 2))) {
      // Ordenando alfabeticamente usando a o método sort
      // aqui estamos usando uma função anônima para dizer
      // ao método sort como devemos comparar. A comparação
      // é feita diretamente sobre os nomes dos objetos passados.
      sort(animais.begin(), animais.end(), [](Animal* a, Animal* b) {
        return a->getNome() < b->getNome();
      });

      switch (criterio) {
        // Imprimir todos os animais
        case 0:
          for (unsigned int i = 0; i < animais.size(); i++){
            animais.at(i)->imprime();
          }
          break;

        // Imprimir apenas os peixes
        case 1:
          for (unsigned int i = 0; i < animais.size(); i++){
            if (animais.at(i)->getEspecie() == "Peixe"){
              animais.at(i)->imprime();
            }
          }
          break;

        // Imprimir apenas os cachorros
        case 2:
          for (unsigned int i = 0; i < animais.size(); i++){
            if (animais.at(i)->getEspecie() == "Cachorro"){
              animais.at(i)->imprime();
            }
          }
          break;
      }
    } else {
      cout << "Critério inválido" << endl;
    }
  }
}

