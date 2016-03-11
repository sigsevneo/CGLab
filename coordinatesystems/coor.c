#include <stdio.h>
#include <graphics.h>

int main()
{
	int gd=DETECT,gm;

	int i, j;
	float sx=1.0, sy=1.0;
	int x=50, y=50, x1, y1, x2, y2, x3, y3, x4, y4, w=50, h=50;
	int body[]={x+w, y+h, x+w*3,y+h, x+w*3,y+h*3,x+w, y+h*3,x+w, y+h};
	int door[]={x+w*1.5, y+h*2, x+w*2.5,y+h*2, x+w*2.5,y+h*3,x+w*1.5, y+h*3,x+w*1.5, y+h*2};
	int top[]={x+w,y+h,x+w*3,y+h,x+w*2,y,x+w,y+h};
	int newwindow[]={x+w/2, y+h/2, x+w*2,y+h/2, x+w*2,y+h*2,x+w/2, y+h*2,x+w/2, y+h/2};
	x1=20; y1=20;
	x2=220; y2=220;

	x3=50; y3=50;
	x4=150; y4=150;
	int world[]={x1,y1,x2,y1,x2,y2,x1,y2,x1,y1};


	initgraph(&gd, &gm, NULL);

	drawpoly(5,door);
	drawpoly(5,world);
	drawpoly(5,body);
	drawpoly(4,top);
	drawpoly(5,newwindow);

	for(i=0;i<10;i=i+2)
	{
		door[i]-=x1;
		world[i]-=x1;
		body[i]-=x1;
		newwindow[i]-=x1;
		if(i<8)
			top[i]-=x1;
	}

	for(i=1;i<10;i=i+2)
	{
		door[i]-=y1;
		world[i]-=y1;
		body[i]-=y1;
		newwindow[i]-=y1;
		if(i<8)
			top[i]-=y1;
	}
	delay(1000);
	cleardevice();

	drawpoly(5,door);
	drawpoly(5,world);
	drawpoly(5,body);
	drawpoly(4,top);
	drawpoly(5,newwindow);

	sx=(float)(x4-x3)/(x2-x1);
	sy=(float)(y4-y3)/(y2-y1);

	for(i=0;i<10;i=i+2)
	{
		door[i]*=sx;
		world[i]*=sx;
		body[i]*=sx;
		newwindow[i]*=sx;
		if(i<8)
			top[i]*=sx;
	}
	for(i=1;i<10;i=i+2)
	{
		door[i]*=sy;
		world[i]*=sy;
		body[i]*=sy;
		newwindow[i]*=sy;
		if(i<8)
			top[i]*=sy;
	}

	delay(1000);
	cleardevice();

	drawpoly(5,door);
	drawpoly(5,world);
	drawpoly(5,body);
	drawpoly(4,top);
	drawpoly(5,newwindow);


	for(i=0;i<10;i=i+2)
	{
		door[i]+=x3;
		world[i]+=x3;
		body[i]+=x3;
		newwindow[i]+=x3;
		if(i<8)
			top[i]+=x3;
	}

	for(i=1;i<10;i=i+2)
	{
		door[i]+=y3;
		world[i]+=y3;
		body[i]+=y3;
		newwindow[i]+=y3;
		if(i<8)
			top[i]+=y3;
	}

	delay(1000);
	cleardevice();

	drawpoly(5,door);
	drawpoly(5,world);
	drawpoly(5,body);
	drawpoly(4,top);
	drawpoly(5,newwindow);
	delay(1000);
	closegraph();
	return 0;
}
