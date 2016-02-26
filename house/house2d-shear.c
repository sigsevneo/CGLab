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
	int a1,b1,a2,b2,p=x,q=y,i;

	a1=p+(x-p)*cos(angle)-(y-q)*sin(angle);
	b1=q+(x-p)*sin(angle)+(y-q)*cos(angle);
	a2=p+(x1-p)*cos(angle)-(y1-q)*sin(angle);
	b2=q+(x1-p)*sin(angle)+(y1-q)*cos(angle);

	x = (int)a1;
	y = (int)b1;
	x1 = (int)a2;
	y1 = (int)b2;

	int points1[]={x,y,x-70,y+70,x+70,y+70,x,y};
	int points2[]={x-60,y+70,x-60,y+150,x+60,y+150,x+60,y+70,x-60,y+70};
	int points3[]={x-10,y+150,x+10,y+150,x+10,y+120,x-10,y+120,x-10,y+150};
	int points4[]={x+30,y+100,x+40,y+100,x+40,y+90,x+30,y+90,x+30,y+100};

	setlinestyle(0,1,1);	// dashedline , thick

/*	setcolor(LIGHTBLUE);
	fillpoly(4, points1);
	setcolor(BLUE);
	fillpoly(5, points2);
	setcolor(RED);
	fillpoly(5, points3);
	setcolor(YELLOW);
	fillpoly(5, points4);
*/

	for(i=0;i<4;i++)
	{
		points1[2*i]+=0.3*points1[2*i+1];
	}
	for(i=0;i<5;i++)
	{
		points2[2*i]+=0.3*points2[2*i+1];
	}
	for(i=0;i<5;i++)
	{
		points3[2*i]+=0.3*points3[2*i+1];
	}
	for(i=0;i<5;i++)
	{
		points4[2*i]+=0.3*points4[2*i+1];
	}


	setlinestyle(0,1,1);	// dashedline , thick

	setcolor(LIGHTBLUE);
	fillpoly(4, points1);
	setcolor(BLUE);
	fillpoly(5, points2);
	setcolor(RED);
	fillpoly(5, points3);
	setcolor(YELLOW);
	fillpoly(5, points4);

}


int main()
{
	int gd=DETECT,gm,x=200,y=200;
	int x1=300,y1=200,i;

	initgraph(&gd, &gm, NULL);
	
	cleardevice();


	//for(i=0;i<10;i++)
	//{
		cleardevice();
		house(x,y,x1,y1,0);
		delay(100);
	//}

	delay(5000);

	closegraph();
	return 0;
}