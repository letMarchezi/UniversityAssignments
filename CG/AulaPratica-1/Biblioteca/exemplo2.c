// Um exemplo utizando as funções da biblioteca implementada

// Para executar:
// gcc -c bibaux.c
// gcc -c cg2d.c
// gcc exemplo2.c -o exemplo2 cg2d.o bibaux.o -lm -lX11
// ./exemplo2

#include "cg2d.h"

int main(int argc, char ** argv) {
  
  palette * palheta;
  bufferdevice * monitor;
  window * janela;
  viewport * porta1, * porta2;
  object * poligono1, * poligono2;
  
  SetWorld(-20, -20, 10, 15); // Define o tamanho do mundo  
  monitor = CreateBuffer(640,480); // Cria um monitor virtual
  
  palheta = CreatePalette(5);  // Cria um colormap (lookup table) com 5 cores
  SetColor(0,0,0,palheta);
  SetColor(1,0,0,palheta);
  SetColor(0,1,0,palheta);
  SetColor(0,0,1,palheta);
  SetColor(1,1,1,palheta);
  
  // cria dois objetos bidimensionais
  poligono1 = CreateObject(5);  // polígono fechado com 5 vértices
  poligono2 = CreateObject(4);  // polígono fechado com 4 vértices
  
  // Insere as coordenadas dos pontos representados no SRU em cada objeto
  // O terceiro parâmetro será discutido em aula futura
  // O quarto parâmetro é o indice associado a lookup table (cor)
  SetObject(SetPoint(-9.0,-8.0,1,1), poligono1);
  SetObject(SetPoint(-7.0,-3.0,1,1), poligono1);
  SetObject(SetPoint(-4.0,-4.0,1,1), poligono1);
  SetObject(SetPoint(-3.0,-6.0,1,1), poligono1);
  SetObject(SetPoint(-6.0,-9.0,1,1), poligono1);
  
  SetObject(SetPoint(-6.0,-2.0,1,3), poligono2);
  SetObject(SetPoint(-1.0,-2.0,1,3), poligono2);
  SetObject(SetPoint(-1.0,-6.0,1,3), poligono2);
  SetObject(SetPoint(-6.0,-6.0,1,3), poligono2);
  
  janela = CreateWindow(-10.0,-10.0,0.0,0.0); // cria uma janela de visualização (coordenadas no SRU)

  porta1 = CreateViewPort(30, 60, 347, 220); // Cria uma viewport
  porta2 = CreateViewPort(370, 260, 503, 407); // Cria uma segunda viewport

  DrawObject(poligono1,janela,porta1,monitor,3);
  DrawObject(poligono2,janela,porta2,monitor,2);
 
  Dump2X(monitor,palheta);
 
  return 0;
  }


