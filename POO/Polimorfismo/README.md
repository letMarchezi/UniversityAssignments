# Polymorphism

```diff 
+  Polymorphism example in C++: implementing abstract class and inheritance 
 ```
 
 In this project there is an abstract class named ```Animal``` used to implement ```Pessoa``` (Person), ```Cachorro``` (Dog) and ```Peixe``` (Fish).
One person can have multiple animals that are stored in a vector. Above there are is a description of every class:

## Animal
`Atributes: Nome, Peso `

 `Methods: getEspecie(), imprime() `


## Pessoa
`Atributes: Nome, Idade, <vector> animais `

 `Methods:  adicionaAnimal(), removeAnimal(), obtemAnimal(), qtdeAnimais(), qtdePeixes(),  qtdeCachorros(), imprime()`
 
 ## Cachorro
`Atributes: Raca `

 `Methods:  getRaca(), setRaca()`
 
 ## Peixe
`Atributes:  tipoHabitat`

 `Methods:  getTipoHabitat, setTipoHabitat`
 
 
