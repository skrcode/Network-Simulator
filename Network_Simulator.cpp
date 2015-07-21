//Simulation with a segment tree

#include<cstdlib>
#include<windows.h>
#include<gl\gl.h>
#include<gl\glut.h>
#include <vector>
#include <cmath>
#include<iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <string.h>
#include <cassert>
#include <climits>
#include <ctime>
#define ARR_SIZE 1000000
using namespace std;

//int min(int a,int b) { return a<b ? a: b; }

int segtree[10000000];
int arr[ARR_SIZE];
int arr2[ARR_SIZE];

void build(int a[],int node,int b,int e) {
    if(b == e) {
        segtree[node] = a[b];
        return;
    }
    build(a,2*node,b,(b+e)/2);
    build(a,2*node+1,(b+e)/2+1,e);
    segtree[node] = min(segtree[2*node],segtree[2*node+1]);
}

int query(int a[],int node,int b,int e,int i,int j) {
    if(b>j || e<i) return INT_MAX;
    if(b>=i && e<=j)return segtree[node];

    int p = query(a,2*node,b,(b+e)/2,i,j);
    int q = query(a,2*node+1,(b+e)/2+1,e,i,j);

    return min(p,q);
}

void update(int a[],int node,int b,int e,int pos,int val) {
    if(b == e) {
        segtree[node] = val;
        return;
    }
    if(pos>=(b+e)/2+1)update(a,2*node+1,(b+e)/2+1,e,pos,val);
    else update(a,2*node,b,(b+e)/2,pos,val);
    segtree[node] = min(segtree[2*node],segtree[2*node+1]);
}

const float DEG2RAD = 3.14159/180;

void drawCircle(float radius)
{
   glBegin(GL_POINTS);

 for(int i=0;i<1000;++i)

  {

  glVertex3f(cos(2*3.14159*i/1000.0),sin(2*3.14159*i/1000.0),0);

  }

 glEnd();
}
int x;

void draw_circle(float x, float y, float radius) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    static const int circle_points = 100;
    static const float angle = 2.0f * 3.1416f / circle_points;

    // this code (mostly) copied from question:
    glBegin(GL_POLYGON);
    double angle1=0.0;
    glVertex2d(radius * cos(0.0) , radius * sin(0.0));
    int i;
    for (i=0; i<circle_points; i++)
    {
        glVertex2d(radius * cos(angle1), radius *sin(angle1));
        angle1 += angle;
    }
    glEnd();
    glPopMatrix();
}
float r,g,b;
void RenderString(float x, float y, void *font, const char* str)
{
  glColor3f(r, g, b);
  glRasterPos2f(x, y);

  for (int i=0; i<strlen(str); i++)
    {
        glutBitmapCharacter(font, str[i]);
    }
}

void linquery(int a,int b)
{
    int i,j;
    for(i=a;i<b;i++)
        j=min(arr2[i],arr2[i+1]);
}


char conv[2];
void converter(int a)
{
    conv[0]='0';
    conv[1]='0';
    int i=0,rem;
    while(a>0)
    {
        rem=a%10;
        a=a/10;
        conv[i]=rem+48;
        ++i;
    }
    strrev(conv);

}

void endofexec()
{
    cout<<"\nThank you!\n";
    int pos,val;
    clock_t start = clock(), diff;
    for(long int i=0;i<1000;i++){
    x=query(arr,1,1,ARR_SIZE,10000,90000);
    pos=rand()%80000 + 10000;val=rand()%99 + 1;
    update(arr,1,1,ARR_SIZE,pos,val);}
    diff = clock() - start;
    int msec = diff * 1000 / CLOCKS_PER_SEC;
    cout<<"\nTIME for segment tree ops = "<<msec<<"\n";

    clock_t start1 = clock(), diff1;
    for(int i=0;i<1000;i++){
    linquery(10000,90000);
    pos=rand()%80000 + 10000;val=rand()%99 + 1;
    arr2[pos]=val;}
    diff1 = clock() - start1;
    msec = diff1 * 1000 / CLOCKS_PER_SEC;
    cout<<"\nTIME for array = "<<msec<<"\n";

    exit(0);
}



void display () {
   glFlush();
   glClear(GL_COLOR_BUFFER_BIT);
   int x;

  r=1.0;g=0.0;b=0.0;
  converter(arr[90000]);
  RenderString(-0.55f, 0.6f, GLUT_BITMAP_TIMES_ROMAN_24,conv);
  converter(arr[90001]);
  RenderString(-0.4f, 0.6f, GLUT_BITMAP_TIMES_ROMAN_24,conv);
  converter(arr[90002]);
  RenderString(-0.25f, 0.6f, GLUT_BITMAP_TIMES_ROMAN_24,conv);
  converter(arr[90003]);
  RenderString(-0.1f, 0.6f, GLUT_BITMAP_TIMES_ROMAN_24,conv);
  converter(arr[90004]);
  RenderString(0.05f, 0.6f, GLUT_BITMAP_TIMES_ROMAN_24,conv);
  converter(arr[90005]);
  RenderString(0.2f, 0.6f, GLUT_BITMAP_TIMES_ROMAN_24,conv);
  converter(arr[90006]);
  RenderString(0.35f, 0.6f, GLUT_BITMAP_TIMES_ROMAN_24,conv);
  converter(arr[90007]);
  RenderString(0.5f, 0.6f, GLUT_BITMAP_TIMES_ROMAN_24,conv);
  converter(arr[90008]);
  RenderString(0.65f, 0.6f, GLUT_BITMAP_TIMES_ROMAN_24,conv);

  r=1.0;g=1.0;b=1.0;
  RenderString(-0.55f, 0.3f, GLUT_BITMAP_TIMES_ROMAN_24,"90000");
  RenderString(-0.4f, 0.3f, GLUT_BITMAP_TIMES_ROMAN_24,"90001");
  RenderString(-0.25f, 0.3f, GLUT_BITMAP_TIMES_ROMAN_24,"90002");
  RenderString(-0.1f, 0.3f, GLUT_BITMAP_TIMES_ROMAN_24,"90003");
  RenderString(0.05f, 0.3f, GLUT_BITMAP_TIMES_ROMAN_24,"90004");
  RenderString(0.2f, 0.3f, GLUT_BITMAP_TIMES_ROMAN_24,"90005");
  RenderString(0.35f, 0.3f, GLUT_BITMAP_TIMES_ROMAN_24,"90006");
  RenderString(0.5f, 0.3f, GLUT_BITMAP_TIMES_ROMAN_24,"90007");
  RenderString(0.65f, 0.3f, GLUT_BITMAP_TIMES_ROMAN_24,"90008");


  glColor3f(1.0, 0.0, 0.0);  /* blue */
  glBegin(GL_LINES);
    glVertex2f(-0.55f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
  glEnd();
  glBegin(GL_LINES);
    glVertex2f(-0.4f, 0.5f);
    glVertex2f(-0.35f, 0.5f);
  glEnd();
  glBegin(GL_LINES);
    glVertex2f(-0.25f, 0.5f);
    glVertex2f(-0.2f, 0.5f);
  glEnd();
  glBegin(GL_LINES);
    glVertex2f(-0.1f, 0.5f);
    glVertex2f(-0.05f, 0.5f);
  glEnd();
  glBegin(GL_LINES);
    glVertex2f(0.05f, 0.5f);
    glVertex2f(0.1f, 0.5f);
  glEnd();
  glBegin(GL_LINES);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.25f, 0.5f);
  glEnd();
  glBegin(GL_LINES);
    glVertex2f(0.35f, 0.5f);
    glVertex2f(0.4f, 0.5f);
  glEnd();
  glBegin(GL_LINES);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.55f, 0.5f);
  glEnd();
  glBegin(GL_LINES);
    glVertex2f(0.65f, 0.5f);
    glVertex2f(0.7f, 0.5f);
  glEnd();
  glColor3f(0.0, 0.0, 1.0);  /* blue */
    draw_circle(-0.6f, 0.5f, 0.05f);
    draw_circle(-0.45f, 0.5f, 0.05f);
    draw_circle(-0.3f, 0.5f, 0.05f);
    draw_circle(-0.15f, 0.5f, 0.05f);
    draw_circle(0.0f, 0.5f, 0.05f);
    draw_circle(0.15f, 0.5f, 0.05f);
    draw_circle(0.3f, 0.5f, 0.05f);
    draw_circle(0.45f, 0.5f, 0.05f);
    draw_circle(0.6f, 0.5f, 0.05f);
    draw_circle(0.75f, 0.5f, 0.05f);
  x=query(arr,1,1,ARR_SIZE,90003,90006);
  int pos=rand()%4 + 90003,val=rand()%99 + 1;
  arr[pos]=val;
  update(arr,1,1,ARR_SIZE,pos,val);

  converter(x);
  RenderString(-0.55f, 0.1f, GLUT_BITMAP_TIMES_ROMAN_24,"Shortest link bandwidth (between links 90003 and 90006) - ");
  RenderString(0.65f, 0.1f, GLUT_BITMAP_TIMES_ROMAN_24,conv);
  glFlush();  /* Single buffered, so needs a flush. */

  cout<<"\n"<<"Press any key to continue - ";
  int f;
  cin>>f;
  if(f!=0)
    display();
  else
    endofexec();

}

int main (int argc, char * argv[]) {
    //while(1)
    int i;
    srand (time(NULL));
    for(i=1;i<=ARR_SIZE;i++)
    {
        arr[i] = rand()%99 + 1;
        arr2[i]=arr[i];
    }
    /*
    for(i=1;i<=ARR_SIZE;i++)
    {
        cout<<arr[i]<<"  "<<i<<"\n";
    }
    */
    build(arr,1,1,ARR_SIZE);
    /* initialize GLUT, using any commandline parameters passed to the
       program */
    glutInit(&argc,argv);

    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(2000,2000);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB);

    /* create and set up a window */
    glutCreateWindow("Bandwidth Statistics - Segment Tree");
    glutDisplayFunc(display);

    /* tell GLUT to wait for events */
    glutMainLoop();//}

}