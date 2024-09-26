#include <stdio.h>

#define SIZE 8

void good_echo(void);

int main(void) {
	good_echo();
	return 0;
}

void good_echo(void) {
	char buf[SIZE];
	if (fgets(buf, SIZE, stdin) != NULL)
		puts(buf);
	else 
		return;
}

