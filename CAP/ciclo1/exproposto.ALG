Algoritmo "ValorTerreno"
// Disciplina   : [Construção de Algoritmos e Programação]
// Professor   : Ednaldo
// Descrição   : Calcula o valor a ser pago no terreno
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 04/09/2020
Var
// declara as variáveis das dimensoes e do valor por metro quadrado
dimensaox, dimensaoy, valorquad: real

Inicio
//entrada de dados
escreva("Digite a primeira dimensão do terreno: ")
leia(dimensaox)
escreva("Digite a segunda dimensão do terreno: ")
leia(dimensaoy)
escreva("Digite o valor por metro quadrado anunciado: ")
leia(valorquad)
//fim da entrada de dados

//saida, calculo da area do terreno e do valor final
escreva("Valor a ser pago: R$",dimensaox*dimensaoy*valorquad,",00")
Fimalgoritmo