#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
	float dy, dx, dt, x, y, I, p, E, a, B, S;
	

	scanf("%f", &dx);
	dy = tanh(dx);

	printf("%f", dy);

}

