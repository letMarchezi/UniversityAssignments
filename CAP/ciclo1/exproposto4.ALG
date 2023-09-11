Algoritmo "MediaAritmetica"
// Disciplina   : [Construção de Algoritmos e Programação]
// Professor   : Ednaldo
// Descrição   : Calcula a média aritmética de 3 notas
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 04/09/2020
Var
// declara as variaveis das três notas
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

// saida de dados. a media aritmetica é calculada pela soma dos valores
// divida pela quantidade de valores, nesse caso, 3.
escreva("Media aritmetica do aluno:", (notaum+notadois+notatres)/3)
Fimalgoritmo