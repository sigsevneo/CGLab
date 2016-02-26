#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  int x1=250,y1=250;
  int x3=x1+100,y3=y1+100;
  int x2=250,y2=350, x9=280, y9=280, x10=320, y10=280;
  int x4=500,y4=320,x5=500,y5=220,x6=450,y6=150,x7=300,y7=180,x8=350,y8=250;
  int x11=280, y11=350, x12=320, y12=350;
  int x[]={0,250,250,350,500,500,450,300,350,280,320,280,320,300,450,400};
  int y[]={0,250,350,350,320,220,150,180,250,280,280,350,350,280,250,265};
  int px[16];
  int py[16];
  px[0]=0;
  py[0]=0;


  setlinestyle(SOLID_LINE,0,1);
  line(x[1],y[1],x[2],y[2]);
  line(x[2],y[2],x[3],y[3]);
  line(x[3],y[3],x[4],y[4]);
  line(x[4],y[4],x[5],y[5]);
  line(x[5],y[5],x[6],y[6]);
  line(x[6],y[6],x[7],y[7]);
  line(x[7],y[7],x[8],y[8]);
  line(x[7],y[7],x[1],y[1]);
  line(x[1],y[1],x[8],y[8]);
  line(x[8],y[8],x[5],y[5]);
  line(x[8],y[8],x[3],y[3]);
  line(x[9],y[9],x[11],y[11]);
  line(x[10],y[10],x[12],y[12]);
  line(x[9],y[9],x[10],y[10]);

  setlinestyle(DOTTED_LINE, 0, 1);
  line(x[7],y[7],x[13],y[13]);
  line(x[2],y[2],x[13],y[13]);
  line(x[13],y[13],x[14],y[14]);
  line(x[6],y[6],x[14],y[14]);
  line(x[14],y[14],x[4],y[4]);
  line(x[3],y[3],x[13],y[13]);

  // Shear values
  float shx,shy;
  printf("\nEnter value of X-shear : ");
  scanf("%f",&shx);
  printf("\nEnter value of Y-shear : ");
  scanf("%f",&shy);

  // Reference Point
  int xdiff=x[2], ydiff=y[2];

  int i;
  for(i=1;i<=15;i++)
  {
     px[i]=x[i]-xdiff;
     py[i]=y[i]-ydiff;
  }



  for(i=1;i<=15;i++)
  {
    px[i]+=(shx*(abs(py[i])));
    py[i]-=(shy*(abs(px[i])));
  }


  for(i=1;i<=15;i++)
  {
    x[i]=px[i]+xdiff;
    y[i]=py[i]+ydiff;
  }

  cleardevice();

  // Begin the modified house
  setlinestyle(SOLID_LINE,0,1);
  line(x[1],y[1],x[2],y[2]);
  line(x[2],y[2],x[3],y[3]);
  line(x[3],y[3],x[4],y[4]);
  line(x[4],y[4],x[5],y[5]);
  line(x[5],y[5],x[6],y[6]);
  line(x[6],y[6],x[7],y[7]);
  line(x[7],y[7],x[8],y[8]);
  line(x[7],y[7],x[1],y[1]);
  line(x[1],y[1],x[8],y[8]);
  line(x[8],y[8],x[5],y[5]);
  line(x[8],y[8],x[3],y[3]);
  line(x[9],y[9],x[11],y[11]);
  line(x[10],y[10],x[12],y[12]);
  line(x[9],y[9],x[10],y[10]);

  // Begin the dotted lined portion
  setlinestyle(DOTTED_LINE, 0, 1);
  line(x[7],y[7],x[13],y[13]);
  line(x[2],y[2],x[13],y[13]);
  line(x[13],y[13],x[14],y[14]);
  line(x[6],y[6],x[14],y[14]);
  line(x[14],y[14],x[4],y[4]);
  line(x[3],y[3],x[13],y[13]);

  delay(5000);
  scanf("%d");
  return 0;
}
