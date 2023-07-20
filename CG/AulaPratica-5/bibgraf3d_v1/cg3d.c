#include "cg3d.h"

point3d * VectorProduct3d(point3d * u, point3d * v) {
 point3d * w;
 w = (point3d *) malloc(sizeof(point3d));

 w->x = (u->y)*(v->z) - (u->z)*(v->y);
 w->y = (u->z)*(v->x) - (u->x)*(v->z);
 w->z = (u->x)*(v->y) - (u->y)*(v->x);
 
 w->color = 1;
 
 return w;
 }
 
float Modulo3d(point3d * u) {
 return (sqrt(((u->x)*(u->x))+((u->y)*(u->y))+((u->z)*(u->z))));
 }

point3d * Versor3d(point3d * u) {
  point3d * w;
  float modulo = Modulo3d(u);
  w = (point3d *) malloc(sizeof(point3d));

  w->x = (u->x) / modulo;
  w->y = (u->y) / modulo; 
  w->z = (u->z) / modulo;
 
  w->color = 1;
 
  return w;
  }
 
face * CreateFace(int numbers_of_points) {
  face * fob;
 
  fob = (face *) malloc(sizeof(face));
  fob->numbers_of_points = 0;
  fob->points = (point3d *) malloc(numbers_of_points*sizeof(point3d));
 
  return fob;
  }
  
point3d * SetVertex3d(float x, float y, float z, float h, int color) {
  point3d * pnt;
  
  pnt = (point3d *) malloc(sizeof(point3d)); 
  pnt->x = x/h;
  pnt->y = y/h;
  pnt->z = z/h;  
  pnt->h = h/h;
  pnt->color = color;
  
  return pnt;
  }
  
int SetPointFace(point3d * pnt, face * fc) {

  fc->points[fc->numbers_of_points] = * pnt;
  fc->numbers_of_points = fc->numbers_of_points + 1;

  return 0;
  } 

object3d * CreateObject3d(int numbers_of_faces) {
  object3d * ob;
 
  ob = (object3d *) malloc(sizeof(object3d));
  ob->numbers_of_faces = 0;
  ob->faces = (face *) malloc(numbers_of_faces*sizeof(face));
 
  return ob;
  }

int SetObject3d(face * fc, object3d * ob) {

  ob->faces[ob->numbers_of_faces] = * fc;
  ob->numbers_of_faces = ob->numbers_of_faces + 1;

  return 0;
  }
  
matrix3d * CreateObserver(point3d * normal, point3d * viewup, point3d * offset) {
  point3d * u, * v, * w;
  matrix3d * m;
 
  w = (point3d *) malloc(sizeof(point3d));
  w->x = normal->x;
  w->y = normal->y;
  w->z = normal->z;
  w->h = 1.0;
  w->color = 0; 
  w = Versor3d(w);
 
  u = VectorProduct3d(viewup,w);
  u = Versor3d(u);
  v = VectorProduct3d(w,u);
  
  m = (matrix3d *) malloc(sizeof(matrix3d));
  m->a11 = u->x; m->a12 = u->y; m->a13 = u->z; m->a14 = offset->x;
  m->a21 = v->x; m->a22 = v->y; m->a23 = v->z; m->a24 = offset->y;
  m->a31 = w->x; m->a32 = w->y; m->a33 = w->z; m->a34 = offset->z;  
  m->a41 = 0.0;  m->a42 = 0.0;  m->a43 = 0.0;  m->a44 = 1.0;
  
  return m;
  }

point3d * LinearTransf3d(matrix3d * m, point3d * u) {
 point3d * p;
  
 p = (point3d *) malloc(sizeof(point3d));
  
 p->x = m->a11*u->x + m->a12*u->y + m->a13*u->z - m->a14*u->h;
 p->y = m->a21*u->x + m->a22*u->y + m->a23*u->z - m->a24*u->h;
 p->z = m->a31*u->x + m->a32*u->y + m->a33*u->z - m->a34*u->h;
 p->h = m->a41*u->x + m->a42*u->y + m->a43*u->z + m->a44*u->h;
 p->color = u->color;
  
 return p;  
 }

object3d * ConvertObjectBase(matrix3d * m, object3d * ob) {
 object3d * mob;
 point3d * p0, * p1;
 int numbers_of_points, numbers_of_faces;
  
 p0 = (point3d *) malloc(sizeof(point3d));
 p1 = (point3d *) malloc(sizeof(point3d));
 
 mob = (object3d *) malloc(sizeof(object3d));
 mob->numbers_of_faces = ob->numbers_of_faces;
 mob->faces = (face *) malloc(ob->numbers_of_faces*sizeof(face));
 
 for(numbers_of_faces=0;numbers_of_faces<ob->numbers_of_faces;numbers_of_faces++) {
   mob->faces[numbers_of_faces].numbers_of_points = ob->faces[numbers_of_faces].numbers_of_points;
   mob->faces[numbers_of_faces].points = (point3d *) malloc(ob->faces[numbers_of_faces].numbers_of_points*sizeof(point3d));
   for(numbers_of_points=0;numbers_of_points<ob->faces[numbers_of_faces].numbers_of_points;numbers_of_points++) {
     p0->x = ob->faces[numbers_of_faces].points[numbers_of_points].x;
     p0->y = ob->faces[numbers_of_faces].points[numbers_of_points].y;
     p0->z = ob->faces[numbers_of_faces].points[numbers_of_points].z;
     p0->h = ob->faces[numbers_of_faces].points[numbers_of_points].h;
     p0->color = ob->faces[numbers_of_faces].points[numbers_of_points].color;
     p1 = LinearTransf3d(m,p0); 
     mob->faces[numbers_of_faces].points[numbers_of_points].x = p1->x;    
     mob->faces[numbers_of_faces].points[numbers_of_points].y = p1->y; 
     mob->faces[numbers_of_faces].points[numbers_of_points].z = p1->z;
     mob->faces[numbers_of_faces].points[numbers_of_points].h = p1->h;
     mob->faces[numbers_of_faces].points[numbers_of_points].color = p1->color;
     }
   } 

 return mob; 
 }
 
object3d * ParalProjFaces(object3d * ob3d, float zpp) {
 object3d * ob;
 float x, y, z, h;
 int numbers_of_points, numbers_of_faces, color;
 
 ob = CreateObject3d(ob3d->numbers_of_faces);

 for(numbers_of_faces=0;numbers_of_faces<ob3d->numbers_of_faces;numbers_of_faces++) {
   ob->faces[numbers_of_faces].numbers_of_points = ob3d->faces[numbers_of_faces].numbers_of_points;
   ob->faces[numbers_of_faces].points = (point3d *) malloc((ob3d->faces[numbers_of_faces].numbers_of_points)*sizeof(point3d));
   for(numbers_of_points=0;numbers_of_points<ob3d->faces[numbers_of_faces].numbers_of_points;numbers_of_points++) {     
     x = ob3d->faces[numbers_of_faces].points[numbers_of_points].x;
     y = ob3d->faces[numbers_of_faces].points[numbers_of_points].y;
     z = zpp;
     h = 1.0;
     color = ob3d->faces[numbers_of_faces].points[numbers_of_points].color;
     ob->faces[numbers_of_faces].points[numbers_of_points].x = x;
     ob->faces[numbers_of_faces].points[numbers_of_points].y = y;
     ob->faces[numbers_of_faces].points[numbers_of_points].z = z;
     ob->faces[numbers_of_faces].points[numbers_of_points].h = h;
     ob->faces[numbers_of_faces].points[numbers_of_points].color = color;
     }
   ob->numbers_of_faces = ob->numbers_of_faces + 1;
   }

 return ob;
 }

object3d * PerspProjFaces(object3d * ob3d, float zpp, float zcp) {
 object3d * ob;
 float x, y, z, h;
 int numbers_of_points, numbers_of_faces, color;
 
 ob = CreateObject3d(ob3d->numbers_of_faces);
 
 for(numbers_of_faces=0;numbers_of_faces<ob3d->numbers_of_faces;numbers_of_faces++) {
   ob->faces[numbers_of_faces].numbers_of_points = ob3d->faces[numbers_of_faces].numbers_of_points;
   ob->faces[numbers_of_faces].points = (point3d *) malloc((ob3d->faces[numbers_of_faces].numbers_of_points)*sizeof(point3d));
   for(numbers_of_points=0;numbers_of_points<ob3d->faces[numbers_of_faces].numbers_of_points;numbers_of_points++) {
     x = ((ob3d->faces[numbers_of_faces].points[numbers_of_points].x)*(zpp-zcp))/(ob3d->faces[numbers_of_faces].points[numbers_of_points].z-zcp);
     y = ((ob3d->faces[numbers_of_faces].points[numbers_of_points].y)*(zpp-zcp))/(ob3d->faces[numbers_of_faces].points[numbers_of_points].z-zcp);
     z = zpp;
     h = 1.0;
     color = ob3d->faces[numbers_of_faces].points[numbers_of_points].color;
     ob->faces[numbers_of_faces].points[numbers_of_points].x = x;
     ob->faces[numbers_of_faces].points[numbers_of_points].y = y;
     ob->faces[numbers_of_faces].points[numbers_of_points].z = z;
     ob->faces[numbers_of_faces].points[numbers_of_points].h = h;
     ob->faces[numbers_of_faces].points[numbers_of_points].color = color;   
     }
   ob->numbers_of_faces = ob->numbers_of_faces + 1;     
   }
 
 return ob;  
 }

object2d * Obj3dtoObj2d(object3d * ob3d) {
  object2d * ob;
  polygon * pol;
  
  ob = CreateObject2d(ob3d->numbers_of_faces);
  
  for(int numbers_of_faces=0;numbers_of_faces<ob3d->numbers_of_faces;numbers_of_faces++) {
    pol = CreatePolig(ob3d->faces[numbers_of_faces].numbers_of_points);
    for(int numbers_of_points=0;numbers_of_points<ob3d->faces[numbers_of_faces].numbers_of_points;numbers_of_points++) {   
      float x = ob3d->faces[numbers_of_faces].points[numbers_of_points].x;
      float y = ob3d->faces[numbers_of_faces].points[numbers_of_points].y;
      float color = ob3d->faces[numbers_of_faces].points[numbers_of_points].color;      
      SetPolig(SetVertex(x,y,1.0,color),pol);
      }
    SetObject2d(pol,ob);
    }
  
  return ob;
  }

object3d * ObjectFromData(char * faces, char * vertices, int color) {
  struct data_face {
    int nface, vertice1, vertice2, vertice3;
    };
  struct data_vertice {
    int vertice_index;
    float x, y, z;
    };
  FILE * df;
  face * f;
  object3d * ob;
  const char s[2] = ",";
  char * result, * token, linha[80];
  int numbers_of_points, numbers_of_faces, k, v1, v2, v3;
  float x, y, z, info[4]; 
  struct data_face data_faces[MAX_FACES];
  struct data_vertice data_vertices[MAX_VERTICES]; 

  if ((df = fopen(faces,"r")) == NULL) {
    printf("Erro ao abrir o arquivo de faces.\n");
    exit(1);
    }
  numbers_of_faces = 0;
  while (!feof(df)) {
    result = fgets(linha,80,df);
    if (result) token = strtok(result,s);
    k = 0;
    while(token != NULL) {
      info[k] = atoi(token);
      token = strtok(NULL,s);
      k++;
      }
    data_faces[numbers_of_faces].nface = (int) info[0];
    data_faces[numbers_of_faces].vertice1 = (int) info[1];
    data_faces[numbers_of_faces].vertice2 = (int) info[2];  
    data_faces[numbers_of_faces].vertice3 = (int) info[3];           
    numbers_of_faces++;  
    }
  fclose(df);
  numbers_of_faces--;

  if ((df = fopen(vertices,"r")) == NULL) {
    printf("Erro ao abrir o arquivo de vértices.\n");
    exit(1);
    }
  numbers_of_points = 0;
  while (!feof(df)) {
    result = fgets(linha,80,df);
    if (result) token = strtok(result,s);
    k = 0;
    while(token != NULL) {
      if (k==0) info[k] = atoi(token);
      else info[k] = atof(token);
      token = strtok(NULL,s);
      k++;
      }
    data_vertices[numbers_of_points].vertice_index = (int) info[0];
    data_vertices[numbers_of_points].x = info[1];
    data_vertices[numbers_of_points].y = info[2];  
    data_vertices[numbers_of_points].z = info[3];           
    numbers_of_points++;  
    }
  fclose(df);
  numbers_of_points--;
  
  ob = CreateObject3d(numbers_of_faces);

  for(k=0;k<numbers_of_faces;k++) {
    f = CreateFace(3);
    v1 = data_faces[k].vertice1;
    x = data_vertices[v1].x;
    y = data_vertices[v1].y;
    z = data_vertices[v1].z;   
    SetPointFace(SetVertex3d(x,y,z,1.0,color),f);
    v2 = data_faces[k].vertice2;
    x = data_vertices[v2].x;
    y = data_vertices[v2].y;
    z = data_vertices[v2].z;   
    SetPointFace(SetVertex3d(x,y,z,1.0,color),f);
    v3 = data_faces[k].vertice3;
    x = data_vertices[v3].x;
    y = data_vertices[v3].y;
    z = data_vertices[v3].z;    
    SetPointFace(SetVertex3d(x,y,z,1.0,color),f);
    SetObject3d(f,ob);
    }  

  return ob;
  }
  
matrix3d * Rot_X_Matr(float theta) {
  matrix3d * m;

  m = (matrix3d *) malloc(sizeof(matrix3d));
  theta = (M_PI*theta)/180.0;

  m->a11 = 1.0; m->a12 = 0.0;        m->a13 = 0.0;         m->a14 = 0.0;
  m->a21 = 0.0; m->a22 = cos(theta); m->a23 = -sin(theta); m->a24 = 0.0;
  m->a31 = 0.0; m->a32 = sin(theta); m->a33 = cos(theta);  m->a34 = 0.0;
  m->a41 = 0.0; m->a42 = 0.0;        m->a43 = 0.0;         m->a44 = 1.0;

  return m;
  }

matrix3d * Rot_Y_Matr(float theta) {
  matrix3d * m;

  m = (matrix3d *) malloc(sizeof(matrix3d));
  theta = (M_PI*theta)/180.0;

  m->a11 = cos(theta);  m->a12 = 0.0; m->a13 = sin(theta); m->a14 = 0.0;
  m->a21 = 0.0;         m->a22 = 1.0; m->a23 = 0.0;        m->a24 = 0.0;
  m->a31 = -sin(theta); m->a32 = 0.0; m->a33 = cos(theta); m->a34 = 0.0;
  m->a41 = 0.0;         m->a42 = 0.0; m->a43 = 0.0;        m->a44 = 1.0;

  return m;
  }

matrix3d * Rot_Z_Matr(float theta) {
  matrix3d * m;

  m = (matrix3d *) malloc(sizeof(matrix3d));
  theta = (M_PI*theta)/180.0;

  m->a11 = cos(theta); m->a12 = -sin(theta); m->a13 = 0.0; m->a14 = 0.0;
  m->a21 = sin(theta); m->a22 = cos(theta);  m->a23 = 0.0; m->a24 = 0.0;
  m->a31 = 0.0;        m->a32 = 0.0;         m->a33 = 1.0; m->a34 = 0.0;
  m->a41 = 0.0;        m->a42 = 0.0;         m->a43 = 0.0; m->a44 = 1.0;

  return m;
  }

matrix3d * Scale_Matr(float sx, float sy, float sz) {
  matrix3d * m;

  m = (matrix3d *) malloc(sizeof(matrix3d));

  m->a11 = sx;  m->a12 = 0.0; m->a13 = 0.0; m->a14 = 0.0;
  m->a21 = 0.0; m->a22 = sy;  m->a23 = 0.0; m->a24 = 0.0;
  m->a31 = 0.0; m->a32 = 0.0; m->a33 = sz;  m->a34 = 0.0;
  m->a41 = 0.0; m->a42 = 0.0; m->a43 = 0.0; m->a44 = 1.0;

  return m;
  }

matrix3d * Shift_Matr(float dx, float dy, float dz) {
  matrix3d * m;

  m = (matrix3d *) malloc(sizeof(matrix3d));

  m->a11 = 1.0; m->a12 = 0.0; m->a13 = 0.0; m->a14 = dx;
  m->a21 = 0.0; m->a22 = 1.0; m->a23 = 0.0; m->a24 = dy;
  m->a31 = 0.0; m->a32 = 0.0; m->a33 = 1.0; m->a34 = dz;
  m->a41 = 0.0; m->a42 = 0.0; m->a43 = 0.0; m->a44 = 1.0;

  return m;
  }

matrix3d * Persp_Proj_Matr(float Zvp, float Zcp) {
  matrix3d * m;

  m = (matrix3d *) malloc(sizeof(matrix3d));

  m->a11 = 1.0; m->a12 = 0.0; m->a13 = 0.0;           m->a14 = 0.0;
  m->a21 = 0.0; m->a22 = 1.0; m->a23 = 0.0;           m->a24 = 0.0;
  m->a31 = 0.0; m->a32 = 0.0; m->a33 = Zvp/(Zvp-Zcp); m->a34 = -(Zvp*Zcp)/(Zvp-Zcp);
  m->a41 = 0.0; m->a42 = 0.0; m->a43 = 1.0/(Zvp-Zcp); m->a44 = -Zcp/(Zvp-Zcp);

  return m;
  }

matrix3d * ComposeMatrix3D(matrix3d * m1, matrix3d * m2) {
  matrix3d * m;

  m = (matrix3d *) malloc(sizeof(matrix3d));
  
  m->a11 = m1->a11*m2->a11 + m1->a12*m2->a21 + m1->a13*m2->a31 + m1->a14*m2->a41;
  m->a12 = m1->a11*m2->a12 + m1->a12*m2->a22 + m1->a13*m2->a32 + m1->a14*m2->a42;
  m->a13 = m1->a11*m2->a13 + m1->a12*m2->a23 + m1->a13*m2->a33 + m1->a14*m2->a43;
  m->a14 = m1->a11*m2->a14 + m1->a12*m2->a24 + m1->a13*m2->a34 + m1->a14*m2->a44;
  
  m->a21 = m1->a21*m2->a11 + m1->a22*m2->a21 + m1->a23*m2->a31 + m1->a24*m2->a41;
  m->a22 = m1->a21*m2->a12 + m1->a22*m2->a22 + m1->a23*m2->a32 + m1->a24*m2->a42;
  m->a23 = m1->a21*m2->a13 + m1->a22*m2->a23 + m1->a23*m2->a33 + m1->a24*m2->a43;
  m->a24 = m1->a21*m2->a14 + m1->a22*m2->a24 + m1->a23*m2->a34 + m1->a24*m2->a44;
  
  m->a31 = m1->a31*m2->a11 + m1->a32*m2->a21 + m1->a33*m2->a31 + m1->a34*m2->a41;
  m->a32 = m1->a31*m2->a12 + m1->a32*m2->a22 + m1->a33*m2->a32 + m1->a34*m2->a42;
  m->a33 = m1->a31*m2->a13 + m1->a32*m2->a23 + m1->a33*m2->a33 + m1->a34*m2->a43;
  m->a34 = m1->a31*m2->a14 + m1->a32*m2->a24 + m1->a33*m2->a34 + m1->a34*m2->a44;

  m->a41 = m1->a41*m2->a11 + m1->a42*m2->a21 + m1->a43*m2->a31 + m1->a44*m2->a41;
  m->a42 = m1->a41*m2->a12 + m1->a42*m2->a22 + m1->a43*m2->a32 + m1->a44*m2->a42;
  m->a43 = m1->a41*m2->a13 + m1->a42*m2->a23 + m1->a43*m2->a33 + m1->a44*m2->a43;
  m->a44 = m1->a41*m2->a14 + m1->a42*m2->a24 + m1->a43*m2->a34 + m1->a44*m2->a44;
  
  return m;
  }

object3d * TransObject(matrix3d * m, object3d * ob) {
  object3d * mob;
  
  mob = ConvertObjectBase(m,ob);

  return mob;
  }



