Algoritmo "Ciclo 3 - Exercicio 1"
// Disciplina  : [Construção de Algoritmos e Programação]
// Professor   : Dr. Ednaldo Pizzolato
// Descrição   : Informar o número para listar seus divisores.
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 12/09/2020
// RA          : 791003

Var
// Seção de Declarações das variáveis 
 i, numero: inteiro
 

Inicio

escreva("Digite o número inteiro para listar seus divisores: ")
leia(numero)
 
escreval("Divisores de ",numero,":")
 para i<-1 até numero faça
 
      se(numero%i=0)entao
            escreva(i," ")
      fimse
 fimpara

Fimalgoritmo