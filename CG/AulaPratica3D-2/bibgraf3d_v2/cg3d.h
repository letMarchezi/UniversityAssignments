/* 
   Autor: Murillo Rodrigo Petrucelli Homem
   Departamento de Computação
   Universidade Federal de São Carlos

   Código ilustrativo de uma biblioteca gráfica tridimensional
*/

#include "cg2d.h"

#define MAX_FACES 10000
#define MAX_VERTICES 30000

typedef struct HPoint3D {
  float x, y, z;
  float w;     
  int   color;
  } point3d;
      
typedef struct Face {
  int numbers_of_points;
  point3d * points;
  } face;
  
typedef struct Object3D {
  int numbers_of_faces;
  face * faces;
  } object3d;

typedef struct Matrix3D {
  float a11, a12, a13, a14,
        a21, a22, a23, a24,
        a31, a32, a33, a34,
        a41, a42, a43, a44;
        } matrix3d;

point3d * VectorProduct3d(point3d *, point3d *);
float InnerProduct3d(point3d *, point3d *);
float Modulo3d(point3d *);
point3d * Versor3d(point3d *);
face * CreateFace(int);
point3d * SetVertex3d(float, float, float, float, int);
int SetPointFace(point3d *, face *);
object3d * CreateObject3d(int);
int SetObject3d(face *, object3d *);
matrix3d * CreateObserver(point3d *, point3d *, point3d *);
point3d * LinearTransf3d(matrix3d *, point3d *);
object3d * ConvertObjectBase(matrix3d *, object3d *);
object3d * ParalProjFaces(object3d *, float);
object3d * PerspProjFaces(object3d *, float, float);
bool FaceView(face *, point3d *);
object3d * CleanFaces(object3d *, point3d *);
object2d * Obj3dtoObj2d(object3d *);
object3d * ObjectFromData(char *, char *, int);
matrix3d * Rot_X_Matr(float);
matrix3d * Rot_Y_Matr(float);
matrix3d * Rot_Z_Matr(float);
matrix3d * Scale_Matr(float, float, float); 
matrix3d * Shift_Matr(float, float, float);
matrix3d * Persp_Proj_Matr(float, float);
object3d * TransObject(matrix3d *, object3d *);


