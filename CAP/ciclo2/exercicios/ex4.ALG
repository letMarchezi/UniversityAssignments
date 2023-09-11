Algoritmo "Ciclo 2 - Ex 4"
// Disciplina  : [Construção de Algoritmos e Programação]
// Professor   : Dr. Ednaldo Pizzolato
// Descrição   : Digitar 3 números inteiros diferentes.
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 12/09/2020
// RA          : 791003

Var
// Declaração das variáveis
numa, numb, numc: inteiro;

Inicio

//Leitura de dados
escreva("Digite o 1º número: ")
leia(numa)

escreva("Digite o 2º número diferente do 1º: ")
leia(numb)

escreva("Digite o 3º número diferente dos 2 anteriores: ")
leia(numc)
//testa se todos os números são diferentes
se(numa<>numb)e(numb<>numc)e(numa<>numc)entao
   se(numa>numb)e(numa>numc) então // caso o número a seja o maior
        escreva(numa)
        se(numb>numc)entao    //testa se o numero b é o segundo maior
           escreva(numb)
           escreva(numc)
        senao
           escreva(numc)
           escreva(numb)
        fimse
   senao
        se(numb>numa)e(numb>numc)então   //caso o número b seja o maior
             escreva(numb)
             se(numa>numc)entao    //testa se o numero a é o segundo maior
                  escreva(numa)
                  escreva(numc)
             fimse
        senao  // senao, o número c é o maior
             escreva(numc)
             se(numb>numa)entao      //testa se o numero b é o segundo maior
                  escreva(numb)
                  escreva(numa)
             senao
                  escreva(numa)
                  escreva(numb)
             fimse
        fimse
   fimse
senao
escreva("Os 3 números não são todos diferentes.")
   
fimse



Fimalgoritmo