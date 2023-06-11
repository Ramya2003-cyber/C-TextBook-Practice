#include <stdio.h>
int main()
{
    printf("hello, world\n");
    return 0;
}

//leave #
include <stdio.h>
int main()
{
    printf("hello, world\n");
    return 0;
}

//Error:
/*  expected '=', ',', ';', 'asm' or '__attribute__' before '<' token
    9 | include <stdio.h>  */


//leave <> /*
include stdio.h
int main()
{
    printf("hello, world\n");
    return 0;
}
/*ERROR:
error: unknown type name 'include'
   22 | include stdio.h
      | ^~~~~~~
Excercise-1.1.c:22:14: error: expected '=', ',', ';', 'asm' or '__attribute__' before '.' token
   22 | include stdio.h
      |              ^
      */

//Leave preprocessor directory
int main()
{
    printf("hello, world\n");
    return 0;
}

//Implicit decalration of functiin printf

#include <stdio.h>
int main()
{
    printf("hello, world\n");
    return 0;


//Error:expected declaration or statement at end of input

