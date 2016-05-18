#include <stdio.h>
#include <math.h>

#define NUM_NEUR	6
#define T_MAX		1

int heavSide(float v)
{
	if(v >= 0)
		return 1;
	else
		return 0;
}

int main(int argc, const char * argv[])
{

	FILE *neuronData;
	neuronData = fopen("neuronDataX.txt", "w");

	float dy, dx, dt, I, p, epsilon, alpha, beta, theta, ro, S;

	float x[NUM_NEUR], y[NUM_NEUR], w[NUM_NEUR][NUM_NEUR];
	
	//Parametros do modelo
	I = -0.2;//I = -0.02;
	theta = 0.5;
	alpha = 0.5;
	epsilon = 0.02;
	beta = 0.1;
	ro = 0;

	dt = 0.01;
	x[0] = 0;
	y[0] = 0;

	float i;
	int j, n;

	//Inicializa variaveis
	for(n = 0; n < NUM_NEUR; n++)
	{
		x[n] = 0;
		y[n] = 0;
		for(j = 0; j < NUM_NEUR; j++)
			w[n][j] = 0;
	}

	w[0][1] = 0.1;
	w[1][0] = 0.1;

	w[1][2] = 0.1;
	w[2][1] = 0.1;



	for(i = 0; i < T_MAX; i += dt)
	{

		for(n = 0; n < NUM_NEUR; n++)
		{

			//Calculo do S para cada Neuronio		
			S = 0;
			for(j = 0; j < NUM_NEUR; j++)
			{
				if(w[n][j]) //Se neuronio é vizinho
				{
					S += w[n][j]*heavSide(x[j]-theta);
				}
			}
			
			printf("Neuron: %d S value: %f\n\r", n, S);
		
			dx = (3*x[n] - pow(x[n],3) + 2 - y[n] + I + ro + S)*dt;
			dy = (epsilon*(alpha*(1 + tanh(x[n]/beta)) - y[n]))*dt;
			x[n] += dx;
			y[n] += dy;
		
			printf("X: %f Y: %f\r\n", x[0], y[0]);
		
			fprintf(neuronData, "%f\t", x[n]);
		}
		fprintf(neuronData, "\n");
	}

	fclose(neuronData);
}

