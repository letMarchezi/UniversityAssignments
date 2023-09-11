Algoritmo "Ciclo 3 - Desafio 2"
// Disciplina  : [Construção de Algoritmos e Programação]
// Professor   : Dr. Ednaldo Pizzolato
// Descrição   : Digite o ângulo em graus para convertê-lo em radianos
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 20/09/2020
// RA          : 791003

Var
angulo, resultado: real
i, j, fatorial, aux: inteiro
Inicio


escreva("Digite o ângulo em graus para calcular o seno: ")
leia(angulo)

enquanto ((angulo>360)OU(angulo<0)) faça  //ajuste do ângulo para [0,360]
     se(angulo>360)então
          angulo<-angulo-360
     fimse
     se(angulo<0)então
          angulo<-angulo+360
     fimse
     
     escreva(angulo)
fimenquanto

i<-1
angulo<- GraupRad(angulo)


aux<-0;
enquanto (i<=9) faça
   fatorial<-1
   j<-1
   se (i=1)então
       resultado<-angulo
   senao
       enquanto (j<=i) faça  // calcula o fatorial da parcela
       fatorial<-j*fatorial
       j<-j+1
       fimenquanto

       se (aux=0) então // inverte o sinal da parcela
           resultado<-resultado-(angulo^i/fatorial)
           aux<-1
       senão
           resultado<-resultado+(angulo^i/fatorial)
           aux<-0
       fimse
       
   escreval(resultado)

   fimse
   i<-i+2
fimenquanto

escreval("O resultado do algortimo é:",resultado)
escreval("O resultado da função pré-definida é:", sen(angulo))


Fimalgoritmo