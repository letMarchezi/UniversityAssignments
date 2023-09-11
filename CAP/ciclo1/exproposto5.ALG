Algoritmo "MediaPonderada"
// Disciplina   : [Construção de Algoritmos e Programação]
// Professor   : Ednaldo
// Descrição   : Calcula a média ponderada de 3 notas
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 04/09/2020
Var
// declara as variaveis das 3 notas a serem lidas
notaum, notadois, notatres: real

Inicio
// inicio da entrada de dados
escreva("Digite a primeira nota do aluno: ")
leia(notaum)
escreva("Digite a segunda nota do aluno: ")
leia(notadois)
escreva("Digite a terceira nota do aluno: ")
leia(notatres)
// fim da entrada de dados

// saida de dados. a média ponderada é calculada pela soma da multiplicação
// de cada valor por seu peso, dividida pela soma dos pesos, nesse caso, 6.
escreva("A media ponderada do aluno eh: ", (notaum+(notadois*2)+(notatres*3))/6)
Fimalgoritmo