// Flag of India
#include <stdio.h>
#include <graphics.h>
void lineDDA(int, int, int, int, int);
void main()
{
  int x1, y1, x_n, y_n,i;
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");

  //For the 3 bars of the flag
  for (i = 0; i < 20; i++) {
    /* code */
    lineDDA(20,20+i,100,20+i,0);
    lineDDA(20,40+i,100,40+i,1);
    lineDDA(20,60+i,100,60+i,2);
    lineDDA(20+i/5,20,20+i/5,200,3);
  }
  //lineDDA(20,20,20,200,3);

  int color = getpixel(25,25);
//  printf("%d\n",color );
  delay(2000);
}
void lineDDA(int x1, int y1, int x_n, int y_n, int k)
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
