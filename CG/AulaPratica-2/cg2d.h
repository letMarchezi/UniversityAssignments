
/* 
   Autor: Murillo Rodrigo Petrucelli Homem
   Departamento de Computação
   Universidade Federal de São Carlos

   Código de uma biblioteca gráfica bidimensional
*/

#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <X11/Xlib.h>

#define max(v1,v2) ((v1 >= v2) ? (v1) : (v2))

#define EventMask (KeyPressMask | ExposureMask | ResizeRedirectMask)

// Variáveis globais do X-Window apenas para visualização
Display               * display;
XImage                * ximage;
Window                so_window;
XEvent                an_event;
GC                    gc;
Visual                * visual;
XGCValues             values;
int                   screen, dplanes, width, height;

//   Exemplo de estruturas de dados para a biblioteca de 
//   funções gráficas em C considerando uma porção do 
//   plano como referência para o mundo (planolândia) 

// Janela de visualização definida no SRU
typedef struct CG_Window {
  float xmin,
        ymin,
        xmax,
        ymax;
        } window;
        
typedef window world;        
 
// Porta de visualização (viewport) definida no SRD     
typedef struct ViewPort {
  int xmin,
      ymin,
      xmax,
      ymax;
      } viewport;

// Estrutura de dados para um ponto no plano (SRU 2D) com 
// uma componente homogênea (w != 0)
typedef struct HPoint2D {
  float x,
        y,
        w;  // componente homogênea 
  int   color;
        } point;
 
// Estrutura de dados para um objeto (polígono) no plano (SRU 2D)     
typedef struct Polygon {
  int numbers_of_points;
  point * points;
  } polygon;
  
typedef struct Object {
  int numbers_of_polygons;
  polygon * pol;
  } object2d;

// Estrutura de dados para uma componente de cor no 
// modelo aditivo RGB
typedef struct Color {
  float red,
        green,
        blue;
        } ColorValues;
  
// Paleta de cores (colormap)    
typedef struct Palette {
  int numbers_of_colors;
  ColorValues * colors;
  } palette;

// Estrutura de dados para uma grade bidimensional de 
// entradas que corresponde ao SRD
typedef struct Buffer {
  int MaxX, // número de colunas
      MaxY; // número de linhas
  int * buffer;
  } bufferdevice;
  
// Estrutura para uma matriz homogênea para operações
// lineares no plano - SRU
typedef struct HMatrix2D {
  float a11, a12, a13,
        a21, a22, a23,
        a31, a32, a33;
        } matrix;

/* Determina os limites do mundo */
world * SetWorld(float, float, float, float);
point * GetMinWorld();
point * GetMaxWorld();

/* cria pontos, polígonos e objetos no mundo */
point * SetVertex(float, float, float, int);
float GetXVertex(point *);
float GetYVertex(point *);
polygon * CreatePolig(int);
int SetPolig(point *, polygon *);
object2d * CreateObject2d(int);
int SetObject(polygon *, object2d *);
object2d * poligono_regular(float, point *, int);

/* Funções para criar e gerenciar uma paleta de cores */
palette * CreatePalette(int);
int SetColor(float, float, float, palette *);
ColorValues * GetColor(int, palette *);

/* Sistemas de referências, janelas e viewports */
window * CreateWindow(float, float, float, float);
viewport * CreateViewPort(int, int, int, int);
point * Sru2Srn(point *, window *);
point * Srn2Srd(point *, viewport *);
bufferdevice * CreateBuffer(int, int);

/* Funções para conversão matricial e preenchimento de objetos */
int DrawViewPort(viewport *, bufferdevice *, int);
int Bresenham(int, int, int, int, viewport *, bufferdevice *, int);
int DrawObject(object2d *, window *, viewport *, bufferdevice *, int);

/* Construção das matrizes homogêneas para as operações lineares */
point * Centroide(polygon *);  // calcula o centro geométrico de um objeto (polígono)
matrix * SetRotMatrix(float); // cria uma matriz para a operação de rotação
matrix * SetSftMatrix(float, float); // cria uma matriz para a operação de deslocamento
matrix * SetSclMatrix(float, float); // cria uma matriz para a operação de escalonamento
matrix * SetSpltMatrix(float, float); // cria uma matriz para a operação de espelhamento
matrix * SetCisMatrix(float, float); // cria uma matriz para a operação de cisalhamento
matrix * ComposeMatrix(matrix *, matrix *);
point * LinearTransf(matrix *, point *);

/* Operações lineares sobre poligonos no SRU 2D */
polygon * TransPolig(polygon *, matrix *);
object2d * TransObj(object2d *, matrix *);

/* Funções auxiliares (recorte de primitivas) */
int InWin(point *, window *);
point * InterX(point *, point *, float);
point * InterY(point *, point *, float);
int SetPixel(int, int, int, viewport *, bufferdevice *);
int GetPixel(int, int, viewport *, bufferdevice *);
int ValidSeed(int, int, viewport *, bufferdevice *);

/* Preenchimento de polígonos */
int Fill(object2d *, int, window *, viewport *, bufferdevice *, int, int, int);
int FloodFill(int, int, int, viewport *, bufferdevice *);
int ScanLine(int, viewport *, bufferdevice *);
void ChangeColorDevice(int, int, viewport *, bufferdevice *);
void ClearDevice(viewport *, bufferdevice *);

// Visualiza o buffer (SRD) no monitor virtual do ambiente X
int InitGraf(bufferdevice *);
int RefreshX(bufferdevice *, palette *);

// Visualiza o buffer do SRD diretamente em um terminal tty
// Esta função escreve diretamente no framebuffer através da interface /dev/fb0
int Display_SRD(bufferdevice *, palette *);
int Dump2X(bufferdevice *, palette *);


