// Stickman Figurines

#include <stdio.h>
#include <graphics.h>
#include <math.h>

#define PI 3.14159265

// void DDAdraw(int, int, int, int, int);
void BresenhamDrawLine(int, int, int, int, int);
void BresenhamDrawCircle(int, int, int);
void drawCircle(int, int, int, int);
void bhm_line(int, int, int, int, int);
void DrawCircle(int, int, int);

void main()
{
  int x1, y1, x_n, y_n,i;
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");

  //1st figure
  DrawCircle(50,50,25);
  bhm_line(50, 75, 50, 125,10);
  bhm_line(10, 75, 40, 75,10);
  bhm_line(40, 75, 90, 75,10);
  // Hands and body done

  bhm_line(50, 125, 90, 175,10);
  bhm_line(10,175,50,125,10);
  // Legs done

  //2nd figure
  DrawCircle(150,50,25);
  bhm_line(150, 75, 150, 125,10);
  //Body done
  bhm_line(110, 75, 150, 100,10);
  bhm_line(150,100,190,75,10);

  // Hands done

  bhm_line(150, 125, 190, 165,10);
  bhm_line(110,165,150,125,10);
  // Legs done

  //3rdd figure
  DrawCircle(250,50,25);
  bhm_line(250, 75, 250, 125,10);
  //Body done
  bhm_line(210, 100, 250, 75,10);
  bhm_line(250,75,290,100,10);

  // Hands done

  bhm_line(250, 125, 290, 165,10);
  bhm_line(210,165,250,125,10);
  // Legs done


  // getch();

  delay(5000);
}

void BresenhamDrawCircle(int xc, int yc, int r)
{
  int x = 0, y = r;
  int d = 3 - 2 * r;
  while (x < y)
  {
    drawCircle(xc, yc, x, y);
    x++;
    if (d < 0)
        d = d + 4 * x + 6;
    else
      {
          y--;
          d = d + 4 * (x - y) + 10;
      }
        drawCircle(xc, yc, x, y);
        // delay(50);
  }
}
void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc+x, yc+y, RED);
    putpixel(xc-x, yc+y, RED);
    putpixel(xc+x, yc-y, RED);
    putpixel(xc-x, yc-y, RED);
    putpixel(xc+y, yc+x, RED);
    putpixel(xc-y, yc+x, RED);
    putpixel(xc+y, yc-x, RED);
    putpixel(xc-y, yc-x, RED);
}

void DrawCircle(int x0, int y0, int radius)
{
  int x = radius;
  int y = 0;
  int decisionOver2 = 1 - x;   // Decision criterion divided by 2 evaluated at x=r, y=0

  while( y <= x )
  {
    putpixel( x + x0,  y + y0,10); // Octant 1
    putpixel( y + x0,  x + y0,10); // Octant 2
    putpixel(-x + x0,  y + y0,10); // Octant 4
    putpixel(-y + x0,  x + y0,10); // Octant 3
    putpixel(-x + x0, -y + y0,10); // Octant 5
    putpixel(-y + x0, -x + y0,10); // Octant 6
    putpixel( x + x0, -y + y0,10); // Octant 7
    putpixel( y + x0, -x + y0,10); // Octant 8
    y++;
    if (decisionOver2<=0)
    {
      decisionOver2 += 2 * y + 1;   // Change in decision criterion for y -> y+1
    }
    else
    {
      x--;
      decisionOver2 += 2 * (y - x) + 1;   // Change for y -> y+1, x -> x-1
    }
  }
}

// Takes care of all the cases
void bhm_line(int x1,int y1,int x2,int y2,int c)
{
 int x,y,dx,dy,dx1,dy1,px,py,xe,ye,i;
 dx=x2-x1;
 dy=y2-y1;

 dx1=fabs(dx);
 dy1=fabs(dy);

 px=2*dy1-dx1;
 py=2*dx1-dy1;

 if(dy1<=dx1)
 {
    if(dx>=0)
    {
       x=x1;
       y=y1;
       xe=x2;
    }
    else
    {
       x=x2;
       y=y2;
       xe=x1;
    }
    putpixel(x,y,c);
    for(i=0;x<xe;i++)
    {
       x=x+1;
       if(px<0)
       {
         px=px+2*dy1;
       }
       else
       {
          if((dx<0 && dy<0) || (dx>0 && dy>0))
          {
            y=y+1;
          }
          else
          {
            y=y-1;
          }
        px=px+2*(dy1-dx1);
        }
       delay(0);
       putpixel(x,y,c);
    }
 }

 else
 {
    if(dy>=0)
    {
       x=x1;
       y=y1;
       ye=y2;
    }
    else
    {
       x=x2;
       y=y2;
       ye=y1;
    }

    putpixel(x,y,c);
    for(i=0;y<ye;i++)
    {
       y=y+1;
       if(py<=0)
       {
         py=py+2*dx1;
       }
       else
       {
          if((dx<0 && dy<0) || (dx>0 && dy>0))
          {
            x=x+1;
          }
          else
          {
            x=x-1;
          }
          py=py+2*(dx1-dy1);
       }
       delay(0);
       putpixel(x,y,c);
    }
  }
}
