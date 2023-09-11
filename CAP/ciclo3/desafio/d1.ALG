Algoritmo "Ciclo 3 - Desafio 1"
// Disciplina  : [Construção de Algoritmos e Programação]
// Professor   : Dr. Ednaldo Pizzolato
// Descrição   : Digite um inteiro para calcular sua raiz
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 20/09/2020
// RA          : 791003

Var

numerok:inteiro
numerokum, numerozero: real
aux: real

Inicio


escreval("Digite o numero inteiro para calcular a raiz: ")
leia(numerok)

numerozero<-numerok/2
aux<-0
repita
  se(aux<>0)entao
  numerozero<-numerokum
  fimse
  
  
  numerokum<-numerozero-(numerozero^2-numerok)/(2*numerozero) //Cálculo do Método de Newton

  
  aux<-numerokum
até((abs(numerok-numerokum^2)<0.01)) // testa o valor absoluto, ou seja, erro<0,01

escreval("A raiz R que possui erro < 0,01 é:",numerokum)

escreval("A diferença entre o algortimo e a função pré-definida é:",numerokum-RAIZQ(numerok))



Fimalgoritmo