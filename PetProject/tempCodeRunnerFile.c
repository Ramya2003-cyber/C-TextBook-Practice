#include <stdio.h>
int tabs = 0,k=0,temp1;
void set_tabs(FILE *fp1)
{
    for (int i = 0; i < tabs; i++)
    {
        fputc('\t', fp1);
    }
    return;
}
void set_before_brace(FILE *fp, FILE *fp1, int prev, int c)
{
   
   
    if (prev != '\n')
    {
       
        fputc('\n', fp1);
    }
    else
    {
        fseek(fp, -2, 1);
        if ( (fgetc(fp)) != '{' && c == '{')
        {

            k = 1;
            tabs -= 1;
            set_tabs(fp1);
           
        }
        fseek(fp, 1, 1);
    }