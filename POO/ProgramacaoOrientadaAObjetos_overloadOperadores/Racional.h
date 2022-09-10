/*


*/

#ifndef RACIONAL_H
#define RACIONAL_H
#include <iostream>

using namespace std;

class Racional{

  private:
    int numerador, denominador;

    //metodo de simplificar fração
    void simplificar();

  public: 
    //construtor
    Racional(int, int);

    //getters e setters
    int getNumerador();
    int getDenominador();

    void setNumerador(int);
    void setDenominador(int);
    void setNumeroRacional(int, int);

    // Somar dois números racionais
    Racional operator+(const Racional &operando);

    // Subtrair dois números racionais
    Racional operator-(const Racional &operando);

    // Multiplicar dois números racionais
    Racional operator*(const Racional &operando);

    // Dividir dois números reacionais
    Racional operator/(const Racional &operando);

    // Sobrecarga de operadores lógicos
    bool operator<(const Racional &operando);
    bool operator<=(const Racional &operando);
    bool operator>(const Racional &operando);
    bool operator>=(const Racional &operando);
    bool operator==(const Racional &operando);    
    bool operator!=(const Racional &operando);
    
    // Sobrecarga de operador de saída de dados
    friend ostream &operator<<(ostream &out, const Racional &operando);
};


#endif