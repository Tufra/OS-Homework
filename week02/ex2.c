#include <stdio.h>

int main() {
	
	char str[256];
	int m = 0;
	char c;
	
	while ((c = getc(stdin)) != '\n') {
		if (c == '.') {
			break;
		}
		
		str[m] = c;
		m++;
	}
	
	m--;
	putc('"', stdout);
	while (m >= 0) {
		putc(str[m], stdout);
		m--;
	}
	putc('"', stdout);
}
