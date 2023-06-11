#include <stdio.h>

#define MAXLEN         1000        
#define LIMIT          79          


int getLine(char [], int);
int skipBlanks(char [], int);
void foldLine(char [], char [], int);
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

int skip_blanks(char str[], int pos)
{
	while (str[pos] == ' ' || str[pos] == '\t')
		++pos;
	return --pos;
}


void fold_line(char line[], char output[], int limit)
{
	int i;               
	int nChar;           
	int lastBlank;       
	int inBlank;	
	nChar = lastBlank = inBlank = 0;
	for (i = 0; line[i] != '\0'; ++i) {
		output[i] = line[i];
		++nChar;

		if (line[i] == ' ' || line[i] == '\t') {
			if (!inBlank)
				lastBlank = i;   
			inBlank = 1;
		} else
			inBlank = 0;

		if (nChar >= limit && lastBlank != 0) { 
			output[lastBlank] = '\n';
			i = lastBlank;
			i = skip_blanks(line, i); 
			nChar = lastBlank = inBlank = 0;
		}
	}
	output[i] = '\0';
}

int main(void)
{
	int  len;                
	char line[MAXLEN];      
	char foldedLine[MAXLE+N];  

	while ((len = getLine(line, MAXLEN)) > 0) {
		if (len > LIMIT) {
			fold_line(line, foldedLine, LIMIT);
			printf("%s", foldedLine);
		} else	
			printf("%s", line);
	}
	return 0;
}