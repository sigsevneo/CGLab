#include <stdio.h>
#include <graphics.h>

int main()
{
 	int i,gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);

  // Colors the initial set of lines MAGENTA so that they are visible amongst the other colored lines.
	setcolor(MAGENTA);
  setlinestyle(3, 1, 1);

  // Draws the square at the back of the cube
	line(200,200,300,200);
	line(300,200,300,100);
	line(200,200,200,100);
	line(200,100,300,100);

  // Draws the parallelogram below the cube
  line(250,250,350,250);
	line(350,250,350,150);
	line(250,250,250,150);
	line(250,150,350,150);

  // Draws the square at the side of the cube
	line(200,200,250,250);
	line(300,200,350,250);
	line(350,150,300,100);
	line(200,100,250,150);

  // Draws lines that are dotted in nature.
  setlinestyle(1, 0, 1);
	setcolor(LIGHTGREEN);
	for(i=0;i<100;i++)
            line(250+i,150,250+i,250);

	setcolor(YELLOW);
	for(i=0;i<50;i++)
	         line(200+i,100+i,200+i,200+i);

  setcolor(GREEN);
 	for(i=0;i<100;i++)
 	         line(200+i,100,250+i,150);

  setcolor(MAGENTA);
  setlinestyle(0, 1, 1);

   // Draws the square at the back of the cube
 	line(400,200,500,200);
 	line(500,200,500,100);
 	line(400,200,400,100);
 	line(400,100,500,100);

   // Draws the parallelogram below the cube
  line(450,250,550,250);
 	line(550,250,550,150);
 	line(450,250,450,150);
 	line(450,150,550,150);

   // Draws the square at the side of the cube
 	line(400,200,450,250);
 	line(500,200,550,250);
 	line(550,150,500,100);
 	line(400,100,450,150);

  setlinestyle(1, 0, 1);
	setcolor(RED);
	for(i=0;i<100;i++)
            line(400+i,100,400+i,200);

	setcolor(WHITE);
	for(i=0;i<50;i++)
	         line(500+i,100+i,500+i,200+i);

  setcolor(BROWN);
 	for(i=0;i<100;i++)
 	         line(400+i,200,450+i,250);

 	delay(10000);
	closegraph();
  return 0;
}
