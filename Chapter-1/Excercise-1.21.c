#include <stdio.h>

#define MAXLEN 1000
#define N 4 


int  getLine(char [], int);
void entab(char [], char []);


int getLine(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}


void entab(char in[], char out[])
{
	int i; 
	int j; 
	int nblanks; 
	int ntabs; 
	
	for (i = j = 0; in[i] != '\0'; ++i) {
		if (in[i] == ' ') {
			for (nblanks = ntabs = 0; in[i] == ' '; ++i) { 
				if ((i + 1) % N == 0) { 
					++ntabs;
					nblanks = 0;
					//printf("tab\n");
				} else
					++nblanks;
			}
			--i; 
			while (ntabs-- > 0) 
			{
				out[j++]='\t';
			}
				
			while (nblanks-- > 0) 
				out[j++] = ' ';
		} else 
			out[j++] = in[i]; 
	}
	out[j] = '\0';
}

int main(void)
{
	char in[MAXLEN]; 
	char out[MAXLEN]; 

	while (getLine(in, MAXLEN) > 0) {
		entab(in, out);
		printf("%s", out);
	}
	return 0;
}