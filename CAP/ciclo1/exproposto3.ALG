Algoritmo "CalcGasolina"
// Disciplina   : [Construção de Algoritmos e Programação]
// Professor   : Ednaldo
// Descrição   : Calcula a quantidade de gasolina comprada com o valor inserido
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 04/09/2020
Var
// declara as variaveis de valor da gasolina e o valor pago
precogas, valorpag: real

Inicio
// inicio da entrada de dados
escreva("Digite o valor da gasolina: ")
leia(precogas)
escreva("Digite o valor a ser pago: ")
leia(valorpag)
// fim da entrada de dados

// saida. a quantidade de gasolina é o quociente entre o valor pago
// e o valor do litro da gasolina
escreva("Você comprou",valorpag/precogas," litros de gasolina")
Fimalgoritmo