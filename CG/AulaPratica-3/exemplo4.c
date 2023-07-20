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
  polygon * poligono1, * poligono2;
  object2d * obj1, * obj2;
  float cx, cy;
  
  monitor = CreateBuffer(800,600); // Cria um monitor virtual com 800x600 entradas
  
  palheta = CreatePalette(5);  // Cria um colormap (lookup table) com 5 cores
  SetColor(0,0,0,palheta);
  SetColor(1,0,0,palheta);
  SetColor(0,1,0,palheta);
  SetColor(0,0,1,palheta);
  SetColor(1,1,1,palheta);
  
  // cria polígono
  poligono1 = CreatePolig(5); // polígono fechado com 5 vértices
  poligono2 = CreatePolig(4); // polígono fechado com 4 vértices
  
  // Insere as coordenadas dos pontos representados no SRU 2D relativas aos vértices do polígono
  // O terceiro parâmetro corresponde a componente homogênea
  // O quarto parâmetro é o indice associado a lookup table (cor)
  SetPolig(SetVertex(-9.0,-8.0,1,1), poligono1);
  SetPolig(SetVertex(-7.0,-3.0,1,1), poligono1);
  SetPolig(SetVertex(-4.0,-4.0,1,1), poligono1);
  SetPolig(SetVertex(-3.0,-6.0,1,1), poligono1);
  SetPolig(SetVertex(-6.0,-9.0,1,1), poligono1);
  
  SetPolig(SetVertex(-6.0,-2.0,1,3), poligono2);
  SetPolig(SetVertex(-1.0,-2.0,1,3), poligono2);
  SetPolig(SetVertex(-1.0,-6.0,1,3), poligono2);
  SetPolig(SetVertex(-6.0,-6.0,1,3), poligono2);
  
  // cria objeto
  obj1 = CreateObject2d(1);
  SetObject2d(poligono1,obj1);
  obj2 = CreateObject2d(1); 
  SetObject2d(poligono2,obj2);
  
  janela = CreateWindow(-10.0,-10.0,10.0,10.0); // cria uma janela de visualização (coordenadas no SRU)

  porta = CreateViewPort(1, 1, 800, 600); // Cria uma viewport...
  // ...no caso uma única saída para o dispositivo de visualização com 800x600 entradas
  
  // Conversa com o SO para criar o monitor virtual
  InitGraf(monitor);
  // Mapeia o SRD no monitor virtual (ainda sem preenchimento)
  RefreshX(monitor,palheta);
  
  // Desenha os polígonos e o objeto no SRD
  DrawObject(obj1,janela,porta,monitor,1);
  DrawObject(obj2,janela,porta,monitor,1);

  // Exibe o SRD no monitor
  char opcao = 'c';
  while (opcao != 'q') {
    opcao = getchar();
    switch (opcao) {
      case '1':
        cx = Centro_x(Centroide(obj1));
        cy = Centro_y(Centroide(obj1));
        //printf("Objeto 1: cx = %f\tcy = %f\n",cx,cy);        
        obj1 = TransObj(obj1,SetSftMatrix(-cx,-cy));
        obj1 = TransObj(obj1,SetRotMatrix(5));
        obj1 = TransObj(obj1,SetSftMatrix(cx,cy));    
      break;
      case '2':
        cx = Centro_x(Centroide(obj2));
        cy = Centro_y(Centroide(obj2));
        //printf("Objeto 2: cx = %f\tcy = %f\n",cx,cy);        
        obj2 = TransObj(obj2,SetSftMatrix(-cx,-cy));
        obj2 = TransObj(obj2,SetRotMatrix(5));
        obj2 = TransObj(obj2,SetSftMatrix(cx,cy));   
      break;     
      case 'a':
        cx = Centro_x(Centroide(obj1));
        cy = Centro_y(Centroide(obj1));
        //printf("Objeto 1: cx = %f\tcy = %f\n",cx,cy);        
        obj1 = TransObj(obj1,SetSftMatrix(-cx,-cy));
        obj1 = TransObj(obj1,SetSclMatrix(1.1,1.1));
        obj1 = TransObj(obj1,SetSftMatrix(cx,cy));   
      break;
      case 'd':
        cx = Centro_x(Centroide(obj1));
        cy = Centro_y(Centroide(obj1));
        //printf("Objeto 1: cx = %f\tcy = %f\n",cx,cy);        
        obj1 = TransObj(obj1,SetSftMatrix(-cx,-cy));
        obj1 = TransObj(obj1,SetSclMatrix(0.9,0.9));
        obj1 = TransObj(obj1,SetSftMatrix(cx,cy));   
      break;
      case 'x': 
        obj1 = TransObj(obj1,SetSftMatrix(0.1,0.0));
      break;
      case 'y':
        obj1 = TransObj(obj1,SetSftMatrix(0.0,0.1));
      break;
      }
   ClearDevice(porta,monitor); // Limpa o SRD na view-port específica
   DrawObject(obj1,janela,porta,monitor,1);
   DrawObject(obj2,janela,porta,monitor,3);   
   RefreshX(monitor,palheta); // Mapeia o SRD no monitor virtual   
   } 

  return 0;
  }

 
