/*
   Autor Original: Murillo Rodrigo Petrucelli Homem.
   Alteração do desenho: Leticia Bossatto
   Departamento de Computação
   Universidade Federal de São Carlos
*/

// Para executar em um shell linux digite: make

#include "cg2d.h"

int main(int argc, char ** argv) {
  
  palette * palheta;
  bufferdevice * monitor;
  window * janela;
  viewport * porta;
  polygon * poligono1;
  object2d * obj1;
  
  monitor = CreateBuffer(800,600); // Cria um monitor virtual com 800x600 entradas
  
  palheta = CreatePalette(7);  // Cria um colormap (lookup table) com 7 cores
  SetColor(0,0,0,palheta);
  SetColor(1,0,0,palheta);
  SetColor(0,1,0,palheta);
  SetColor(0,0,1,palheta);
  SetColor(0.4,0.3,1,palheta);
  SetColor(0.8,0.8,0.8,palheta);
  SetColor(1,1,1,palheta);
  
  // cria dois polígonos
  poligono1 = CreatePolig(8); // polígono fechado com 5 vértices
  
  // Insere as coordenadas dos pontos representados no SRU 2D em cada polígono
  // O terceiro parâmetro corresponde a componente homogênea
  // O quarto parâmetro é o indice associado a lookup table (cor)

  SetPolig(SetVertex(0.0,-7.0,1,3), poligono1);// meio baixo
  SetPolig(SetVertex(-5.0, 2.0,1,3), poligono1); // lado dir
  SetPolig(SetVertex(-4.0, 4,1,3), poligono1); // lado dir
  SetPolig(SetVertex(-2.0,4.0,1,3), poligono1); // lado dir
  SetPolig(SetVertex(0.0,2.0,1,3), poligono1); // meio cima
  SetPolig(SetVertex(2.0,4.0,1,3), poligono1); // lado esq
  SetPolig(SetVertex(4.0,4,1,3), poligono1); // lado esq
  SetPolig(SetVertex(5.0,2.0,1,3), poligono1); // lado esq
  

  // cria os objetos
  obj1 = CreateObject2d(1);
  SetObject(poligono1,obj1);
  
  janela = CreateWindow(-10.0,-10.0,10.0,10.0); // cria uma janela de visualização (coordenadas no SRU)

  porta = CreateViewPort(1, 1, 800, 600); // Cria uma viewport...
  // ...no caso uma única saída para o dispositivo de visualização com 800x600 entradas
  
  // Desenha os polígonos e o objeto no SRD
  DrawObject(obj1,janela,porta,monitor,1);

  
  // Exibe o SRD no monitor
  Dump2X(monitor,palheta);
  //Display_SRD(monitor,palheta);  // Uma opção interessante...

  return 0;
  }

 
