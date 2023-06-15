
// Autor: Murillo Rodrigo Petrucelli Homem
// Para compilar e executar em um Shell Linux
// gcc arco.c -o arco -lm
// ./arco

// Conversão matricial de circunferências

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXIMO 30

int main(void) {

float x, y,     /* coordenadas dos pontos que pertencem ao arco */
      R;        /* raio da circunferência */

int m, n, i, j; /* indices das entradas da matriz que conterá a aproximação */
                /* do arco de circunferência */

char imagem[MAXIMO][MAXIMO];  /* matriz que conterá a representação matricial 
                              /* de um arco de circunferência */
                              
/* Inicializando a matriz imagem */
for(i = 0; i < MAXIMO; i++) {
  for(j = 0; j < MAXIMO; j++) {  /* preenche as entradas de uma linha */
     imagem[i][j] = '-';
     }
  }

R = 29;
x = 0;
y = sqrt(R*R - x*x);
while (x < R) { /* (i,j) são entradas discretas do SRD */
  i = x;
  j = y;  /* conversão implícita de um valor em ponto flutuante para um inteiro */    
  imagem[i][j] = '+';
  x++;
  y = sqrt(R*R - x*x);
  }

/* Exibindo o arco de circunferência */
printf("Exibindo o arco de circunferência na grade matricial do SRD\n");
for(i = 0; i < MAXIMO; i++) {
  for(j = 0; j < MAXIMO; j++) {  /* preenche as entradas de uma linha */
    printf("%c",imagem[i][j]);
    }
  printf("\n");
  }
  
/* Exibindo o arco de circunferência */
printf("\nExibindo o arco de circunferência no sistema de coordenadas do monitor\n");
for(i = 0; i < MAXIMO; i++) {
  for(j = 0; j < MAXIMO; j++) {
    m = j;
    n = MAXIMO - i - 1;
    printf("%c",imagem[m][n]);
    }
  printf("\n");
  }

printf("\n");

return 0;
}




