#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int i = INT_MAX;
	unsigned short us = USHRT_MAX;
	long l = LONG_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;

	printf("int: %zu %d \n\r", sizeof(int), i);
	printf("unsigned short: %zu %u \n\r", sizeof(unsigned short), us);
	printf("long: %zu %d \n\r", sizeof(long), l);
	printf("float: %zu %f \n\r", sizeof(float), f);
	printf("double: %zu %f \n\r", sizeof(double), d);
}
