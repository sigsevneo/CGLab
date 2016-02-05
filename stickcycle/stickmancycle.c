#include<stdio.h>
#include<graphics.h>
#include<math.h>

int main()
{
	int gd=DETECT, gm, i, j, choice;
	float a, b;
	printf("1. Translate the cycle\n2. Rotate the cycle\n3. Scale the cycle\nEnter choice : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1 : initgraph(&gd, &gm, NULL);
			 for(j=0;j<10;j++)
			 {

				line(200+j, 300+j, 300+j, 300+j);
				line(280+j, 200+j, 380+j, 200+j);
				line(200+j, 300+j, 280+j, 200+j);
				line(300+j, 300+j, 380+j, 200+j);
				line(276+j, 180+j, 300+j, 300+j);
				line(400+j, 300+j, 370+j, 150+j);
				line(300+j, 110+j, 276+j, 180+j);
				line(290+j, 125+j, 385+j, 150+j);
				line(290+j, 125+j, 355+j, 150+j);
				line(270+j, 280+j, 276+j, 180+j);
				line(330+j, 260+j, 276+j, 180+j);
				for(i=175;i<290;i++)
				 line(256+j, i+j, 296+j, i+j);

				for(i=145;i<190;i++)
	 			line(355+j, i+j, 385+j, i+j);

				circle(200+j, 300+j, 50);
				circle(400+j, 300+j, 50);
				circle(300+j, 90+j, 20);

				float theta = 2*3.141592*15/260;
				for(i=0;i<20;++i)
      	 			line(200+j,300+j,200+(50*cos(i*theta))+j,j+300+(50*sin(i*theta)));

				for(i=0;i<20;++i)
      	 			line(400+j,300+j,400+(50*cos(i*theta))+j,j+300+(50*sin(i*theta)));
				delay(250);
				cleardevice();
			}
			break;

		case 2 : initgraph(&gd, &gm, NULL);
			 float an = 10*3.141592/180;
			 // Uncomment to take user input for rotation

			//  printf("\nEnter angle:");
			//  scanf("%f",&an);

			  //Display the initial image of the cycle
				line(200, 300, 300, 300);
				line(280, 200, 380, 200);
				line(200, 300, 280, 200);
				line(300, 300, 380, 200);
				line(276, 180, 300, 300);
				line(400, 300, 370, 150);
				line(300, 110, 276, 180);
				line(290, 125, 385, 150);
				line(290, 125, 355, 150);
				line(270, 280, 276, 180);
				line(330, 260, 276, 180);
				for(i=175;i<180;i++)
				 line(256, i, 296, i);

				for(i=145;i<150;i++)
				 line(355, i, 385, i);

				circle(200, 300, 50);
				circle(400, 300, 50);
				circle(300, 90, 20);

				// Display the spokes
				float theta = 2*3.141592*15/260;
				for(i=0;i<20;++i)
     			 	 line(200,300,200+(50*cos(i*theta)),300+(50*sin(i*theta)));

				for(i=0;i<20;++i)
     			 	 line(400,300,400+(50*cos(i*theta)),300+(50*sin(i*theta)));

				delay(1000);
				cleardevice();

				//Display rotated image
			 	 line(200*cos(an)-300*sin(an), 200*sin(an)+300*cos(an), 300*cos(an)-300*sin(an), 300*sin(an)+300*cos(an));
				 line(280*cos(an)-200*sin(an), 280*sin(an)+200*cos(an), 380*cos(an)-200*sin(an), 380*sin(an)+200*cos(an));
				 line(200*cos(an)-300*sin(an), 200*sin(an)+300*cos(an), 280*cos(an)-200*sin(an), 280*sin(an)+200*cos(an));
				 line(300*cos(an)-300*sin(an), 300*sin(an)+300*cos(an), 380*cos(an)-200*sin(an), 380*sin(an)+200*cos(an));
				 line(276*cos(an)-180*sin(an), 276*sin(an)+180*cos(an), 300*cos(an)-300*sin(an), 300*sin(an)+300*cos(an));
				 line(400*cos(an)-300*sin(an), 400*sin(an)+300*cos(an), 370*cos(an)-150*sin(an), 370*sin(an)+150*cos(an));
				 line(200*cos(an)-300*sin(an), 200*sin(an)+300*cos(an), 300*cos(an)-300*sin(an), 300*sin(an)+300*cos(an));
				 line(300*cos(an)-110*sin(an), 300*sin(an)+110*cos(an), 276*cos(an)-180*sin(an), 276*sin(an)+180*cos(an));
				 line(290*cos(an)-125*sin(an), 290*sin(an)+125*cos(an), 385*cos(an)-150*sin(an), 385*sin(an)+150*cos(an));
				 line(290*cos(an)-125*sin(an), 290*sin(an)+125*cos(an), 355*cos(an)-150*sin(an), 355*sin(an)+150*cos(an));
			 	 line(270*cos(an)-280*sin(an), 270*sin(an)+280*cos(an), 276*cos(an)-180*sin(an), 276*sin(an)+180*cos(an));
				 line(330*cos(an)-260*sin(an), 330*sin(an)+260*cos(an), 276*cos(an)-180*sin(an), 276*sin(an)+180*cos(an));

				 // Display spokes
			 for(i=145;i<150;i++)
			  line(256*cos(an)-i*sin(an), 256*sin(an)+i*cos(an), 296*cos(an)-i*sin(an), 296*sin(an)+i*cos(an));

			 for(i=145;i<150;i++)
			  line(355*cos(an)-i*sin(an), 355*sin(an)+i*cos(an), 385*cos(an)-i*sin(an), 385*sin(an)+i*cos(an));

			 circle(200*cos(an)-300*sin(an), 200*sin(an)+300*cos(an), 50);
			 circle(400*cos(an)-300*sin(an), 400*sin(an)+300*cos(an), 50);
			 circle(300*cos(an)-90*sin(an), 300*sin(an)+90*cos(an), 20);

			 for(i=0;i<20;++i)
      	 		  line(200*cos(an)-300*sin(an), 200*sin(an)+300*cos(an),200*cos(an)-300*sin(an)+(50*cos(i*theta)),200*sin(an)+300*cos(an)+(50*sin(i*theta)));

			 for(i=0;i<20;++i)
      	 		  line(400*cos(an)-300*sin(an), 400*sin(an)+300*cos(an),400*cos(an)-300*sin(an)+(50*cos(i*theta)),400*sin(an)+300*cos(an)+(50*sin(i*theta)));
			 break;

			 case 3 : printf("\n1. Zoom in\n2. Zoom out\nEnter choice : ");
					scanf("%d",&choice);
					if(choice==1) a=1.3;
					else a=0.7;
					 initgraph(&gd, &gm, NULL);

					 //Display the initial image of the cycle
					 line(200, 300, 300, 300);
					 line(280, 200, 380, 200);
					 line(200, 300, 280, 200);
					 line(300, 300, 380, 200);
					 line(276, 180, 300, 300);
					 line(400, 300, 370, 150);
					 line(300, 110, 276, 180);
					 line(290, 125, 385, 150);
					 line(290, 125, 355, 150);
					 line(270, 280, 276, 180);
					 line(330, 260, 276, 180);
					 for(i=175;i<180;i++)
						line(256, i, 296, i);

					 for(i=145;i<150;i++)
						line(355, i, 385, i);

					 circle(200, 300, 50);
					 circle(400, 300, 50);
					 circle(300, 90, 20);

					 // Displaying the spokes
					 theta = 2*3.141592*15/260;
					 for(i=0;i<20;++i)
									line(200,300,200+(50*cos(i*theta)),300+(50*sin(i*theta)));

					 for(i=0;i<20;++i)
									line(400,300,400+(50*cos(i*theta)),300+(50*sin(i*theta)));

					 delay(1000);
					 cleardevice();

					 line(200*a, 300*a, 300*a, 300*a);
					 line(280*a, 200*a, 380*a, 200*a);
					 line(200*a, 300*a, 280*a, 200*a);
					 line(300*a, 300*a, 380*a, 200*a);
					 line(276*a, 180*a, 300*a, 300*a);
					 line(400*a, 300*a, 370*a, 150*a);
					 line(300*a, 110*a, 276*a, 180*a);
					 line(290*a, 125*a, 385*a, 150*a);
					 line(290*a, 125*a, 355*a, 150*a);
					 line(270*a, 280*a, 276*a, 180*a);
					 line(330*a, 260*a, 276*a, 180*a);

					 // For drawing the solid boxes
					 for(i=175;i<180;i++)
						line(256*a, i*a, 296*a, i*a);

					 for(i=145;i<150;i++)
						line(355*a, i*a, 385*a, i*a);

					 circle(200*a, 300*a, 50*a);
					 circle(400*a, 300*a, 50*a);
					 circle(300*a, 90*a, 20*a);

					 //For drawing the spokes
					 for(i=0;i<20;++i)
									line(200*a,300*a,200*a+(50*cos(i*theta))*a,300*a+(50*sin(i*theta))*a);

					 for(i=0;i<20;++i)
									line(400*a,300*a,400*a+(50*cos(i*theta))*a,300*a+(50*sin(i*theta))*a);

				 break;

	}
	delay(10000);
	closegraph();
}
