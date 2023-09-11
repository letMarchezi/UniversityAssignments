Algoritmo "Ciclo 2 - Desafio 1 - Res.1"
// Disciplina  : [Construção de Algoritmos e Programação]
// Professor   : Dr. Ednaldo Pizzolato
// Descrição   : Informar a média final do aluno.
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 12/09/2020
// RA          : 791003

Var
// Declaração das variáveis
mf: real


Inicio
// Entrada de dados
escreval("Digite a média final do aluno: ")
leia(mf)

// teste dos intervalos
se (mf>=9)então
escreval("Conceito A")
fimse
se (mf>=7)E(mf<9)então
 escreval("Conceito B")
fimse
se (mf>=6)E(mf<7)então
     escreval("Conceito C")
fimse
se (mf<6)então
   escreval("Conceito D")
fimse


Fimalgoritmo