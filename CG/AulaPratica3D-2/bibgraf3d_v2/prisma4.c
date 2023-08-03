
#include "cg3d.h"

int main(void) {
 object2d * ob2d; 
 object3d * ob3d_1, * ob3d_2, * cob3d;
 point3d * normal, * viewup, * deslocamento;
 
 palette * palheta;
 bufferdevice * dispositivo;
 window * janela;
 viewport * porta;
 so_win x_par;
 
 dispositivo = CreateBuffer(800,600);
 x_par = InitGraf(dispositivo);
 
 palheta = CreatePalette(5);
 SetColor(0,0,0,palheta);
 SetColor(1,0,0,palheta);
 SetColor(0,1,0,palheta);
 SetColor(0,0,1,palheta);
 SetColor(1,1,1,palheta);
 
 ob3d_1 = ObjectFromData("./data/prisma/faces.txt","./data/prisma/vertices.txt",1);
 
 normal = SetVertex3d(0.0, 0.0, 5.0, 1.0, 0);
 viewup = SetVertex3d(0.0, 7.0, 0.0, 1.0, 0);
 deslocamento = SetVertex3d(0.0, 0.0, 0.0, 1.0, 0);
 cob3d = ConvertObjectBase(CreateObserver(normal,viewup,deslocamento),ob3d_1);
 
 float zvp = 40.0;
 float zcp = -45.0;
 ob3d_2 = PerspProjFaces(cob3d,zvp,zcp);
 ob2d = Obj3dtoObj2d(ob3d_2);
 
 janela = CreateWindow(-40,-40,40,40);
 porta = CreateViewPort(1, 1, 800, 600); 
 DrawObject(ob2d,janela,porta,dispositivo,1);
 
 char opcao = 'c';
 while (opcao != 'q') {
   switch (opcao) {
      case 'x':
        ob3d_1 = TransObject(Rot_X_Matr(10),ob3d_1);
        ClearDevice(porta,dispositivo);  
        cob3d = ConvertObjectBase(CreateObserver(normal,viewup,deslocamento),ob3d_1);   
        ob3d_2 = PerspProjFaces(cob3d,zvp,zcp);
        ob2d = Obj3dtoObj2d(ob3d_2);
        DrawObject(ob2d,janela,porta,dispositivo,1);
      break;
      case 'y':
        ob3d_1 = TransObject(Rot_Y_Matr(10),ob3d_1); 
        ClearDevice(porta,dispositivo);  
        cob3d = ConvertObjectBase(CreateObserver(normal,viewup,deslocamento),ob3d_1);   
        ob3d_2 = PerspProjFaces(cob3d,zvp,zcp);
        ob2d = Obj3dtoObj2d(ob3d_2);
        DrawObject(ob2d,janela,porta,dispositivo,1);    
      break;
      case 'z':
        ob3d_1 = TransObject(Rot_Z_Matr(10),ob3d_1);
        ClearDevice(porta,dispositivo);  
        cob3d = ConvertObjectBase(CreateObserver(normal,viewup,deslocamento),ob3d_1);   
        ob3d_2 = PerspProjFaces(cob3d,zvp,zcp);
        ob2d = Obj3dtoObj2d(ob3d_2);
        DrawObject(ob2d,janela,porta,dispositivo,1);        
      break;
      case 'a':
        ob3d_1 = TransObject(Scale_Matr(1.1,1.1,1.1),ob3d_1);   
        ClearDevice(porta,dispositivo);  
        cob3d = ConvertObjectBase(CreateObserver(normal,viewup,deslocamento),ob3d_1);   
        ob3d_2 = PerspProjFaces(cob3d,zvp,zcp);
        ob2d = Obj3dtoObj2d(ob3d_2);
        DrawObject(ob2d,janela,porta,dispositivo,1);     
      break;
      case 'e':
        ob3d_1 = TransObject(Scale_Matr(0.9,0.9,0.9),ob3d_1); 
        ClearDevice(porta,dispositivo);  
        cob3d = ConvertObjectBase(CreateObserver(normal,viewup,deslocamento),ob3d_1);   
        ob3d_2 = PerspProjFaces(cob3d,zvp,zcp);
        ob2d = Obj3dtoObj2d(ob3d_2);
        DrawObject(ob2d,janela,porta,dispositivo,1);      
      break;
      }
   RefreshX(dispositivo,palheta,x_par);
   opcao = getchar();           
   }
   
 CloseGraf(x_par);   

 return 0; 
 }


