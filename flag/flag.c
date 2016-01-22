// Flag of India

#include <stdio.h>
#include <graphics.h>
#include <math.h>

void DDAdraw(int, int, int, int, int);
void calcPoints(int, int, int, int *, int *);
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
    // DDAdraw(10+i/30,200,10+i/30,200,3);

    setcolor(BLUE);
    circle(300, 110, 30);
  }
  // For the bars of the circle
  // calcPoints(30, 300, 110, x, y);
  int xtop=300,ytop=100;
  int theta;
  for (i = 0; i < 2; i++)
  {
    //  if (i % 2 == 0)
    theta=90 - (i*15);
    line(300,110, xtop+ (30 * sin (theta)) , ytop+ (30 * cos(theta)) );

   }

delay(2000);
  //getch();
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

// For finding the points at 0, 30, 60...360 degrees
// The sine and cosine values are used
void calcPoints(int radius, int midx, int midy, int x[12], int y[12])
{
      // midx= x coordinate of circle
      // midy= y coordinate of circle
      int x1, y1;

      // 90, 270, 0, 180 degrees
      x[0] = midx, y[0] = midy - radius;
      x[6] = midx, y[6] = midy + radius;
      x[3] = midx + radius, y[3] = midy;
      x[9] = midx - radius, y[9] = midy;

      // 30, 150, 210, 330 degrees
      x1 = (int) ((radius / 2) * sqrt(3));
      y1 = (radius / 2);
      x[2] = midx + x1, y[2] = midy - y1;
      x[4] = midx + x1, y[4] = midy + y1;
      x[8] = midx - x1, y[8] = midy + y1;
      x[10] = midx - x1, y[10] = midy - y1;

      // 60, 120, 210, 300 degrees
      x1 = radius / 2;
      y1 = (int) ((radius / 2)  * sqrt(3));
      x[1] = midx + x1, y[1] = midy - y1;
      x[5] = midx + x1, y[5] = midy + y1;
      x[7] = midx - x1, y[7] = midy + y1;
      x[11] = midx - x1, y[11] = midy - y1;

      return ;
}
