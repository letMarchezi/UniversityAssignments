Algoritmo "Problema2"
// Disciplina   : [Construção de Algoritmos e Programação]
// Professor   : Ednaldo
// Descrição   : Calcula a altura do avião após percorrer certa distância
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 04/09/2020
// RA          : 791003
Var
// declara as variáveis para armazenar o valor do ângulo de voo, a distância
// percorridae a altura calculada
angulo, distancia, altura: real

Inicio
// Inicio da entrada de dados
escreva("Insira o valor do ângulo de voo: ")
leia(angulo)
escreva("Insira o valor da distância percorrida(em metros): ")
leia(distancia)
// Fim da entrada de dados

// Conversão de graus para radianos
angulo<-GraupRad(angulo)

// Calculo da altura
altura<-(distancia*Sen(angulo))

// Imprime o resultado
escreva("Altura alcançada pelo avião: ", altura)
Fimalgoritmo