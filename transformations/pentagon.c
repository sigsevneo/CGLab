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

        		printf("\n\n1.X-axis scale\n2.Y-axis scale\nEnter your choices:   ");
        		int z1,z2;

            scanf("%d",&z1);  // For specific X-scaling
            scanf("%d",&z2);  // For specific Y-scaling


        			initgraph(&gd,&gm,NULL);

        			setcolor(CYAN);

        			line(200,100,105,169);
        			line(105,169,141,281);
        		 	line(141,281,259,281);
        			line(259,281,295,169);
        			line(295,169,200,100);


        			delay(1000);
        			cleardevice();

        			line(200*z1,50*z2,57*z1,154*z2);
        			line(57*z1,154*z2,112*z1,321*z2);
        		 	line(112*z1,321*z2,288*z1,321*z2);
        			line(288*z1,321*z2,343*z1,154*z2);
        			line(343*z1,154*z2,200*z1,50*z2);

        		 	delay(5000);
        			closegraph();

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
