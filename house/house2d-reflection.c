#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

void setfillstyle( int pattern, int color);

void drawLine(int X0,int Y0,int X1,int Y1, int color, float scale, float angle)
{
	int dx,dy,Steps,v,a1,b1,a2,b2,p=X0,q=Y0;
	float x,y,Xincrement,Yincrement;

	X0 = (int)X0*scale;
	X1 = (int)X1*scale;
	Y0 = (int)Y0*scale;
	Y1 = (int)Y1*scale;

	a1=p+(X0-p)*cos(angle)-(Y0-q)*sin(angle);
	b1=q+(X0-p)*sin(angle)+(Y0-q)*cos(angle);
	a2=p+(X1-p)*cos(angle)-(Y1-q)*sin(angle);
	b2=q+(X1-p)*sin(angle)+(Y1-q)*cos(angle);
	
	X0 = (int)a1;
	Y0 = (int)b1;
	X1 = (int)a2;
	Y1 = (int)b2;
	
	dx = X1-X0;
	dy = Y1-Y0;
	
	if(dx>dy)
	{
		Steps = abs(dx);
	}
	else
	{
		Steps = abs(dy);
	}
	
	Xincrement = dx / (float)Steps;
	Yincrement = dy / (float)Steps;
	x = X0;
	y = Y0;

	for(v=0;v<Steps;v++)
	{
		putpixel(x,y,color);
		x = (x + Xincrement);
		y = (y + Yincrement);
	}
}


house(int x, int y, int x1, int y1, float angle)
{
	int a1,b1,a2,b2,p=x,q=y;

	a1=p+(x-p)*cos(angle)-(y-q)*sin(angle);
	b1=q+(x-p)*sin(angle)+(y-q)*cos(angle);
	a2=p+(x1-p)*cos(angle)-(y1-q)*sin(angle);
	b2=q+(x1-p)*sin(angle)+(y1-q)*cos(angle);

	x = (int)a1;
	y = (int)b1;
	x1 = (int)a2;
	y1 = (int)b2;

	int points1[]={x,y,x-30,y+30,x+30,y+30,x,y};
	int points2[]={x-20,y+30,x+20,y+30,x+20,y+100,x-20,y+100,x-20,y+30};
	int points3[]={x-5,y+100,x+5,y+100,x+5,y+80,x-5,y+80,x-5,y+100};
	int points4[]={x+10,y+50,x+15,y+50,x+15,y+55,x+10,y+55,x+10,y+50};

	setlinestyle(0,1,1);	// dashedline , thick

	setcolor(LIGHTBLUE);
	fillpoly(4, points1);
	setcolor(BLUE);
	fillpoly(5, points2);
	setcolor(RED);
	fillpoly(5, points3);
	setcolor(YELLOW);
	fillpoly(5, points4);

	// about x=300

	int points5[]={600-x,y,600-x-30,y+30,600-x+30,y+30,600-x,y};
	int points6[]={600-(x-20),y+30,600-(x+20),y+30,600-(x+20),y+100,600-(x-20),y+100,600-(x-20),y+30};
	int points7[]={600-(x-5),y+100,600-(x+5),y+100,600-(x+5),y+80,600-(x-5),y+80,600-(x-5),y+100};
	int points8[]={600-x-10,y+50,600-x-15,y+50,600-x-15,y+55,600-x-10,y+55,600-x-10,y+50};

	setcolor(LIGHTBLUE);
	fillpoly(4, points5);
	setcolor(BLUE);
	fillpoly(5, points6);
	setcolor(RED);
	fillpoly(5, points7);
	setcolor(YELLOW);
	fillpoly(5, points8); 


}
int main()
{
	int gd=DETECT,gm,x=200,y=200;
	int x1=300,y1=200,i;

	initgraph(&gd, &gm, NULL);
	
	cleardevice();
	house(x,y,x1,y1,0);

	delay(5000);

	closegraph();
	return 0;
}