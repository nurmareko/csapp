#include <stdio.h>

char *getsx(char *s);
void echox(void);

int main(void)
{
	echox();
	return 0;
}

// Implementtion of library function gets()
char *getsx(char *s)
{
	int c;
	char *dest = s;
	while ((c = getchar()) != '\n' && c != EOF)
		*dest++ = c;
	if (c == EOF && dest == s)
		return NULL;
	*dest++ = '\0'; // Terminate string
	return s;
}

// Read input line and write it back
void echox(void) 
{
	char buf[8]; // Way to small!
	getsx(buf);
	puts(buf);
}



