#include <stdio.h>

#define YES                    1
#define NO                     0  

/* globals */
int leftParens = 0;
int rightParens = 0;
int leftBrackets = 0;
int rightBrackets = 0;
int leftBraces = 0;
int rightBraces = 0;

/* functions */
void printInfo();
int  skipChar(int);
void checkSymbolsBallance(void);
void countSymbols(void);
int  skipComment(int);
int  skipQuote(int);

/* skipChar: skips n characters in the input stream */
int skipChar(int n)
{
	int c;

	while (n--)
		c = getchar();
	return c ;
}

/* skipComment: skip characters in the input stream until encountered the
 * ending symbol of a c-style comment */
int skipComment(int c)
{
	int stop = NO;

	while (stop == NO && (c = getchar()) != EOF)
		if (c == '*' && (c = getchar()) == '/')
			stop = YES;
	return c;
}

/* skipComment: skip characters in the input stream until encountered the
 * ending character of a c-style quote (single or double) */
int skipQuote(int type)
{
	int c, stop = NO, step = 2;

	while (stop == NO && (c = getchar()) != EOF) {
		if (c == '\\')
			c = skipChar(step);
		if (c == type)
			stop = YES;
	}
	return c;
}


void countSymbols(void) {
	extern int leftParens, rightParens, leftBrackets, rightBrackets,
		       leftBraces, rightBraces;
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '/' && (c = getchar()) == '*') /* skip comments */
			c = skipComment(c);
		if (c == '"')  /* skip double quotes */
			c = skipQuote(c);
		if (c == '\'') /* slip single quotes */
			c = skipQuote(c);
		if (c == '(')
			++leftParens;
		if (c == ')')
			++rightParens;
		if (c == '[')
			++leftBrackets;
		if (c == ']')
			++rightBrackets;
		if (c == '{')
			++leftBraces;
		if (c == '}')
			++rightBraces;
	}
}

/* checkSymbolsBallance: check if number of c-style demarcating symbols for
 * comments and quotes are balanced. Print an error message if not. */
void checkSymbolsBallance(void)
{
	extern int leftParens, rightParens, leftBrackets, rightBrackets,
		       leftBraces, rightBraces;

	if (leftParens - rightParens < 0)
		printf("Error: missing '('\n");
	else if (leftParens - rightParens > 0)
		printf("Error: missing ')'\n");
	if (leftBrackets - rightBrackets < 0)
		printf("Error: missing '['\n");
	else if (leftBrackets - rightBrackets > 0)
		printf("Error: missing ']'\n");
	if (leftBraces - rightBraces < 0)
		printf("Error missing '{'\n");
	else if (leftBraces - rightBraces > 0)
		printf("Error missing '}'\n");
}

void printInfo(void)
{
	extern int leftParens, rightParens, leftBrackets, rightBrackets,
		       leftBraces, rightBraces;

	printf("'(': %i ')': %i Total: %i\n",
			leftParens, rightParens, leftParens + rightParens);
	printf("'[': %i ']': %i Total: %i\n",
			leftBrackets, rightBrackets, leftBrackets + rightBrackets);
	printf("'{': %i '}': %i Total: %i\n",
			leftBraces, rightBraces, leftBraces + rightBraces);
}

int main(void)
{
	countSymbols();
	printInfo();
	checkSymbolsBallance();
	return 0;
}