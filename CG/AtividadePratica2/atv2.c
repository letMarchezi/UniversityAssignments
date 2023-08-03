/*
  Autores:
  Ivan Duarte Calvo RA:790739
  Leticia Bossatto Marchezi RA:791003
*/


#include "cg2d.h"

int main(int argc, char ** argv) {
  
    palette * palheta;
    bufferdevice * monitor;
    window * janela, *janela1;
    viewport * porta1, * porta2, * porta3, *porta4;
    polygon * poligono1, * poligono2;
    object2d * obj3_i, *obj3_r, *obj3_s, *obj3;
    so_win x_par;  

    monitor = CreateBuffer(800,600); // Cria um monitor virtual com 800x600 entradas
    x_par = InitGraf(monitor);  // Conversa com o SO para criar o monitor virtual

    palheta = CreatePalette(5);  // Cria um colormap (lookup table) com 5 cores
    SetColor(0,0,0,palheta); //preto
    SetColor(1,0,0,palheta); //vermelho
    SetColor(0,1,0,palheta); //verde
    SetColor(0,0,1,palheta); //azul
    SetColor(1,1,1,palheta); //branco

    // cria polígono
    poligono1 = CreatePolig(8); // polígono fechado com 8 vértices
    poligono2 = CreatePolig(4); // polígono fechado com 4 vértices

    // Insere as coordenadas dos pontos representados no SRU 2D relativas aos vértices do polígono
    // O terceiro parâmetro corresponde a componente homogênea
    // O quarto parâmetro é o indice associado a lookup table (cor)
    SetPolig(SetVertex(-2.0,6.0,1,1), poligono1);
    SetPolig(SetVertex(2.0,6.0,1,1), poligono1);
    SetPolig(SetVertex(8.0,-8.0,1,1), poligono1);
    SetPolig(SetVertex(4.0,-8.0,1,1), poligono1);
    SetPolig(SetVertex(2.0,-4.0,1,1), poligono1);
    SetPolig(SetVertex(-2.0,-4.0,1,1), poligono1);
    SetPolig(SetVertex(-4.0,-8.0,1,1), poligono1);
    SetPolig(SetVertex(-8.0,-8.0,1,1), poligono1);
    
    SetPolig(SetVertex(1.7,-2.0,1,1), poligono2);
    SetPolig(SetVertex(-1.7,-2.0,1,1), poligono2);
    SetPolig(SetVertex(-0.3,2.0,1,1), poligono2);
    SetPolig(SetVertex(0.3,2.0,1,1), poligono2);

    //criando um único objeto com os dois poligonos
    obj3 = CreateObject2d(2);
    SetObject2d(poligono1, obj3);
    SetObject2d(poligono2, obj3);
    
    janela = CreateWindow(-10.0,-10.0,10.0,10.0); // cria uma janela de visualização (coordenadas no SRU)
    janela1 = CreateWindow(-5.0,-5.0,5.0,5.0); // cria uma janela de visualização (coordenadas no SRU)

    porta1 = CreateViewPort(1, 1, 400, 300);
    porta2 = CreateViewPort(401, 1, 800, 301);
    porta3 = CreateViewPort(1, 301, 401, 600);
    porta4 = CreateViewPort(401, 301, 800, 600);
    
    //objeto em italico
    obj3_i = CreateObject2d(2);
    SetObject2d(poligono1,obj3_i);
    SetObject2d(poligono2,obj3_i);

    //realizando a conversão do objeto para itálico, utilizando o valor 0.2
    obj3_i = TransObj(obj3, SetCisMatrix(0.2, 0));

    //objeto rotacionado
    //somente a operação de rotação já foi suficiente para a correta visualização do objeto dentro da viewport  
    obj3_r = CreateObject2d(2);
    SetObject2d(poligono1,obj3_r);
    SetObject2d(poligono2,obj3_r);

    //foi realizada a rotação do objeto em 90º no sentido horario
    obj3_r = TransObj(obj3, SetRotMatrix(-90));
    
    //objeto redimensionado
    /*para a visualização do objeto ser exatamente a mesma do primeiro, foi criada uma 
    nova janela com metade das dimensões da janela original*/
    obj3_s = CreateObject2d(2);
    SetObject2d(poligono1,obj3_s);
    SetObject2d(poligono2,obj3_s);

    //foi feito o redimensionamento do objeto para metade do tamanho do original
    obj3_s = TransObj(obj3, SetSclMatrix(0.5, 0.5));

    while(1) {
        // Desenha os polígonos e o objeto no SRD
        DrawObject(obj3, janela, porta1, monitor, 1);

        DrawObject(obj3_i,janela,porta2,monitor,2);

        DrawObject(obj3_r,janela,porta3,monitor,3);
        
        DrawObject(obj3_s,janela1,porta4,monitor,4);
        
        RefreshX(monitor,palheta,x_par); // Mapeia o SRD no monitor virtual exibindo o objeto na tela
    }
    return 0;

}