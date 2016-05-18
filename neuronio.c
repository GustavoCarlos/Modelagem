#include <stdio.h>
#include <math.h>

int heavSide(float v)
{
	if(v >= 0)
		return 1;
	else
		retunr 0;
}

int main(int argc, const char * argv[])
{

	FILE *neuronData;
	neuronData = fopen("neuronData.txt", "w");

	float dy, dx, dt, x, y, I, p, epsilon, alpha, beta, S;
	
	I = -0.02;
	alpha = 0.5;
	epsilon = 0.02;
	beta = 0.1;
	dt = 0.01;
	x = 0;
	y = 0;

	float i;

	for(i = 0; i < 10.0; i += dt)
	{
		dx = ((3*x) - pow(x,3) + 2 - y + I)*dt;
		dy = (epsilon*(alpha*(1 + tanh(x/beta)) - y))*dt;
		x += dx;
		y += dy;
		
		printf("X: %f Y: %f\r\n", x, y);
		
		fprintf(neuronData, "%f\t%f\n", x, y);

	}

	fclose(neuronData);
}

