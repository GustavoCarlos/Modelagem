#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define NUM_NEUR	500
#define T_MAX		20.0


#define I_ativo 0.2
#define I_inativo -0.02

float w[NUM_NEUR][NUM_NEUR];



int heaviSide(float v)
{
	if(v >= 0)
		return 1;
	else
		return 0;
}

void inicilizaVariaveis(float *x, float *y, float *I)
{
	int n, j;
	//Inicializa variaveis
	for(n = 0; n < NUM_NEUR; n++)
	{
		x[n] = (float)(-200 + (rand()%410))/100;
		y[n] = (float)(rand()%410)/100;
		
		if(n > NUM_NEUR/3)
			I[n] = I_ativo;
		else
			I[n] = I_inativo;
		
		for(j = 0; j < NUM_NEUR; j++)
			w[n][j] = 0.0;
	}
}

void inicializaRede()
{
	int a, b;
	FILE *readRede;
	readRede = fopen("proj3Files/graph_BA.txt", "r");

	while(fscanf(readRede, "%d%d", &a, &b) != -1)//!feof(readRede))
	{
		w[a][b] = 0.1;
		printf("Inicializando...");
	}
	
	fclose(readRede);
	

}


int main(int argc, const char * argv[])
{

	FILE *neuronData;
	neuronData = fopen("neuronDataX.txt", "w");

	float dy, dx, dt, p, epsilon, alpha, beta, theta, ro;

	float x[NUM_NEUR], y[NUM_NEUR]/*, w[NUM_NEUR][NUM_NEUR]*/, S[NUM_NEUR], I[NUM_NEUR];
	
	//Parametros do modelo
	//I = -0.02;//I = -0.02;
	theta = 0.5;
	alpha = 6.0;
	epsilon = 0.02;
	beta = 0.1;
	ro = 0;

	dt = 0.01;


	float i;
	int j, n;
	
	//x e y aleatorios x -2 a 2 e y de 0 a 4

	inicilizaVariaveis(x, y, I);
			
	inicializaRede();
	

	for(i = 0; i < T_MAX; i += dt)
	{
		//Calculo do S para cada Neuronio
		for(n = 0; n < NUM_NEUR; n++)
		{		
			S[n] = 0;
			for(j = 0; j < NUM_NEUR; j++)
			{
				if(w[n][j]) //Se neuronio é vizinho
				{
					S[n] += w[n][j]*heaviSide(x[j]-theta);
				}
			}
			
			printf("Neuron: %d S value: %f\n\r", n, S[n]);
		}

		//Realiza calculo para cada neuronio
		for(n = 0; n < NUM_NEUR; n++)
		{
		
			dx = (3*x[n] - pow(x[n],3) + 2 - y[n] + I[n] + ro + S[n])*dt;
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

