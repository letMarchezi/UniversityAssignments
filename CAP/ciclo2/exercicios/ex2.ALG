Algoritmo "Ciclo 2 - Ex 3_1"
// Disciplina  : [Construção de Algoritmos e Programação]
// Professor   : Dr. Ednaldo Pizzolato
// Descrição   : Digitar a altura e o peso.
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 12/09/2020
// RA          : 791003

Var
// Declaração das variáveis
peso, altura, imc: real;

Inicio

//Leitura de dados
escreva("Digite o peso em kg: ")
leia(peso)
escreva("Digite a altura em m: ")
leia(altura)


imc<-peso/(altura*altura)  //calculo do imc

se (imc<18.5)entao   // teste da classificação do imc
 escreva("Abaixo do peso")
senao
  se(imc<25) entao
   escreva("Peso normal")
  
  senao
     se(imc<30)  entao
      escreva("Acima do peso")
     
     senao
      escreva("Obeso")
     fimse
  fimse
fimse

Fimalgoritmo