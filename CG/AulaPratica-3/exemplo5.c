/* 
   Autor: Murillo Rodrigo Petrucelli Homem
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
  float cx, cy;
  
  monitor = CreateBuffer(600,600); // Cria um monitor virtual com 600x600 entradas
  
  palheta = CreatePalette(5);  // Cria um colormap (lookup table) com 5 cores
  SetColor(0,0,0,palheta);
  SetColor(1,0,0,palheta);
  SetColor(0,1,0,palheta);
  SetColor(0,0,1,palheta);
  SetColor(1,1,1,palheta);
  
  obj1 = poligono_regular(0.5,30);
  obj1 = TransObj(obj1,SetSftMatrix(-5.0,0.0));
  
  janela = CreateWindow(-10.0,-10.0,10.0,10.0); // cria uma janela de visualização (coordenadas no SRU)

  porta = CreateViewPort(1, 1, 600, 600); // Cria uma viewport...
  // ...no caso uma única saída para o dispositivo de visualização com 800x600 entradas
  
  // Conversa com o SO para criar o monitor virtual
  InitGraf(monitor);
  // Mapeia o SRD no monitor virtual (ainda sem preenchimento)
  RefreshX(monitor,palheta);
  
  // Desenha os polígonos e o objeto no SRD
  DrawObject(obj1,janela,porta,monitor,1);

  // Exibe o SRD no monitor
  char opcao = 'c';
  while (opcao != 'q') {
    opcao = getchar();
    switch (opcao) {
      case '1':
        cx = Centro_x(Centroide(obj1));
        cy = Centro_y(Centroide(obj1));      
        obj1 = TransObj(obj1,SetSftMatrix(-cx,-cy));
        obj1 = TransObj(obj1,SetRotMatrix(-3));
        obj1 = TransObj(obj1,SetSftMatrix(cx+0.1,cy));
      break;
      }
   ClearDevice(porta,monitor); // Limpa o SRD na view-port específica
   DrawObject(obj1,janela,porta,monitor,1);
   RefreshX(monitor,palheta); // Mapeia o SRD no monitor virtual   
   } 

  return 0;
  }

 
