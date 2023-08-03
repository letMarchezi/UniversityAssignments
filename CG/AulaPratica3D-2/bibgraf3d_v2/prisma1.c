
 //	1) estude e entenda as relações entre a posição
 //	do plano de observação e o deslocamento do observador virtual.

 //	2) estude o exemplo para diferentes valores de zvp e zcp.

 //	3) explique o caso zvp = 0.0.

 //	4) analise o exemplo para zcp = -1000.0. Como ficam as proporções
 //	dos objetos nesse caso? Explique.
 
#include "cg3d.h"

int main(void) {
 object2d * ob2d;
 face * f1, * f2, * f3, * f4, * f5;
 object3d * ob3d_1, * ob3d_2, * cob3d;
 point3d * normal, * viewup, * deslocamento;
 so_win x_par;
 
 palette * palheta;
 bufferdevice * dispositivo;
 window * janela;
 viewport * porta;
 
 dispositivo = CreateBuffer(800,600);
 x_par = InitGraf(dispositivo);
 
 palheta = CreatePalette(5);
 SetColor(0,0,0,palheta);
 SetColor(1,0,0,palheta);
 SetColor(0,1,0,palheta);
 SetColor(0,0,1,palheta);
 SetColor(1,1,1,palheta);
 
 f1 = CreateFace(3);
 SetPointFace(SetVertex3d(10.0, 10.0, 0.0, 1.0, 1), f1);
 SetPointFace(SetVertex3d(10.0, 0.0, 15.0, 1.0, 1), f1);
 SetPointFace(SetVertex3d(10.0, -10.0, 0.0, 1.0, 1), f1);

 f2 = CreateFace(3);
 SetPointFace(SetVertex3d(-10.0, 10.0, 0.0, 1.0, 2), f2);
 SetPointFace(SetVertex3d(-10.0, 0.0, 15.0, 1.0, 2), f2);
 SetPointFace(SetVertex3d(-10.0, -10.0, 0.0, 1.0, 2), f2); 
 
 f3 = CreateFace(4);
 SetPointFace(SetVertex3d(10.0, 10.0, 0.0, 1.0, 3), f3);
 SetPointFace(SetVertex3d(10.0, 0.0, 15.0, 1.0, 3), f3);
 SetPointFace(SetVertex3d(-10.0, 0.0, 15.0, 1.0, 3), f3);
 SetPointFace(SetVertex3d(-10.0, 10.0, 0.0, 1.0, 3), f3); 
 
 f4 = CreateFace(4);
 SetPointFace(SetVertex3d(10.0, 0.0, 15.0, 1.0, 4), f4);
 SetPointFace(SetVertex3d(10.0, -10.0, 0.0, 1.0, 4), f4);
 SetPointFace(SetVertex3d(-10.0, -10.0, 0.0, 1.0, 4), f4);
 SetPointFace(SetVertex3d(-10.0, 0.0, 15.0, 1.0, 4), f4);  

 f5 = CreateFace(4);
 SetPointFace(SetVertex3d(10.0, 10.0, 0.0, 1.0, 5), f5);
 SetPointFace(SetVertex3d(10.0, -10.0, 0.0, 1.0, 5), f5);
 SetPointFace(SetVertex3d(-10.0, -10.0, 0.0, 1.0, 5), f5);
 SetPointFace(SetVertex3d(-10.0, 10.0, 0.0, 1.0, 5), f5);   

 ob3d_1 = CreateObject3d(5); // prisma de base triangular no SRU 3D
 SetObject3d(f1,ob3d_1);
 SetObject3d(f2,ob3d_1);
 SetObject3d(f3,ob3d_1);
 SetObject3d(f4,ob3d_1);
 SetObject3d(f5,ob3d_1);
 
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

