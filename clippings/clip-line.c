#include <graphics.h>
#include <stdio.h>

struct line
{
	float x1,y1;
	float x2,y2;
};

struct line makeline()
{
	struct line l;
	//Manual entry
	
	printf("Enter x1: ");
	scanf("%f", &l.x1);
	printf("Enter y1: ");
	scanf("%f", &l.y1);
	printf("Enter x2: ");
	scanf("%f", &l.x2);
	printf("Enter y2: ");
	scanf("%f", &l.y2);
	if(l.x1>l.x2)
	{
		float t1, t2;
		t1 = l.x1;
		t2 = l.y1;
		l.x1 = l.x2;
		l.y1 = l.y2;
		l.x2 = t1;
		l.y2 = t2;
	}
	

	//Autoset
	/*
	l.x1 = 120;
	l.y1 = 120;
	l.x2 = 300;
	l.y2 = 400;
	*/
	return l;
}

struct line makebox()
{
	struct line l;
	//Manual entry
	/*
	printf("Enter x1: ");
	scanf("%f", &l.x1);
	printf("Enter y1: ");
	scanf("%f", &l.y1);
	printf("Enter x2: ");
	scanf("%f", &l.x2);
	printf("Enter y2: ");
	scanf("%f", &l.y2);
	*/

	//Autoset
	///*
	l.x1 = 100;
	l.y1 = 100;
	l.x2 = 300;
	l.y2 = 300;
	//*/
	return l;
}

void drawline(struct line l)
{
	line(l.x1, l.y1, l.x2, l.y2);
}

void drawbox(struct line l)
{
	line(l.x1, l.y1, l.x2, l.y1);
	line(l.x1, l.y1, l.x1, l.y2);
	line(l.x1, l.y2, l.x2, l.y2);
	line(l.x2, l.y1, l.x2, l.y2);
}

int inbox(float x1, float y1, struct line b)
{
	if(x1>=b.x1 && x1<=b.x2)
	{
		if(y1>=b.y1 && y1<=b.y2)
		{
			// if(x2>b.x1 && x2<b.x2)
			// {
			// 	if(y2>b.y1 && y2<b.y2)
			// 	{
					return 1;
			// 	}
			// }
		}
	}
	return 0;
}

struct line clipline(struct line l, struct line b)
{
	float m = (l.y2-l.y1)/(l.x2-l.x1);
	float p1,q1,p2,q2;
	float x,y;

	printf("Clipping Line\n");

	//check full line
	if(inbox(l.x1, l.y1, b)==1 && inbox(l.x2, l.y2, b)==1)
	{
			// printf("Inside box\n");
		return l;
	}

	y = ((b.x1-l.x1)/(l.x2-l.x1))*(l.y2-l.y1)+l.y1;
	if((l.y1<=y&&y<=l.y2)||(l.y1>=y&&y>=l.y2))
	{
		if(b.x1>=l.x1 && b.x1<=l.x2)
		{
			l.x1 = b.x1;
			l.y1 = y;
			//printf("Test1\n");
		}
	}

	y = ((b.x2-l.x1)/(l.x2-l.x1))*(l.y2-l.y1)+l.y1;
	if((l.y1<=y&&y<=l.y2)||(l.y1>=y&&y>=l.y2))
	{
		if(b.x2>=l.x1 && b.x1<=l.x2)
		{
			l.x2 = b.x2;
			l.y2 = y;
			//printf("Test2\n");
		}
	}

	x = ((b.y1 - l.y1)/(l.y2 - l.y1))*(l.x2 - l.x1) + l.x1;
	if(l.x1 <= x && l.x2 >= x)
	{
		if((b.y1<=l.y1 && b.y1>=l.y2) || (b.y1>=l.y1 && b.y1<=l.y2))
		{
			if(l.y1 >= l.y2)
			{
				l.x2 = x;
				l.y2 = b.y1;
				//printf("Test3\n");
			}
			else
			{
				l.x1 = x;
				l.y1 = b.y1;
				//printf("Test4\n");
			}
		}
	}

	x = ((b.y2 - l.y1)/(l.y2 - l.y1))*(l.x2 - l.x1) + l.x1;
	if(l.x1 <= x && l.x2 >= x)
	{
		if((b.y2<=l.y1 && b.y2>=l.y2) || (b.y2>=l.y1 && b.y2<=l.y2))
		{
			if(l.y1 >= l.y2)
			{
				l.x1 = x;
				l.y1 = b.y2;
				//printf("Test5\n");
			}
			else
			{
				l.x2 = x;
				l.y2 = b.y2;
			
				//printf("Test6\n");			
			}
		}
	}

	// printf("The end\n");
	
	if(inbox(l.x1, l.y1, b)==0 && inbox(l.x2,l.y2,b)==0)
	{
		l.x1=b.x1;
		l.x2=b.x1;
		l.y1=b.y1;
		l.y2=b.y2;
	}
		

	return l;
}

int main()
{
	

	struct line l;
	struct line b;
	l = makeline();
	b = makebox();
	
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	drawline(l);
	delay(1000);
	drawbox(b);
	delay(1000);
	cleardevice();
	drawbox(b);
	l = clipline(l, b);	
	drawline(l); 


	delay(5000);
	closegraph();
	return 0;
}
