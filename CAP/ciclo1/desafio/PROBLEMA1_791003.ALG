Algoritmo "Problema1"
// Disciplina   : [Construção de Algoritmos e Programação]
// Professor   : Ednaldo
// Descrição   : Calcula a altura do morro a partir do deslocamento e variação do ângulo de observação
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 04/09/2020
// RA          : 791003
Var
// declara as variáveis para armazenar o valor do ângulo inicial e depois da caminhada
// e a distância percorrida em metros
anguloum, angulodois, distancia, altura: real


Inicio
// Inicio da entrada de dados

escreva("Insira o valor do ângulo inicial: ")
leia(anguloum)
escreva("Insira o valor da distância percorrida(em metros): ")
leia(distancia)
escreva("Insira o valor do ângulo após o deslocamento: ")
leia(angulodois)
// Fim da entrada de dados

// Conversão de graus para radianos
anguloum<-GraupRad(anguloum)
angulodois<-GraupRad(angulodois)


// Calculo da altura
altura<-(distancia*Tan(anguloum)*Tan(angulodois))/(Tan(angulodois)-Tan(anguloum))
// Imprime o resultado
escreva("Altura do morro: ", altura)
Fimalgoritmo