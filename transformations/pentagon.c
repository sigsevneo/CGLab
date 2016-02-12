#include<stdio.h>
#include<graphics.h>

int main()
{
     	int gd=DETECT,gm,choice,z,si,co;


   	printf("Menu:\n1.Transformation\n2.Scaling\n3.Rotation\n Enter your choice    ");
	scanf("%d",&choice);
  
	

 	switch(choice)
	{
	   case 1:
 
		initgraph(&gd,&gm,NULL);
		
		setcolor(CYAN);

		line(200,100,105,169);
		line(105,169,141,281);
	 	line(141,281,259,281);
		line(259,281,295,169);
		line(295,169,200,100);

		delay(1000);
		cleardevice();
		
 		for(si=0;si<=50;si+=10)
		{
			cleardevice();
			line(200+si,100+si,105+si,169+si);
			line(105+si,169+si,141+si,281+si);
		 	line(141+si,281+si,259+si,281+si);
			line(259+si,281+si,295+si,169+si);
			line(295+si,169+si,200+si,100+si);
			delay(500);

			
  		}
	 	delay(5000);
		closegraph();

		break;

	
           case 2:
 
		printf("\n\n1.Zoom in\n2.Zoom out\n Choice   ");
		scanf("%d",&z);

		if(z==1)
 		{
		
			initgraph(&gd,&gm,NULL);
		
			setcolor(CYAN);

			line(200,100,105,169);
			line(105,169,141,281);
		 	line(141,281,259,281);
			line(259,281,295,169);
			line(295,169,200,100);


			 delay(1000);
			cleardevice();
		
			line(200,50,57,154);
			line(57,154,112,321);
		 	line(112,321,288,321);
			line(288,321,343,154);
			line(343,154,200,50);

		 	delay(5000);
			closegraph();

			break;
                 }

		if(z==2)
 		{
			initgraph(&gd,&gm,NULL);
		
			setcolor(CYAN);

			line(200,100,105,169);
			line(105,169,141,281);
		 	line(141,281,259,281);
			line(259,281,295,169);
			line(295,169,200,100);


			 delay(1000);
			cleardevice();
		
			line(200,150,152,185);
			line(152,185,171,240);
		 	line(171,240,229,240);
			line(229,240,248,185);
			line(248,185,200,150);

		 	delay(5000);
			closegraph();

			break;
                 }   

		break;

	   
	   case 3:
 
		initgraph(&gd,&gm,NULL);
		
		setcolor(CYAN);

		line(200,100,105,169);
		line(105,169,141,281);
	 	line(141,281,259,281);
		line(259,281,295,169);
		line(295,169,200,100);

		delay(1000);
		cleardevice();
		
		line(200*cos(15*3.1414/180)-100*sin(15*3.1414/180),200*sin(15*3.1414/180)+100*cos(15*3.1414/180),105*cos(15*3.1414/180)-169*sin(15*3.1414/180),105*sin(15*3.1414/180)+169*cos(15*3.1414/180));
			
			line(105*cos(15*3.1414/180)-169*sin(15*3.1414/180),105*sin(15*3.1414/180)+169*cos(15*3.1414/180),141*cos(15*3.1414/180)-281*sin(15*3.1414/180),141*sin(15*3.1414/180)+281*cos(15*3.1414/180));

		 	line(141*cos(15*3.1414/180)-281*sin(15*3.1414/180),141*sin(15*3.1414/180)+281*cos(15*3.1414/180),259*cos(15*3.1414/180)-281*sin(15*3.1414/180),259*sin(15*3.1414/180)+281*cos(15*3.1414/180));

			line(259*cos(15*3.1414/180)-281*sin(15*3.1414/180),259*sin(15*3.1414/180)+281*cos(15*3.1414/180),295*cos(15*3.1414/180)-169*sin(15*3.1414/180),295*sin(15*3.1414/180)+169*cos(15*3.1414/180));

			line(295*cos(15*3.1414/180)-169*sin(15*3.1414/180),295*sin(15*3.1414/180)+169*cos(15*3.1414/180),200*cos(15*3.1414/180)-100*sin(15*3.1414/180),200*sin(15*3.1414/180)+100*cos(15*3.1414/180));

	 	delay(5000);
		closegraph();

		break;

	  default: printf("Invalid choice\n"); 
	}

   return 0;
}
