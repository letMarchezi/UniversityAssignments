Algoritmo "Ciclo 2 - Desafio 1 - Res.1"
// Disciplina  : [Constru��o de Algoritmos e Programa��o]
// Professor   : Dr. Ednaldo Pizzolato
// Descri��o   : Informar a m�dia final do aluno.
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 12/09/2020
// RA          : 791003

Var
// Declara��o das vari�veis
mf: real


Inicio
// Entrada de dados
escreval("Digite a m�dia final do aluno: ")
leia(mf)

// teste dos intervalos
se (mf>=9)ent�o
escreval("Conceito A")
fimse
se (mf>=7)E(mf<9)ent�o
 escreval("Conceito B")
fimse
se (mf>=6)E(mf<7)ent�o
     escreval("Conceito C")
fimse
se (mf<6)ent�o
   escreval("Conceito D")
fimse


Fimalgoritmo