/*

Objetivo: Arquivo de métodos e sobrecargas da classe Racional

*/

#include <iostream>
#include "Racional.h"

using namespace std;

// Construtor de números racionaisr um numero racional ja simplificando-o.
Racional::Racional(int n, int d){
  if(d!=0){ // se o denominador informado for != de 0
    this->numerador = n;   // faz as atribuições para 
    this->denominador = d; // numerador e denominador
    if(this->denominador<0){ // se o denominador for menor que 0
      this->denominador = this->denominador * -1; // inverte os sinais e deixa
      this->numerador = this->numerador * -1;     // o negativo em cima
    }
    this->simplificar(); // realiza a simplificação do racional obtido

  } else { // é impossível uma divisão por 0, então não realiza operações e avisa
    cout << "ERRO! Denominador deve ser diferente de 0!";
  }
  
}

int Racional::getNumerador(){//Metodo get que obtem o numerador.
  return this->numerador;
}

int Racional::getDenominador(){//Metodo get que obtem o denominador.
  return this->denominador;
}

void Racional::setNumerador(int num){//Metodo set atribui um valor ao numerador.
  this->numerador=num;
}

void Racional::setDenominador(int den){//Metodo set atribui um valor ao denominador.
  this->denominador=den;
}

void Racional::setNumeroRacional(int num, int den){//Metodo set atribui um valor ao numerador e denominador.
    this->numerador=num;
    this->denominador=den;
}

void Racional::simplificar(){//Metodo que simplifica numeros racionais.
  int a, b;
  a = this->numerador;
  b = this->denominador;
  int resto;

  //calcula MDC (maximo divisor comum)
  do {
      resto = a % b;

      a = b;
      b = resto;
  } while (resto != 0);

  //resultado do MDC esta em 'a'
  //divide o numerador e denominador pelo MDC
  this->numerador = this->numerador / a;
  this->denominador = this->denominador / a;

  //se o denominador ficar negativo, passa sinal para o numerador
  if(this->denominador < 0){
      this->numerador *= -1;
      this->denominador *= -1;
  }
}

// Sobrecarga de operadores aritméticos
Racional Racional::operator+(const Racional &operando){
  Racional resultado((this->numerador * operando.denominador) + (this->denominador * operando.numerador), (this->denominador * operando.denominador));

   return resultado;
}

Racional Racional::operator-(const Racional &operando){
  Racional resultado((this->numerador * operando.denominador) - (this->denominador * operando.numerador), (this->denominador * operando.denominador));

  return resultado;
}

Racional Racional::operator*(const Racional &operando){
  Racional resultado(this->numerador * operando.numerador, this->denominador * operando.denominador);

  return resultado;
}

Racional Racional::operator/(const Racional &operando){
  Racional resultado(this->numerador * operando.denominador, this->denominador * operando.numerador);

  return resultado;
}

// Sobrecarga de operadores lógicos
bool Racional::operator<(const Racional &operando){
  return (this->numerador * operando.denominador) < (this->denominador * operando.numerador);
}

bool Racional::operator<=(const Racional &operando){
  return (*this < operando || *this == operando);
}

bool Racional::operator>(const Racional &operando){
  return !(*this <= operando);
}

bool Racional::operator>=(const Racional &operando){
  return (*this > operando || *this == operando);
}

bool Racional::operator==(const Racional &operando){
  return (this->numerador * operando.denominador) == (this->denominador * operando.numerador);
}

bool Racional::operator!=(const Racional &operando){
  return !(*this == operando);
}

// Sobrecarga de operador de saída de dados
ostream &operator<<(ostream &out, const Racional &operando){
  if(operando.denominador != 1){
    out << operando.numerador << "/" << operando.denominador; 
  }else{
    out << operando.numerador;
  }

  return out;
}