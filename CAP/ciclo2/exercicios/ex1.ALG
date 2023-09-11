Algoritmo "Ciclo 2 - Ex 3_1"
// Disciplina  : [Construção de Algoritmos e Programação]
// Professor   : Dr. Ednaldo Pizzolato
// Descrição   : Digitar o dia, o mês e o ano.
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 12/09/2020
// RA          : 791003

Var
// Declaração das variáveis
dia, mes, ano, b, c, f, i, j, a, d, ea, g, h: real

Inicio

//Leitura de dados
escreva("Digite o dia: ")
leia(dia)
escreva("Digite o mes: ")
leia(mes)
escreva("Digite o ano: ")
leia(ano)

a<- Int((12-mes)/10)  //calcula o valor de a e converte para inteiro
b <- ano-a
c <- mes+(12*a)
d <- Int(b / 100)
ea <- (d / 4)
f <- 2 - d + ea
g <- Int(365.25 * b)
h <- Int(30.6001 * (c + 1))
i <- f + g + h + dia + 5
j <- i % 7

// imprime o resultado da conta
escolha j

caso 0
   escreva("Sábado")

caso 1
   escreva("Domingo")

caso 2
   escreva("Segunda")

caso 3
   escreva("Terça")

caso 4
   escreva("Quarta")

caso 5
   escreva("Quinta")

caso 6
   escreva("Sexta")

fimescolha


Fimalgoritmo