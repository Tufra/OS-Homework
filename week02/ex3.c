#include <stdio.h>
#include <string.h>

void convert(char* str, int from, int to) {
	
	// to decimal
	int mult = 1;
	int i = strlen(str) - 1;
	int dig = 0;
	int sum = 0;
	
	while(i >= 0) {
		dig = str[i] - '0';
		
		// check
		if (dig >= from || dig < 0) {
			printf("cannot convert");
			return;
		}

		sum += mult * dig;
		mult *= from;
		i--;
	}

	char output[64];
	i = 0;
	// to required and print
	while (sum > 0) {
		output[i] = (sum % to) + '0';
		sum /= to;
		i++;
	}
	i--;
	while(i >= 0) {
		putc(output[i], stdout);
		i--;
	}
}

int main() {
	char origin[256];
	int from = 10;
	int to = 10;

	scanf("%s %d %d", origin, &from, &to);

	convert(origin, from, to);
}
