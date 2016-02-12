#include <stdio.h>
#include <graphics.h>

int main()
{
     	int i,gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);

	setcolor(CYAN);

	line(200,200,300,200);
	line(300,200,300,100);
	line(200,200,200,100);
	line(200,100,300,100);

	line(250,250,350,250);
	line(350,250,350,150);
	line(250,250,250,150);
	line(250,150,350,150);

	line(200,200,250,250);
	line(300,200,350,250);
	line(350,150,300,100);
	line(200,100,250,150);

	setcolor(10);
	for(i=0;i<100;i++)
            line(250+i,150,250+i,250);

	setcolor(14);
	for(i=0;i<50;i++)
	   line(200+i,100+i,200+i,200+i);

 	delay(10000);
	closegraph();

   return 0;
}
