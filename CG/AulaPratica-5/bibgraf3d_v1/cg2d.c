/* 
   Autor: Murillo Rodrigo Petrucelli Homem
   Departamento de Computação
   Universidade Federal de São Carlos

   Código para uma biblioteca gráfica bidimensional
*/

#include "cg2d.h"

world * SetWorld(float XWMin, float YWMin, float XWMax, float YWMax) {
  world * universo;
  
  universo = CreateWindow(XWMin,YWMin,XWMax,YWMax);

  return universo;
  }

point2d * GetMinWorld(world * universo) {
  point2d * p;
  
  p = (point2d *) malloc(sizeof(point2d)); 

  p->x = universo->xmin;
  p->y = universo->ymin;
  
  return p;  
  }
  
point2d * GetMaxWorld(world * universo) {
  point2d * p;
  
  p = (point2d *) malloc(sizeof(point2d)); 

  p->x = universo->xmax;
  p->y = universo->ymax;
  
  return p; 
  }

point2d * SetVertex(float x, float y, float w, int color) {
  point2d * pnt;
  
  pnt = (point2d *) malloc(sizeof(point2d)); 
  pnt->x = x/w;
  pnt->y = y/w;
  pnt->w = w/w;
  pnt->color = color;
  
  return pnt;
  }
  
float GetXVertex(point2d * pnt) {
  float x;
  
  x = pnt->x;
  
  return x;
  }
  
float GetYVertex(point2d * pnt) {
  float y;
  
  y = pnt->y;
  
  return y;
  } 

polygon * CreatePolig(int numbers_of_points) {
  polygon * ob;
 
  ob = (polygon *) malloc(sizeof(polygon));
  ob->numbers_of_points = 0;
  ob->points = (point2d *) malloc(numbers_of_points*sizeof(point2d));
 
  return ob;
  }

int SetPolig(point2d * pnt, polygon * ob) {
  ob->points[ob->numbers_of_points] = * pnt;
  ob->numbers_of_points = ob->numbers_of_points + 1;

  return 0;
  }
  
object2d * CreateObject2d(int numbers_of_polygons) {
  object2d * ob;
  
  ob = (object2d *) malloc(sizeof(object2d));
  ob->numbers_of_polygons = 0;
  ob->pol = (polygon *) malloc(numbers_of_polygons*sizeof(polygon));
 
  return ob;
  }

int SetObject2d(polygon * polig, object2d * ob) {
  ob->pol[ob->numbers_of_polygons] = *polig;
  ob->numbers_of_polygons = ob->numbers_of_polygons + 1;
  }

object2d * poligono_regular(float tamLado, int numLados) {

  object2d * obj = CreateObject2d(1);
  polygon * pol = CreatePolig(numLados);
  float x = 0.0, y = 0.0, cx, cy;
  float angInterno = M_PI * (numLados - 2) / numLados;
  float angSuplementar = M_PI - angInterno;

  for (int i = 0; i < numLados; i++) {
    SetPolig(SetVertex(x, y, 1, 1), pol);
    x += tamLado * cos(angSuplementar * (i + 1));
    y += tamLado * sin(angSuplementar * (i + 1));
    }

  SetObject2d(pol, obj);
  cx = GetXVertex(Centroide(obj));
  cy = GetYVertex(Centroide(obj));
  obj = TransObj(obj,SetSftMatrix(-cx,-cy));

  return obj;
  }

palette * CreatePalette(int numbers_of_colors) {
  palette * pal;

  pal = (palette *) malloc(sizeof(palette));
  pal->numbers_of_colors = 0;
  pal->colors = (ColorValues *) malloc(numbers_of_colors*sizeof(ColorValues));
  
  return pal;
  }

int SetColor(float red, float green, float blue, palette * pal) {
  pal->colors[pal->numbers_of_colors].red = red;
  pal->colors[pal->numbers_of_colors].green = green;
  pal->colors[pal->numbers_of_colors].blue = blue;
  pal->numbers_of_colors = pal->numbers_of_colors + 1;

  return 0;
  }
  
ColorValues * GetColor(int value, palette * pal) {
 ColorValues * color;
 
 color = (ColorValues *) malloc(sizeof(ColorValues)); 
 color->red = pal->colors[value].red;
 color->green = pal->colors[value].green;
 color->blue = pal->colors[value].blue; 
 
 return color;
 }

window * CreateWindow(float xmin, float ymin, float xmax, float ymax) {
  window * win;

  win = (window *) malloc(sizeof(window));
  
  win->xmin = xmin;
  win->ymin = ymin;
  win->xmax = xmax;
  win->ymax = ymax;
  
  return win;
  }

viewport * CreateViewPort(int xmin, int ymin, int xmax, int ymax) {
  viewport * port;

  port = (viewport *) malloc(sizeof(viewport));
  
  port->xmin = xmin-1;
  port->ymin = ymin-1;
  port->xmax = xmax-1;
  port->ymax = ymax-1;
  
  return port;
  }

point2d * Sru2Srn(point2d * ponto, window * janela) {
  point2d * np;

  np = (point2d *) malloc(sizeof(point2d));
  np->x = ((ponto->x/ponto->w) - janela->xmin)/(janela->xmax - janela->xmin);
  np->y = ((ponto->y/ponto->w) - janela->ymin)/(janela->ymax - janela->ymin);
  np->w = ponto->w/ponto->w;
  np->color = ponto->color;
  
  return np;  
  }

point2d * Srn2Srd(point2d * ponto, viewport * port) {
  point2d * dpt;

  dpt = (point2d *) malloc(sizeof(point2d));
  dpt->x = port->xmin + round((ponto->x)*((port->xmax - port->xmin) - 1));
  dpt->y = port->ymin + round((ponto->y)*((port->ymax - port->ymin) - 1));
  dpt->w = ponto->w;
  dpt->color = ponto->color;
 
  return dpt;
  }

bufferdevice * CreateBuffer(int maxx, int maxy) {  
  bufferdevice * dev;
  
  dev = (bufferdevice *) malloc(sizeof(bufferdevice));
  dev->MaxX = maxx;
  dev->MaxY = maxy;
  dev->buffer = (int *) malloc(maxx*maxy*sizeof(int));
    
  return dev;
  }
  
int DrawViewPort(viewport * port, bufferdevice * dev, int color) {

  for(int i=port->xmin;i<port->xmax;i++) {
    SetPixel(i,port->ymin,color,port,dev);
    SetPixel(i,port->ymax,color,port,dev);    
    }

  for(int j=port->ymin;j<=port->ymax;j++) {
    SetPixel(port->xmin,j,color,port,dev);
    SetPixel(port->xmax,j,color,port,dev);  
    }

  return 0;
  }
  
int Bresenham(int x1, int y1, int x2, int y2, viewport * port, bufferdevice * dev, int color) {
  int i, j, dx, dy, sx, sy, erro, novo_erro, continua;
  
  i = x1;
  j = y1;

  dx = abs(x2 - x1);
  dy = abs(y2 - y1);
  
  if (x1 < x2) sx = 1;
  else sx = -1;
  
  if (y1 < y2) sy = 1;
  else sy = -1;
  
  if (dx > dy) erro = dx/2;
  else erro = -dy/2; 

  continua = 1;
  while (continua) {
     SetPixel(i,j,color,port,dev);
     if ((i == x2) && (j == y2)) continua = 0;
     novo_erro = erro;
     if (novo_erro > -dx) { 
        erro = erro - dy; 
        i = i + sx; 
        }
     if (novo_erro < dy) {
        erro = erro + dx; 
        j = j + sy;
        }
     }
 
  return 0;
  }

int DrawObject(object2d * ob, window * win, viewport * port, bufferdevice * dev, int color) {

  int i, j;
  float aux;
  point2d * p1, * p2, * paux, * pn1, * pn2, * pd1, * pd2;
  
  p1 = (point2d *) malloc(sizeof(point2d));
  p2 = (point2d *) malloc(sizeof(point2d));
  paux = (point2d *) malloc(sizeof(point2d));

  DrawViewPort(port,dev,1);
  
  for(j=0;j<ob->numbers_of_polygons;j++) {
    for(i=0;i<ob->pol[j].numbers_of_points;i++) {
      p1 = SetVertex(ob->pol[j].points[i].x,ob->pol[j].points[i].y,ob->pol[j].points[i].w,ob->pol[j].points[i].color);
      p2 = SetVertex(ob->pol[j].points[(i+1)%ob->pol[j].numbers_of_points].x,ob->pol[j].points[(i+1)%ob->pol[j].numbers_of_points].y,ob->pol[j].points[(i+1)%ob->pol[j].numbers_of_points].w,ob->pol[j].points[(i+1)%ob->pol[j].numbers_of_points].color);
      if (p1->y > p2->y) {
        aux = p1->y;
        p1->y = p2->y;
        p2->y = aux;
        aux = p1->x;
        p1->x = p2->x;
        p2->x = aux;
        }   
      if ((p1->y < win->ymax)&&(p2->y > win->ymax)) {
        paux = InterY(p1,p2,win->ymax);
        if (InWin(paux,win)) {
          p2 = paux;
          } 
        }
      if ((p1->y < win->ymin)&&(p2->y > win->ymin)) {
        paux = InterY(p1,p2,win->ymin);
        if (InWin(paux,win)) {
          p1 = paux;
          } 
        }
      if (p1->x > p2->x) {
        aux = p1->y;
        p1->y = p2->y;
        p2->y = aux;
        aux = p1->x;
        p1->x = p2->x;
        p2->x = aux;
        }      
      if ((p1->x < win->xmax)&&(p2->x > win->xmax)) {
        paux = InterX(p1,p2,win->xmax);
        if (InWin(paux,win)) {
          p2 = paux;
          } 
        }
      if ((p1->x < win->xmin)&&(p2->x > win->xmin)) {
        paux = InterX(p1,p2,win->xmin);
        if (InWin(paux,win)) {
          p1 = paux;
          } 
        }
      if ((InWin(p1,win))&&(InWin(p2,win))) {
	pn1 = Sru2Srn(p1,win);
	pd1 = Srn2Srd(pn1,port);
	pn2 = Sru2Srn(p2,win);
	pd2 = Srn2Srd(pn2,port);
	Bresenham(pd1->x,pd1->y,pd2->x,pd2->y,port,dev,color);
        }
      }
    }  

  return 0;
  }

point2d * Centroide(object2d * ob) {
   point2d * p;
   polygon * pol;
   float cx, cy;
   
   pol = &ob->pol[0];
   
   p = (point2d *) malloc(sizeof(point2d));

   cx = 0.0;
   cy = 0.0;
   for(int i=0;i<pol->numbers_of_points;i++) {
     cx = cx + pol->points[i].x;
     cy = cy + pol->points[i].y;
     }
   cx = cx/pol->numbers_of_points;
   cy = cy/pol->numbers_of_points;   
    
   p -> x = cx;
   p -> y = cy;
   p -> w = 1;
   p -> color = 0;
     
  return p;     
  }
  
matrix * SetRotMatrix(float theta) {
  matrix * m;

  m = (matrix *) malloc(sizeof(matrix));
  theta = (M_PI*theta)/180.0;
  
  m->a11 = cos(theta); m->a12 = (-1.0)*sin(theta); m->a13 = 0.0;
  m->a21 = sin(theta); m->a22 = cos(theta);        m->a23 = 0.0;
  m->a31 = 0.0;        m->a32 = 0.0;               m->a33 = 1.0;
  
  return m;
  }

matrix * SetSftMatrix(float dx, float dy) {
  matrix * m;

  m = (matrix *) malloc(sizeof(matrix));
  
  m->a11 = 1.0;  m->a12 = 0.0;  m->a13 = dx;
  m->a21 = 0.0;  m->a22 = 1.0;  m->a23 = dy;
  m->a31 = 0.0;  m->a32 = 0.0;  m->a33 = 1.0;
  
  return m;
  }

matrix * SetSclMatrix(float sx, float sy) {
  matrix * m;

  m = (matrix *) malloc(sizeof(matrix));
  
  m->a11 = sx;  m->a12 = 0.0;  m->a13 = 0.0;
  m->a21 = 0.0; m->a22 = sy;   m->a23 = 0.0;
  m->a31 = 0.0; m->a32 = 0.0;  m->a33 = 1.0;
  
  return m;
  }
  
matrix * SetSpltMatrix(float x, float y) {
  matrix * m;

  m = (matrix *) malloc(sizeof(matrix));
  
  m->a11 = x;   m->a12 = 0.0; m->a13 = 0.0;
  m->a21 = 0.0; m->a22 = y;   m->a23 = 0.0;
  m->a31 = 0.0; m->a32 = 0.0; m->a33 = 1.0;
  
  return m;
  }
  
matrix * SetCisMatrix(float Sx, float Sy) {
  matrix * m;

  m = (matrix *) malloc(sizeof(matrix));
  
  m->a11 = 1.0;  m->a12 = Sx;   m->a13 = 0.0;
  m->a21 = Sy;   m->a22 = 1.0;  m->a23 = 0.0;
  m->a31 = 0.0;  m->a32 = 0.0;  m->a33 = 1.0;
  
  return m;
  }
  
matrix * ComposeMatrix(matrix * m1, matrix * m2) {
  matrix * m;

  m = (matrix *) malloc(sizeof(matrix));
  
  m->a11 = m1->a11*m2->a11 + m1->a12*m2->a21 + m1->a13*m2->a31;
  m->a12 = m1->a11*m2->a12 + m1->a12*m2->a22 + m1->a13*m2->a32;
  m->a13 = m1->a11*m2->a13 + m1->a12*m2->a23 + m1->a13*m2->a33;
  
  m->a21 = m1->a21*m2->a11 + m1->a22*m2->a21 + m1->a23*m2->a31;
  m->a22 = m1->a21*m2->a12 + m1->a22*m2->a22 + m1->a23*m2->a32;
  m->a23 = m1->a21*m2->a13 + m1->a22*m2->a23 + m1->a23*m2->a33;
  
  m->a31 = m1->a31*m2->a11 + m1->a32*m2->a21 + m1->a33*m2->a31;
  m->a32 = m1->a31*m2->a12 + m1->a32*m2->a22 + m1->a33*m2->a32;
  m->a33 = m1->a31*m2->a13 + m1->a32*m2->a23 + m1->a33*m2->a33;
  
  return m;
  }
  
point2d * LinearTransf(matrix * m, point2d * p) {
  point2d * pt;
  
  pt = (point2d *) malloc(sizeof(point2d));
  
  pt->x = m->a11*p->x + m->a12*p->y + m->a13*p->w;
  pt->y = m->a21*p->x + m->a22*p->y + m->a23*p->w;
  pt->w = m->a31*p->x + m->a32*p->y + m->a33*p->w;
  pt->color = p->color;
  
  return pt;
  }
  
polygon * TransPolig(polygon * pol1, matrix * m) {
  int i;
  polygon * pol2;
  point2d * p, * pt;

  pol2 = CreatePolig(pol1->numbers_of_points);
  
  for(i=0;i<pol1->numbers_of_points;i++) {
     p = SetVertex(pol1->points[i].x,pol1->points[i].y,pol1->points[i].w,pol1->points[i].color);
     pt = LinearTransf(m,p);
     SetPolig(SetVertex(pt->x,pt->y,pt->w,pt->color),pol2);
     }

  return pol2;
  }  

object2d * TransObj(object2d * ob, matrix * m) {
  int i;
  object2d * obj;
  polygon * polig1, * polig2;

  obj = CreateObject2d(ob->numbers_of_polygons);
   
  for(i=0;i<ob->numbers_of_polygons;i++) {
     polig1 = &ob->pol[i];
     polig2 = TransPolig(polig1,m);
     SetObject2d(polig2,obj);
     }

  return obj;
  }

int InWin(point2d * pt, window * win) {
  if ((pt->x >= win->xmin)&&(pt->x <= win->xmax)&&(pt->y >= win->ymin)&&(pt->y <= win->ymax)) return 1;
  else return 0;
  }
 
point2d * InterX(point2d * p1, point2d * p2, float x) {
 float a , b, aux;
 
 if (p2->x - p1->x) {
   a = (p2->y - p1->y)/(p2->x - p1->x);
   b = p1->y - a*p1->x;
   aux = a*x+b;
   }
 else aux = INT_MAX; 
 
 return SetVertex(x,aux,1,p1->color);
 }

point2d * InterY(point2d * p1, point2d * p2, float y) {
 float a , b, aux;

 if (p2->x - p1->x) {
   a = (p2->y - p1->y)/(p2->x - p1->x);
   b = p1->y - a*p1->x;
   if (a) aux = (y-b)/a;
   else aux = INT_MAX; 
   }
 else aux = p2->x;
 
 return SetVertex(aux,y,1,p1->color);
 }
 
int SetPixel(int x, int y, int color, viewport * port, bufferdevice * buffer) {

  int offset = (port->ymin + port->ymax - y) * buffer->MaxX + x;
  buffer->buffer[offset] = color;
 
  return 0;
  }
  
int GetPixel(int x, int y, viewport * port, bufferdevice * buffer) {

  int offset = (port->ymin + port->ymax - y) * buffer->MaxX + x;
    
  return buffer->buffer[offset];
  }

int Fill(object2d * obj, int color, window * win, viewport * port, bufferdevice * buffer) {
  float cx, cy;
  point2d * srd_entry;
  
  cx = GetXVertex(Centroide(obj));
  cy = GetYVertex(Centroide(obj));
  srd_entry = Srn2Srd(Sru2Srn(Centroide(obj),win),port);
  cx = GetXVertex(srd_entry);
  cy = GetYVertex(srd_entry);
      
  DrawObject(obj,win,port,buffer,-1);

  FloodFill((int)cx,(int)cy,color,port,buffer);
  ChangeColorDevice(-1,color,port,buffer);
  
  return 0;  
  }
  
int FloodFill(int x, int y, int color, viewport * port, bufferdevice * buffer) {
  int cor;
  
  cor = GetPixel(x,y,port,buffer);
  
  if (cor == color) return 0;
  if (cor == -1) {
    SetPixel(x,y,color,port,buffer);
    return 0;
    }
  else {
    SetPixel(x,y,color,port,buffer);
    FloodFill(x+1,y,color,port,buffer);
    FloodFill(x-1,y,color,port,buffer); 
    FloodFill(x,y+1,color,port,buffer); 
    FloodFill(x,y-1,color,port,buffer);      
    }
 
  return 0; 
  }
  
void ChangeColorDevice(int old, int new, viewport * port, bufferdevice * buffer) {

  for(int j=port->ymin;j<=port->ymax;j++) {
    for(int i=port->xmin;i<port->xmax;i++) {
      if (GetPixel(i,j,port,buffer) == old) SetPixel(i,j,new,port,buffer);
      }
    }

  }

void ClearDevice(viewport * port, bufferdevice * buffer) {

  for(int j=port->ymin;j<=port->ymax;j++) {
    for(int i=port->xmin;i<port->xmax;i++) {
      SetPixel(i,j,0,port,buffer);
      }
    }

  }

int InitGraf(bufferdevice * dev) {
  width = dev->MaxX;
  height = dev->MaxY;
  
  if ((display = XOpenDisplay(NULL)) == NULL) {
    printf("display: problemas com o ambiente de janelas do X-Window.\n");
    exit(1);
    }
  else {  
    screen = DefaultScreen(display);
    dplanes = DisplayPlanes(display,screen);   
    visual = XDefaultVisual(display,screen);
  
    if (!(so_window=XCreateSimpleWindow(display,RootWindow(display,screen),0,0,width,height,1,BlackPixel(display,screen),WhitePixel(display,screen)))) {
      printf("janela do SO: problemas com o ambiente de janelas do X-Window.\n");
      exit(1);
      }
    else {
      XSelectInput(display, so_window, EventMask);
      XStoreName(display, so_window, "Monitor Virtual");
      gc = XCreateGC(display, so_window, 0, &values);
  
      XMapWindow(display,so_window);
      XSync(display,False);
  
      ximage = XCreateImage(display,visual,dplanes,ZPixmap,0,malloc(width*height*sizeof(int)),width,height,8,0);

      for(int m=0;m<height;m++) {
        for(int n=0;n<width;n++) {
          ximage -> data[(m*4)*width+n*4+0] = (char) 0;
          ximage -> data[(m*4)*width+n*4+1] = (char) 0;
          ximage -> data[(m*4)*width+n*4+2] = (char) 0;
          ximage -> data[(m*4)*width+n*4+3] = (char) 0;
          }
        }

      XPutImage(display,so_window,gc,ximage,0,0,0,0,width,height);
      XFlush(display);
      }
    }
      
  return 0; 
  }

int RefreshX(bufferdevice * dev, palette * pal) {
  ColorValues  * cor;
  float r, g, b;

  for(int m=0;m<height;m++) {
    for(int n=0;n<width;n++) {
       if (dev->buffer[m*width+n] < 0) {
          b = 0.0;
          g = 0.0;
          r = 0.0;
          }
       else {        	
          cor = GetColor(dev->buffer[m*width+n],pal);
          b = cor->blue;
          g = cor->green;
          r = cor->red;
          }     
       ximage -> data[(m*4)*width+n*4+0] = (char) round(b*255);
       ximage -> data[(m*4)*width+n*4+1] = (char) round(g*255);
       ximage -> data[(m*4)*width+n*4+2] = (char) round(r*255);
       ximage -> data[(m*4)*width+n*4+3] = (char) 0;
       }
    }

    XPutImage(display,so_window,gc,ximage,0,0,0,0,width,height);
    XFlush(display);
  
  return 0;    
  }

int Display_SRD(bufferdevice * dev, palette * pal) {
  int fb_fd, fb_width, fb_height, fb_bpp, fb_bytes, fb_data_size, 
      offset, x, y, dev_width, dev_height, off_x, off_y, 
      line_length, passo, acerto;
  char * fb_data;
  float r, g, b, a;
  ColorValues * cor = (ColorValues *) malloc(sizeof(ColorValues));      
  struct fb_var_screeninfo vinfo;
  struct fb_fix_screeninfo finfo;
 
  fb_fd = open("/dev/fb0", O_WRONLY);  

  if (fb_fd == -1) {
    perror("Erro: não foi possível abrir o framebuffer.");
    exit(1);
    }

  ioctl(fb_fd, FBIOGET_VSCREENINFO, &vinfo);
  ioctl(fb_fd, FBIOGET_FSCREENINFO, &finfo);

  fb_width = vinfo.xres;
  fb_height = vinfo.yres;
  fb_bpp = vinfo.bits_per_pixel;
  fb_bytes = fb_bpp / 8;
  fb_data_size = fb_width * fb_height * fb_bytes;
  line_length = finfo.line_length;
  passo = max(line_length,fb_width*fb_bytes);
  acerto = passo - (fb_width*fb_bytes);
  
  fb_data = (char *) malloc(fb_data_size*sizeof(char));
 
  dev_height = dev->MaxY;
  off_y = (fb_height - dev_height)/2;
  dev_width = dev->MaxX;
  off_x = (fb_width - dev_width)/2; 
  
  //printf("Desocamento em x: %d\n",off_x);
  //printf("Desocamento em y: %d\n",off_y);
  //printf("Resolução em x: %d\n",vinfo.xres);
  //printf("Resolução em y: %d\n",vinfo.yres);
  //printf("bits per pixel: %d\n",vinfo.bits_per_pixel);
  //printf("Comprimento linha: %d\n",line_length);
  
  if ((dev_width < fb_width) && (dev_height < fb_height)) {
    for(y=0;y<fb_height;y++) {
      for(x=0;x<fb_width;x++) {
        offset = (y * fb_width + x) * fb_bytes;
        fb_data[offset+0] = (char) 0;
        fb_data[offset+1] = (char) 0;
        fb_data[offset+2] = (char) 0;
        fb_data[offset+3] = (char) 0;
        }
      } 
    for(y=off_y;y<fb_height-off_y;y++) {
      for(x=off_x;x<fb_width-off_x;x++) {
        if (dev->buffer[(y-off_y)*dev_width+(x-off_x)] < 0) {
          r = 0.0; g = 0.0; b = 0.0; a = 0.0;
          }
        else {
          cor = GetColor(dev->buffer[(y-off_y)*dev_width+(x-off_x)],pal);
          r = cor->red;
          g = cor->green;
          b = cor->blue;
          a = 0.0;
          }
        offset = (y * fb_width + x) * fb_bytes + y * acerto;
        fb_data[offset+0] = (char) round(b*255);
        fb_data[offset+1] = (char) round(g*255);
        fb_data[offset+2] = (char) round(r*255);
        fb_data[offset+3] = (char) round(a*255);     
        }
      }
    }
  else {
    printf("As dimensões do SRD são maiores do que a geometria do frame buffer (fb0).\n");
    printf("Utilize o programa fbset para verificar as dimensões do fb.\n");    
    }

  write(fb_fd,fb_data,fb_data_size);
  close(fb_fd);
  
  return 0;
  }

int Dump2X(bufferdevice * dev, palette * pal) {
  Display               * display;
  XImage                * ximage;
  Window                window;
  XEvent                an_event;
  GC                    gc;
  Visual                * visual;
  XGCValues             values;
  int                   m, n, screen, dplanes;
  int                   width, height, ret = 1;
  ColorValues           * cor;
  
  width = dev->MaxX;
  height = dev->MaxY; 

  if ((display = XOpenDisplay(NULL)) == NULL) ret = 0;
  else {  
    screen = DefaultScreen(display);
    dplanes = DisplayPlanes(display,screen);   
    visual = XDefaultVisual(display,screen);
  
    if (!(window=XCreateSimpleWindow(display,RootWindow(display,screen),0,0,width,height,1,BlackPixel(display,screen),WhitePixel(display,screen)))) ret = 0;
    else {
      XSelectInput(display, window, EventMask);
      XStoreName(display, window, "Monitor Virtual");
      gc = XCreateGC(display, window, 0, &values);
  
      XMapWindow(display,window);
      XSync(display,False);
  
      ximage = XCreateImage(display,visual,dplanes,ZPixmap,0,malloc(width*height*sizeof(int)),width,height,8,0);

      for(m=0;m<height;m++) {
        for(n=0;n<width;n++) {
          cor = GetColor(dev->buffer[m*width+n],pal);
          ximage -> data[(m*4)*width+n*4] = (char) round((cor->blue)*255);
          ximage -> data[(m*4)*width+n*4+1] = (char) round((cor->green)*255);
          ximage -> data[(m*4)*width+n*4+2] = (char) round((cor->red)*255);
          ximage -> data[(m*4)*width+n*4+3] = (char) 0;
          }
        }

      XPutImage(display,window,gc,ximage,0,0,0,0,width,height);
      
      while(1) {
      XNextEvent(display, &an_event);
      switch(an_event.type) {
	case Expose:
             	XPutImage(display,window,gc,ximage,0,0,0,0,width,height);
                break;
	
           }
        }

      }
    }
 
  return ret;
  }

