Algoritmo "Ciclo 3 - Exercicio 4"
// Disciplina  : [Construção de Algoritmos e Programação]
// Professor   : Dr. Ednaldo Pizzolato
// Descrição   : Digite o 1º elemento da PA, a razãoe a quantidade de elementos a serem mostrados
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 12/09/2020
// RA          : 791003

Var
// Seção de Declarações das variáveis 
razao, elementoum: real
numero, i: inteiro
Inicio

escreva("digite o primeiro elemento da PA: ")
leia(elementoum)

escreva("digite a razao da PA: ")
leia(razao)

escreva("digite a quantidade de elementos da PA a serem mostrados: ")
leia(numero)


para i<-1 ate numero faca
escreva(elementoum+(i-1)*razao)
fimpara


Fimalgoritmo