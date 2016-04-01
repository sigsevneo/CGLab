#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

float fact(float n){
    return n <= 1 ? 1 : n * fact(n-1);
}

float coeff(int n, int i, float t)
{
	float nfac = fact(n); 
	
	float bin = nfac/(fact(n-i) * fact(i));
	
	return bin * pow(1-t, n-i) * pow(t,i);
}
 
void bezier (int x[10], int y[10], int n)
{
	
	int i;
	float t;
	float xt, yt;
	float c;

	for (t = 0.0; t < 1.0; t += 0.0005)
	{
		xt = 0;
		yt = 0;
		for(i=0; i<n; i++)
		{
			c = coeff(n-1, i, t);
			xt += c * x[i];
			yt += c * y[i];
		}
		
	putpixel (xt, yt, WHITE);
	}

	for (i=0; i<n; i++)
		putpixel (x[i], y[i], RED);

	
}

int main()
{
	int x[10], y[10];
	int i;
	int n;
	
	printf("Enter number of points: ");
	scanf("%d", &n);

	printf ("Enter %d points:\n", n);
	for (i=0; i<n; i++)
	scanf ("%d%d", &x[i], &y[i]);

	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);

	bezier (x, y, n);
	
	delay(5000);
	closegraph();
	return 0;
}

//*/
	/*
	float xt = coeff(n, 0, t) * x[0] + 3 * t * pow (1-t, 2) * x[1] +
			3 * pow (t, 2) * (1-t) * x[2] + pow (t, 3) * x[3];

	float yt = pow (1-t, 3) * y[0] + 3 * t * pow (1-t, 2) * y[1] +
			3 * pow (t, 2) * (1-t) * y[2] + pow (t, 3) * y[3];
	*/
