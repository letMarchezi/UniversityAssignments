
/*
Estudar:

	-> encurtamento perspectivo
	
	-> sentido de rotação em relação ao observador virtual

	-> ângulo entre os vetores das faces com o vetor normal

	-> minimização da confusão visual no modelo de arame (wireframe)

	-> preenchimento das faces
*/

#include "cg3d.h"

int main(void) {
 object2d * ob2d;
 face * f1, * f2, * f3, * f4, * f5;
 object3d * ob3d_1, * ob3d_2, * cob3d;
 point3d * normal, * viewup, * deslocamento;
 matrix3d * m;
 so_win x_par;
 
 palette * palheta;
 bufferdevice * dispositivo;
 window * janela;
 viewport * porta;
 
 dispositivo = CreateBuffer(500,500);
 x_par = InitGraf(dispositivo);
 
 palheta = CreatePalette(7);
 SetColor(0,0,0,palheta);
 SetColor(1,0,0,palheta);
 SetColor(1,1,0,palheta);
 SetColor(0,1,0,palheta);
 SetColor(1,0,1,palheta); 
 SetColor(0,0,1,palheta);
 SetColor(1,1,1,palheta);

 float h = 20.0*pow(3.0,0.5)/2.0;
 
 f1 = CreateFace(3);  
 SetPointFace(SetVertex3d(15.0, 10.0, -h/2, 1.0, 0),f1);
 SetPointFace(SetVertex3d(15.0, 0.0, h/2, 1.0, 0),f1);
 SetPointFace(SetVertex3d(15.0, -10.0, -h/2, 1.0, 0),f1);

 f2 = CreateFace(3);
 SetPointFace(SetVertex3d(-15.0, 0.0, h/2, 1.0, 0),f2);
 SetPointFace(SetVertex3d(-15.0, 10.0, -h/2, 1.0, 0),f2);
 SetPointFace(SetVertex3d(-15.0, -10.0, -h/2, 1.0, 0),f2);

 f3 = CreateFace(4);
 SetPointFace(SetVertex3d(-15.0, -10.0, -h/2, 1.0, 0),f3);
 SetPointFace(SetVertex3d(-15.0, 10.0, -h/2, 1.0, 0),f3);
 SetPointFace(SetVertex3d(15.0, 10.0, -h/2, 1.0, 0),f3);
 SetPointFace(SetVertex3d(15.0, -10.0, -h/2, 1.0, 0),f3);
  
 f4 = CreateFace(4);
 SetPointFace(SetVertex3d(15.0, 10.0, -h/2, 1.0, 0),f4);
 SetPointFace(SetVertex3d(-15.0, 10.0, -h/2, 1.0, 0),f4);
 SetPointFace(SetVertex3d(-15.0, 0.0, h/2, 1.0, 0),f4);
 SetPointFace(SetVertex3d(15.0, 0.0, h/2, 1.0, 0),f4);

 f5 = CreateFace(4);
 SetPointFace(SetVertex3d(15.0, 0.0, h/2, 1.0, 0),f5);
 SetPointFace(SetVertex3d(-15.0, 0.0, h/2, 1.0, 0),f5);
 SetPointFace(SetVertex3d(-15.0, -10.0, -h/2, 1.0, 0),f5);
 SetPointFace(SetVertex3d(15.0, -10.0, -h/2, 1.0, 0),f5);

 ob3d_1 = CreateObject3d(5);
 SetObject3d(f1,ob3d_1);
 SetObject3d(f2,ob3d_1);
 SetObject3d(f3,ob3d_1);
 SetObject3d(f4,ob3d_1);
 SetObject3d(f5,ob3d_1);
 
 normal = SetVertex3d(0.0, 0.0, -1.0, 1.0, 0);
 viewup = SetVertex3d(0.0, 1.0, 0.0, 1.0, 0);
 deslocamento = SetVertex3d(0.0, 0.0, -60.0, 1.0, 0);
 m = CreateObserver(normal,viewup,deslocamento);
 
 float zvp = 10.0;
 float zcp = -45.0;
 
 janela = CreateWindow(-25,-25,25,25);
 porta = CreateViewPort(1,1,500,500);
 
 char opcao = 'c';
 while (opcao != 'q') {
   switch (opcao) {
      case 'd':
        ClearDevice(porta,dispositivo);
        cob3d = ConvertObjectBase(m,ob3d_1);
        cob3d = CleanFaces(cob3d,normal);
        ob3d_2 = PerspProjFaces(cob3d,zvp,zcp);
        ob2d = Obj3dtoObj2d(ob3d_2);
        DrawObject(ob2d,janela,porta,dispositivo,6);      
      break;
      case 'x':
        ob3d_1 = TransObject(Rot_X_Matr(9),ob3d_1);
        ClearDevice(porta,dispositivo);
        cob3d = ConvertObjectBase(m,ob3d_1);
        cob3d = CleanFaces(cob3d,normal);
        ob3d_2 = PerspProjFaces(cob3d,zvp,zcp);
        ob2d = Obj3dtoObj2d(ob3d_2);
        DrawObject(ob2d,janela,porta,dispositivo,6);
        //for(int i=0;i<ob2d->numbers_of_polygons;i++) ScanLineFill(&ob2d->pol[i],janela,porta,dispositivo,i+1);
      break;
      case 'y':
        ob3d_1 = TransObject(Rot_Y_Matr(9),ob3d_1);
        ClearDevice(porta,dispositivo);  
        cob3d = ConvertObjectBase(m,ob3d_1);   
        cob3d = CleanFaces(cob3d,normal);
        ob3d_2 = PerspProjFaces(cob3d,zvp,zcp);
        ob2d = Obj3dtoObj2d(ob3d_2);
        DrawObject(ob2d,janela,porta,dispositivo,6);
	//for(int i=0;i<ob2d->numbers_of_polygons;i++) ScanLineFill(&ob2d->pol[i],janela,porta,dispositivo,i+1);                    
      break;
      case 'z':
        ob3d_1 = TransObject(Rot_Z_Matr(9),ob3d_1);
        ClearDevice(porta,dispositivo);  
        cob3d = ConvertObjectBase(m,ob3d_1);   
        cob3d = CleanFaces(cob3d,normal);
        ob3d_2 = PerspProjFaces(cob3d,zvp,zcp);
        ob2d = Obj3dtoObj2d(ob3d_2);
        DrawObject(ob2d,janela,porta,dispositivo,6);
	//for(int i=0;i<ob2d->numbers_of_polygons;i++) ScanLineFill(&ob2d->pol[i],janela,porta,dispositivo,i+1);        
      break;
      }
   RefreshX(dispositivo,palheta,x_par);
   opcao = getchar();      
   }
   
 CloseGraf(x_par);

 return 0;
 }


