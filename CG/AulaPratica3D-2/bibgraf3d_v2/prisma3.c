
//	1) identifique a posição dos observadores para este exemplo, considerando
//	um sistema orientado positivamente.

//	2) identifique os três tipos de projeções paralelas nas
//	respectivas view-ports.

//	3) As proporções dos objetos são alteradas com o deslocamento
//	do observador na direção de projeção (alvo)?

#include "cg3d.h"

int main(void) {
 face * f1, * f2, * f3, * f4, * f5;
 object3d * ob3d_1, * ob3d_2,    // objeto 3D no SRU
          * cob3d_1, 
          * cob3d_2, 
          * cob3d_3, 
          * cob3d_4; // representação nos SRs Observadores
 object2d * ob2d;      // buffer que contém a projeção planar para o SRD
 so_win x_par;
 
 matrix3d * m;
 point3d * normal, * viewup, * deslocamento;
 
 palette * palheta;
 bufferdevice * dispositivo;
 window * janela1, * janela2, * janela3, * janela4;
 viewport * porta1, * porta2, * porta3, * porta4;
 
 dispositivo = CreateBuffer(800,600);
 x_par = InitGraf(dispositivo);
 
 palheta = CreatePalette(6);
 SetColor(0,0,0,palheta);
 SetColor(1,1,1,palheta);
 SetColor(1,1,0,palheta);
 SetColor(1,0,0,palheta);
 SetColor(0,1,0,palheta);
 SetColor(0,0,1,palheta);
 
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
 
 // parâmetros para as projeções
 float zpp = 40.0;
 float zcp = -45.0;
 
 // primeiro observador
 normal = SetVertex3d(0.0, 0.0, 1.0, 1.0, 0);
 viewup = SetVertex3d(0.0, 1.0, 0.0, 1.0, 0);
 deslocamento = SetVertex3d(0.0, 0.0, 0.0, 1.0, 0);
 m = CreateObserver(normal,viewup,deslocamento); // cria o observador
 cob3d_1 = ConvertObjectBase(m,ob3d_1);
 ob3d_2 = PerspProjFaces(cob3d_1,zpp,zcp); // PROJEÇÃO PERSPECTIVA
 ob2d = Obj3dtoObj2d(ob3d_2); 
 janela1 = CreateWindow(-30,-30,30,30);
 porta1 = CreateViewPort(1, 1, 400, 300);
 DrawObject(ob2d,janela1,porta1,dispositivo,3);

 // segundo observador
 normal = SetVertex3d(0.0, 0.0, 1.0, 1.0, 0);
 viewup = SetVertex3d(0.0, 1.0, 0.0, 1.0, 0);
 deslocamento = SetVertex3d(0.0, 0.0, 10.0, 1.0, 0);
 m = CreateObserver(normal,viewup,deslocamento); // cria o observador
 cob3d_1 = ConvertObjectBase(m,ob3d_1);
 ob3d_2 = ParalProjFaces(cob3d_1,zpp); // PROJEÇÃO PARALELA TIPO ...
 ob2d = Obj3dtoObj2d(ob3d_2);  
 janela2 = CreateWindow(-20,-20,20,20);
 porta2 = CreateViewPort(401, 1, 800, 300);
 DrawObject(ob2d,janela2,porta2,dispositivo,3);

 // terceiro observador
 normal = SetVertex3d(1.0, 0.0, 0.0, 1.0, 0);
 viewup = SetVertex3d(0.0, 1.0, 0.0, 1.0, 0);
 deslocamento = SetVertex3d(0.0, 0.0, 100.0, 1.0, 0);
 m = CreateObserver(normal,viewup,deslocamento); // cria o observador
 cob3d_1 = ConvertObjectBase(m,ob3d_1);
 ob3d_2 = ParalProjFaces(cob3d_1,zpp); // PROJEÇÃO PARALELA TIPO ...
 ob2d = Obj3dtoObj2d(ob3d_2); 
 janela3 = CreateWindow(-20,-20,20,20);
 porta3 = CreateViewPort(1, 301, 400, 600);
 DrawObject(ob2d,janela3,porta3,dispositivo,3);

 // quarto observador
 normal = SetVertex3d(0.0, 1.0, 0.0, 1.0, 0);
 viewup = SetVertex3d(0.0, 0.0, 1.0, 1.0, 0);
 deslocamento = SetVertex3d(0.0, 0.0, 10000.0, 1.0, 0);
 m = CreateObserver(normal,viewup,deslocamento); // cria o observador
 cob3d_1 = ConvertObjectBase(m,ob3d_1); 
 ob3d_2 = ParalProjFaces(cob3d_1,zpp); // PROJEÇÃO PARALELA TIPO ...
 ob2d = Obj3dtoObj2d(ob3d_2); 
 janela4 = CreateWindow(-20,-20,20,20);
 porta4 = CreateViewPort(401, 301, 800, 600);
 DrawObject(ob2d,janela4,porta4,dispositivo,3);

 char opcao = 'c';
 while (opcao != 'q') {
   RefreshX(dispositivo,palheta,x_par);
   opcao = getchar();   
   }

 CloseGraf(x_par);
  
 return 0; 
 }


