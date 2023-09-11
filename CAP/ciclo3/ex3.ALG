Algoritmo "Ciclo 3 - Exercicio 3"
// Disciplina  : [Construção de Algoritmos e Programação]
// Professor   : Dr. Ednaldo Pizzolato
// Descrição   : Mostra os múltiplos de 3 e 7 até 300
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 12/09/2020
// RA          : 791003

Var
// Seção de Declarações das variáveis 
i:inteiro

Inicio
para i<-0 ate 300 faca
  se(i%3=0)E(i%7=0)entao
  escreval("Múltiplo de 3 e 7:",i)
  senao
      se(i%3=0)entao
            escreval("Múltiplo de 3:",i)
      senao
            se(i%7=0)entao
            escreval("Múltiplo de 7:",i)
            fimse
      fimse
  fimse
fimpara

Fimalgoritmo