Algoritmo "Ciclo 2 - Ex 3_2"
// Disciplina  : [Constru��o de Algoritmos e Programa��o]
// Professor   : Dr. Ednaldo Pizzolato
// Descri��o   : Digitar o sexo e a altura.
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 12/09/2020
// RA          : 791003

Var
// Declara��o das vari�veis
peso, h: real;
sexo: inteiro;

Inicio

//Leitura de dados
escreva("Digite o sexo: ")
leia(sexo)


escreva("Digite a altura em metros: ")
leia(h)

se(sexo=1)entao   // caso o indiv�duo seja mulher, ou seja, sexo=1
 peso<- (h*72.7)-58
senao
   se(sexo=0)entao     // caso o indiv�duo seja homem, ou seja, sexo=0
peso<- (62.1*h)-44.7
fimse
  fimse
escreva("Peso ideal: ", peso, "kg")  //imprime o peso ideal
Fimalgoritmo