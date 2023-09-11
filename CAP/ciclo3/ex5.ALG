Algoritmo "Ciclo 3 - Exercicio 5"
// Disciplina  : [Construção de Algoritmos e Programação]
// Professor   : Dr. Ednaldo Pizzolato
// Descrição   : Digite a quantidade de elementos da sequencia de fibonacci a serem mostrados
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 12/09/2020
// RA          : 791003

Var
// Seção de Declarações das variáveis 
i, numero, elementon, elementoum, elementodois :inteiro

Inicio
escreva("Digite a quantidade de numeros a serem mostrados: ")
leia(numero)

para i<-1 ate numero faça
  se(i=1)ou(i=2)entao
     elementon<-1
     elementoum<-1
     elementodois<-1
     escreva(elementon," ")       // imprime o resultado
  senao
     elementon<-elementoum+elementodois
     escreva(elementon," ")          // imprime o resultado
     elementodois<-elementoum  // substitui o elemento n-2 pelo n-1 anterior
     elementoum<-elementon     // substitui o elemento n-1 pelo atual
  fimse
fimpara
  

Fimalgoritmo