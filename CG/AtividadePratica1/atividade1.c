/*
  Autores:
  Ivan Duarte Calvo RA:790739
  Leticia Bossatto Marchezi RA:791003

  As soluções desenvolvidas estão marcadas nos comentários como "Resposta:"
  Foi entregue outra versão pelo Ivan antecipadamente, porém uma resposta não foi corrigida.
  Esta é a versão final.
*/

#include "cg2d.h"

int desenha_linha_1(int x1, int y1, int x2, int y2, int cor, bufferdevice * monitor) { 

/*
 Esta função implementa o algoritmo de Bresenham de acordo com as equações
 apresentadas em sala de aula (veja slides no moodle) para um 
 coeficiente angular no intervalo [0,1].
 
 O algoritmo consiste em valiar o erro p = F(x,y), onde
 
 		F(x,y) = dy*x - dx*y + dx*b
 
 Considerando:
 
 Erro inicial: p = F(x+1,y+(1/2))
 
 Se p >= 0, modifica-se p = p + 2*dy - 2*dx e o próximo ponto será (x+1,y+1).
 O incremento 2*dy - 2*dx é determinado avaliando-se a função 2*F(x+1,y+1).
 
 Se p < 0, modifica-se p = p + 2*dy e o próximo ponto será (x+1,y).
 O incremento 2*dy é determinado avaliando-se a função 2*F(x+1,y).   
*/

  int x, y, dx, dy, p;

  dy = y2 - y1;
  dx = x2 - x1;
 
  x = x1;
  y = y1;
  p = 2*dy - dx;
  
  while ( (x <= x2) && (y <= y2) ) {
    if (p >= 0) {
      monitor->buffer[(monitor->MaxY - y) * monitor->MaxX + x] = cor;
      p = p + 2*dy - 2*dx;
      x = x + 1;
      y = y + 1; 
      }
    else {
      monitor->buffer[(monitor->MaxY - y) * monitor->MaxX + x] = cor;
      p = p + 2*dy;
      x = x + 1;
      }
    }
    
  return 0;
  }
  
int desenha_linha_2(int x1, int y1, int x2, int y2, int cor, bufferdevice * monitor) {

/*
 Esta função implementa o algoritmo de Bresenham de acordo com as equações
 apresentadas em sala de aula (veja slides no moodle) para um 
 coeficiente angular no intervalo [-1,0).
 
 O algoritmo consiste em valiar o erro p = F(x,y), onde
 
 		F(x,y) = dy*x - dx*y + dx*b

 --------------------------------------------
 
 Respostas:

 Erro inicial: p = F(x+1,y-(1/2)), onde M = (x+1, y-(1/2))

 A função implícita é F(x+1, y-(1/2)) = dy(x+1) - dx(y-1/2) = dy*x + dy - dx*y + dx/2

 Multiplicando por 2 para eliminar a divisão, obtemos que a diferença incremental é:

 p = 2*dy + dx
 
 --------------------------------------------

 Se p <= 0, modifica-se p = p + 2*dy + 2*dx e o próximo ponto será (x+1,y-1).
 O incremento é determinado avaliando-se a função 2*F(x+1,y-1).
 
 A função implícita é F(x+1, y-1) = dy(x+1) - dx(y-1) = dy*x + dy - dx*y + dx

 Multiplicando por 2, obtemos que a diferença incremental é:

 p = 2*dy + 2*dx

 --------------------------------------------
 
 Se p > 0, modifica-se p = p + 2*dy e o próximo ponto será (x+1,y).
 O incremento é determinado avaliando-se a função 2*F(x+1,y).

 A função implícita é F(x+1, y) = dy(x+1) - dx(y) = dy*x + dy - dx*y

 Multiplicando por 2, obtemos que a diferença incremental é:

 p = 2*dy
*/

  int x, y, dx, dy, p;

  dy = y2 - y1;
  dx = x2 - x1;
 
  x = x1;
  y = y1;
  p = 2*dy + dx;

  while ( (x <= x2) && (y >= y2) ) {
    if (p <= 0) {
      monitor->buffer[(monitor->MaxY - y) * monitor->MaxX + x] = cor;
      p = p + 2*dy + 2*dx;
      x = x + 1;
      y = y - 1; 
      }
    else {
      monitor->buffer[(monitor->MaxY - y) * monitor->MaxX + x] = cor;
      p = p + 2*dy;
      x = x + 1;
    }
  }
    
    
  return 0;
}

int main(int argc, char ** argv) {

  int x1, y1, x2, y2, cor;
  palette * palheta;
  bufferdevice * monitor;
  
  palheta = CreatePalette(2);
  SetColor(0,0,0,palheta);
  SetColor(1,1,1,palheta);
  
  monitor = CreateBuffer(600,600);

  // Teste primeiro com esses valores para a desenha_linha_1()
  //x1 = 20; y1 = 20;
  //x2 = 580; y2 = 570;

  // Depois, teste com esses valores para a desenha_linha_2()   
  x1 = 20; y1 = 570;
  x2 = 580; y2 = 20;
  
  float a = (float) (y2-y1)/(x2-x1);
  cor = 1;
  
  printf("Coeficiente angular da reta: %f\n",a); 

  if ( (a >= 0) && (a <= 1) ) {
     printf("O coeficiente angular está no intervalo [0,1].\n");
     printf("Desenhando a linha.\n");
     desenha_linha_1(x1,y1,x2,y2,cor,monitor);
     Dump2X(monitor,palheta);
     }
  else { 
    if ( (a < 0) && (a >= -1) ) {
      printf("O coeficiente angular está no intervalo [-1,0).\n");
      printf("Desenhando a linha.\n");
      desenha_linha_2(x1,y1,x2,y2,cor,monitor);
      Dump2X(monitor,palheta);
      }
    else printf("O coeficiente angular não está nos intervalos [-1,0) ou [0,1].\n");
    }

  /*
    Resposta:

    Utilizando apenas as duas funções não é possível desenhar um triângulo equilátero, apesar da função desenha_linha_1() 
    ser capaz de gerar uma semirreta com coeficiente linear igual a 0 e incrementando somente o valor de x, 
    formando a base do triângulo, as funções desenha_linha_1() e desenha_linha_2() apenas geram semirretas formando ângulo de no 
    máximo 45 graus em relação ao eixo x, e um triângulo equilátero obrigatoriamente possui 3 ângulos de 60 graus entre seus lados.
    Isso se deve ao fato de a função desenha_linha_1() aceitar coeficientes lineares entre [0,1] e a função desenha_linha_2()
    aceitar entre [-1,0).
    */
    
  return 0;
}