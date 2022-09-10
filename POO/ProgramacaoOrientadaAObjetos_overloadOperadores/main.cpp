/*

Objetivo: Arquivo main para testes da classe Racional

*/

#include <iostream>
#include "Racional.h"

using namespace std;

int main() {

  // Instancia os objetos de racionais
  Racional r1(4, 6);
  Racional r2(6, 10);
  Racional r3(2, 3);
  Racional r4(3, 3);

  // Testes dos métodos implementados
  cout << boolalpha << endl;
  cout << "r1 => " << r1 << endl;
  cout << "r2 => " << r2 << endl;
  cout << "r3 => " << r3 << endl;
  cout << "r4 => " << r4 << endl;
  cout << "(r1 + r2) => " << r1 + r2 << endl;
  cout << "(r1 - r2) => " << r1 - r2 << endl;
  cout << "(r1 * r2) => " << r1 * r2 << endl;
  cout << "(r1 / r2) => " << r1 / r2 << endl;
  cout << "(r1 < r2) => " << (r1 < r2) << endl;
  cout << "(r1 < r3) => " << (r1 < r3) << endl;
  cout << "(r1 <= r2) => " << (r1 <= r2) << endl;
  cout << "(r1 <= r3) => " << (r1 <= r3) << endl;
  cout << "(r1 == r2) => " << (r1 == r2) << endl;
  cout << "(r1 == r3) => " << (r1 == r3) << endl;
  cout << "(r1 != r2) => " << (r1 != r2) << endl;
  cout << "(r1 != r3) => " << (r1 != r3) << endl;
  cout << "(r1 >= r2) => " << (r1 >= r2) << endl;
  cout << "(r1 >= r3) => " << (r1 >= r3) << endl;
  cout << "(r1 > r2) => " << (r1 > r2) << endl;
  cout << "(r1 > r3) => " << (r1 > r3) << endl;
  cout << endl;

  return 0;
}