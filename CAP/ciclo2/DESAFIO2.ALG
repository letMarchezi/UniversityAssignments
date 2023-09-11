Algoritmo "Ciclo 2 - Desafio 2"
// Disciplina  : [Construção de Algoritmos e Programação]
// Professor   : Dr. Ednaldo Pizzolato
// Descrição   : Informar as 3 medidas do triângulo.
// Autor(a)    : Leticia Bossatto Marchezi
// Data atual  : 12/09/2020
// RA          : 791003

Var
// Declaração das variáveis
medidaa, medidab, medidac: real


Inicio
// Entrada de dados
escreval("Insira a primeira medida do lado do triângulo:")
leia(medidaa)
escreval("Insira a segunda medida do lado do triângulo:")
leia(medidab)
escreval("Insira a terceira medida do lado do triângulo:")
leia(medidac)
//pulando uma linha
escreval()

// Teste de existência do triângulo
se (medidab+medidac > medidaa)E(medidaa+medidac > medidab)E(medidaa+medidab > medidac)então

  se (medidaa=medidab)E(medidab=medidac)então
  escreval("O triângulo é equilatero.")
  
 senao
  se (medidaa=medidab)E(medidab<>medidac)então
  escreval("O triângulo é isósceles.")
  
  senao
  escreval("O triângulo é escaleno.")
  
  fimse
 fimse
 
senão
escreval("As medidas inseridas não formam um triângulo.")

fimse

Fimalgoritmo