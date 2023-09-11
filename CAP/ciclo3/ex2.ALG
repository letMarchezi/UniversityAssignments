Algoritmo "Ciclo 3 - Exercicio 2"
// Disciplina  : [Construção de Algoritmos e Programação]
// Professor   : Dr. Ednaldo Pizzolato
// Descrição   : Mostra os 30 primeiros números primos
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 12/09/2020
// RA          : 791003

Var
// Seção de Declarações das variáveis 
   divisores, i, numero, contador: inteiro

Inicio
contador<-0
numero<-2
divisores<-0

 enquanto contador<>30 faca  //enquanto o programa não encontrar os 30 primos

      para i<-2 até numero-1 faça
           se(numero%i=0)então   // condição de número primo
                divisores<-divisores+1
           fimse
      fimpara
      se (divisores=0)entao
            escreva(numero," ")
            contador<-contador+1
      fimse
      numero<-numero+1
      divisores<-0
fimenquanto
      



Fimalgoritmo