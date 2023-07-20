/* 
   Autor: Murillo Rodrigo Petrucelli Homem
   Departamento de Computação
   Universidade Federal de São Carlos
*/

// Para executar em um shell linux digite: make && ./exemplo8

#include "cg2d.h"

int main(int argc, char ** argv) {
  
  palette * palheta;
  bufferdevice * monitor;
  window * janela;
  viewport * porta1, * porta2, * porta3, * porta4;
  polygon * poligono1;
  object2d * obj, * obj1, * obj2, * obj3, * obj4;
  so_win x_par;   
  
  monitor = CreateBuffer(600,600); // Cria um monitor virtual com 600x600 entradas
  x_par = InitGraf(monitor);  // Conversa com o SO para criar o monitor virtual   
  
  palheta = CreatePalette(5);  // Cria um colormap (lookup table) com 5 cores
  SetColor(0,0,0,palheta);
  SetColor(1,0,0,palheta);
  SetColor(0,1,0,palheta);
  SetColor(0,0,1,palheta);
  SetColor(1,1,1,palheta);
  
  obj = poligono_regular(1.5,7); // cria um polígono regular centrado na origem
  
  janela = CreateWindow(-10.0,-10.0,10.0,10.0); // cria uma janela de visualização (coordenadas no SRU)

  porta1 = CreateViewPort(1, 1, 300, 300);
  porta2 = CreateViewPort(301, 1, 600, 301);
  porta3 = CreateViewPort(1, 301, 301, 600);
  porta4 = CreateViewPort(301, 301, 600, 600);
  
  float angulo = 3.0;
  float cx, cy; // centro do objeto no SRU
  float deslocamento_x = 0.1, deslocamento_y = 0.1;
  float escala_x = 1.003, escala_y = 1.006;
  
  obj1 = TransObj(obj,SetSftMatrix(-5.0,0.0));
  obj2 = TransObj(obj,SetSftMatrix(0.0,-5.0));
  obj3 = TransObj(obj,SetRotMatrix(angulo));
  obj4 = TransObj(obj,SetRotMatrix(angulo)); 
  while (1) {
    // para objeto 1
    cx = GetXVertex(Centroide(obj1));
    cy = GetYVertex(Centroide(obj1));
    if ((cx < -5.0) || (cx > 5.0))  { 
       deslocamento_x = - deslocamento_x;
       angulo = - angulo;
       }     
    obj1 = TransObj(obj1,SetSftMatrix(-cx,-cy));
    obj1 = TransObj(obj1,SetRotMatrix(-angulo));         
    obj1 = TransObj(obj1,SetSftMatrix(cx,cy));
    obj1 = TransObj(obj1,SetSftMatrix(deslocamento_x,0.0));
    ClearDevice(porta1,monitor); // Limpa o SRD na view-port especificada
    DrawObject(obj1,janela,porta1,monitor,1); // Desenha o objeto no SRD
    
    // para objeto 2
    cx = GetXVertex(Centroide(obj2));
    cy = GetYVertex(Centroide(obj2));  
     if ((cy < -5.0) || (cy > 5.0))  { 
       deslocamento_y = - deslocamento_y;
       angulo = - angulo;
       }      
    obj2 = TransObj(obj2,SetSftMatrix(-cx,-cy));
    obj2 = TransObj(obj2,SetRotMatrix(-angulo));         
    obj2 = TransObj(obj2,SetSftMatrix(cx,cy));
    obj2 = TransObj(obj2,SetSftMatrix(0.0,deslocamento_y));
    ClearDevice(porta2,monitor); // Limpa o SRD na view-port especificada
    DrawObject(obj2,janela,porta2,monitor,1); // Desenha o objeto no SRD
   
    // para objeto 3 
    obj3 = TransObj(obj3,SetRotMatrix(-angulo));         
    obj3 = TransObj(obj3,SetSclMatrix(escala_x,escala_x));
    ClearDevice(porta3,monitor); // Limpa o SRD na view-port especificada
    DrawObject(obj3,janela,porta3,monitor,1); // Desenha o objeto no SRD
   
    // para objeto 4
    obj4 = TransObj(obj4,SetRotMatrix(angulo));         
    obj4 = TransObj(obj4,SetSclMatrix(escala_y,escala_y));
    ClearDevice(porta4,monitor); // Limpa o SRD na view-port especificada
    DrawObject(obj4,janela,porta4,monitor,1); // Desenha o objeto no SRD    
        
    RefreshX(monitor,palheta,x_par); // Mapeia o SRD no monitor virtual exibindo o objeto na tela
    }

  return 0;
  }


