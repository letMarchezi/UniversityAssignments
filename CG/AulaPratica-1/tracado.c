
// Autor: Murillo Rodrigo Petrucelli Homem
// Para compilar e executar em um Sheel Linux
// gcc tracado.c -o tracado
// ./tracado

#include <stdio.h>
#include <stdlib.h>

#define MAXIMO 30

int main(void) {

float x1, y1, /* coordenadas reais do primeiro ponto do segmento de reta */
      x2, y2, /* coordenadas reais do último ponto do segmento de reta */
      a, b,     /* parâmetros da equação da reta */
      x, y;     /* coordenadas dos pontos que pertencem a reta */

int m, n, i, j; /* indices dos pontos da matriz que conterá a aproximação */
          /* do segmento de reta */

char imagem[MAXIMO][MAXIMO];  /* matriz que conterá a representação matricial 
                              /* de um segmento */
                              /* de reta (vetor) de um espaço contínuo */

/* Valores de entrada */
/* Esses valores deveriam ser testados para verificar se não estão além dos */
/* intervalos permitidos */

x1 = 3.0;
y1 = 6.0;
x2 = 16.0;
y2 = 24.0;

/* Determinação dos valores de "a" e "b" */
/* y1 = a*x1 + b e y2 = a*x2 + b */
/* Sistema linear de duas equações com duas incógnitas */

if (x1 == x2) exit(1);  
else {
  a = (y2 - y1)/(x2 - x1); /* Como chegamos a isto? */
  b = y1 - a*x1;
  }

/* Fazendo o mapeamendo do segmento de reta na matriz imagem */

/* Inicializando a matriz imagem */
for(i = 0; i < MAXIMO; i++) {
  for(j = 0; j < MAXIMO; j++) {  /* preenche as entradas de uma linha */
     imagem[i][j] = '-';
     }
  }

/* Determinando onde ficará (x1,y1) - representadas em um espaço contínuo - na matriz */
/* Critério adotado: aproximação por um valor inteiro */
i = x1; /* conversão implícita de um valor em ponto flutuante para um inteiro */
j = y1; /* Por quê? */

/* Primeiro ponto do segmento de reta discretizado */
imagem[i][j] = '*';

/* Determinando onde ficará (x2,y2) representadas em um espaço contínuo na matriz */
/* Critério adotado: aproximação por um valor inteiro */
i = x2;
j = y2; /* Por quê? */

/* Último ponto do segmento de reta discretizado */
imagem[i][j] = '*';

/* Traçando a reta */
x = ++x1;
y = a*x + b;

while (y < y2) { /* (i,j) são entradas discretas do SRD */
  i = x;
  j = y;  /* conversão implícita de um valor em ponto flutuante para um inteiro */    
  imagem[i][j] = '+';
  y = a*(++x) + b;
  }

/* Exibindo o segmento de reta */
printf("Exibindo o segmento de reta na grade matricial do SRD\n");
for(i = 0; i < MAXIMO; i++) {
  for(j = 0; j < MAXIMO; j++) {  /* preenche as entradas de uma linha */
    printf("%c",imagem[i][j]);
    }
  printf("\n");
  }
  
/* Exibindo o segmento de reta */
printf("\nExibindo o segmento de reta no sistema de coordenadas do monitor\n");
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




