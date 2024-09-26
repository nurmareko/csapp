#include <stdio.h>

// return throughput in giga-instruction per second
void throughput(int clock_cycle)
{
	float result =  ((float) 1 / clock_cycle) * (1000 / 1);
	printf("clock cycle every %d picoseconds\nthroughput %c %.2f GIPS\n\n", clock_cycle, 0xf7, result);
}

int main(void)
{
	throughput(320);
	throughput(120);
	throughput(170);
	throughput(190);
	throughput(130);
	throughput(110);
	throughput(100);

	return 0;
}

