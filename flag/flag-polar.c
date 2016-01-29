// Flag of India

// DDA for Line
// Polar Based Algo for Circle

#include <stdio.h>
#include <graphics.h>
#include <math.h>

#define PI 3.14159265

void DDAdraw(int, int, int, int, int);
void CirclePolar(int, int, int);

void main()
{
  int x1, y1, x_n, y_n,i;
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");
  int x[12],y[12];

  //For the 3 bars of the flag
  for (i = 0; i < 60; i++) {
    /* code */
    DDAdraw(100,20+i,500,20+i,0);
    DDAdraw(100,80+i,500,80+i,1);
    DDAdraw(100,140+i,500,140+i,2);

    setcolor(BLUE);
//    circle(300, 110, 30);
    CirclePolar(300,110,30);

  }
  // For the bars of the circle
  int xtop=300,ytop=110; // Center coordinates
  float theta, val;
  val = PI / 180.0;     // Needed to for PI and Radian conversion

  for (i = 0; i < 24; i++)
  {
    theta=360.0 - (i*15);
    line(xtop,ytop, xtop+ (30 * sin (theta * val)) , ytop+ (30 * cos(theta * val)) );
  }



  getch();

}
void drawPoints(int xc,int yc, int a, int b)
{
       putpixel( xc+a, yc+b, BLUE);
       putpixel( xc-a, yc+b, BLUE);
       putpixel( xc-a, yc-b, BLUE);
       putpixel( xc+a, yc-b, BLUE);
       putpixel( xc+b, yc+a, BLUE);
       putpixel( xc-b, yc+a, BLUE);
       putpixel( xc-b, yc-a, BLUE);
       putpixel( xc+b, yc-a, BLUE);
}

void CirclePolar(int xc,int yc, int R)
 {
     int x=R,y=0;
     double theta=0,dtheta=1.0/R;
     drawPoints(xc,yc,x,y );
     while(x>y)
     {
       theta+=dtheta;
       x=round(R*cos(theta));
       y=round(R*sin(theta));
       drawPoints(xc,yc,x,y);
     }
 }

void DDAdraw(int x1, int y1, int x_n, int y_n, int k)
{
  int dx, dy, m, i;

  // For drawing lines with slope < 1
  if(x1!=x_n)
  {
    m = (y_n-y1)/(x_n-x1);
    for (i=x1; i<=x_n; i++)
    {
      if (m <= 1)
      {
        dx = 1;
        dy = m * dx;
      }
      else
      {
        dy = 1;
        dx = dy / m;
      }
      x1 = x1 + dx;
      y1 = y1 + dy;

      putpixel(x1, y1, k==0?LIGHTRED:(k==1?WHITE:(k==2?GREEN:YELLOW)));
    }
  }
  // For drawing lines with slope > 1
  else
  {
    m = (x_n-x1)/(y_n-y1);
    for (i=y1; i<=y_n; i++)
    {
      if (m <= 1)
      {
        dy = 1;
        dx = m * dy;
      }
      else
      {
        dx = 1;
        dy = dx / m;
      }
      x1 = x1 + dx;
      y1 = y1 + dy;

      putpixel(x1, y1, k==0?LIGHTRED:(k==1?WHITE:(k==2?GREEN:YELLOW)));
    }
  }
}
