
#include <stdio.h>

#define IN 1
#define OUT 0
int isQuotationMark(char prev, char c)
{
	return (prev != '\\' && prev != '\'' && c == '\"')||(prev=='/'&&c=='/');
}

int main(void)
{
	int prevC; 
	int c; 
	int comment, quote; 

	comment = quote = OUT;
	prevC = getchar(); 
	while ((c = getchar()) != EOF) { 
		if (isQuotationMark(prevC, c)) {
			if (quote == IN)
				quote = OUT; 
			else if (comment == OUT)
				quote = IN; 
		}
		if (quote == OUT && prevC == '/' && (c == '*'||c=='/'))
			comment = IN; 
		if (comment == OUT)
			putchar(prevC);
		if (comment == IN &&(((prevC == '*' )  && (c == '/'))||c=='\n') ){
			c = getchar(); +
			comment = OUT; 
		}
		prevC = c; 
	}
	putchar(prevC); 
	return 0;
}