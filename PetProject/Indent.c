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
    
}
void set_after_brace(FILE *fp, FILE *fp1, int c)
{

    int prev = c;
    c = fgetc(fp);
   // printf("%c,%c\n",prev,c);
    int n = 0;
    while ((c == ' ' || c == '\t' || c == '\n') && c != EOF)
    {

       if (c == '\n')
        {
            
            fputc(c, fp1);
            n++;
        }
        prev = c;
        c = fgetc(fp);
       // printf("%c,%c-1\n", prev, c);
    }
    if (c == '}')
    {
        set_before_brace(fp, fp1, prev, c);
        tabs--;
        set_tabs(fp1);
        putc(c, fp1);
      
        set_after_brace(fp, fp1, c);
    }
    if (n == 0)
    {
        fputc('\n', fp1);
    }
    
    if(k==1)
    {
        tabs++;
        k=0;
    }
    set_tabs(fp1);
    if(c!=EOF && c!='{' && c!='}'){
    
    fputc(c, fp1);}
    if(c==EOF )
    {
        // fputc(prev,fp1);
    }
    if (c == '{')
    {
       
        tabs++;
        
        fputc(c,fp1);
        
        set_after_brace(fp, fp1, c);
    }
    

    return;
}
void indentation(FILE *fp, FILE *fp1)
{
    int prev, c;
    prev = fgetc(fp);
    if (prev == '{')
    {
        tabs++;
       
        fputc(prev, fp1);
        set_after_brace(fp, fp1, prev);
    }
    else {
        fputc(prev,fp1);
    }
    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c %c",prev,c);
         if (c == '\n' && (temp1 = fgetc(fp)) != '}' && temp1 != EOF)
        {

            
            fputc(c, fp1);
            set_tabs(fp1);
            //fputc(temp1, fp1);
            prev=c;
            c = temp1;
            printf("%c %c", prev, c);
        }
        else if (c == '\n' && temp1 != EOF && temp1 == '}')
        {

            fputc(c, fp1);
            tabs--;
            set_tabs(fp1);
           // fputc(temp1, fp1);
            set_after_brace(fp, fp1, temp1);
            prev=c;
            c = temp1;
            printf("%c %c", prev, c);
        }

        if (c == '{')
        {
            set_before_brace(fp, fp1, prev, c);
            set_tabs(fp1);
           
            tabs++;
            
            fputc(c, fp1);
            
            set_after_brace(fp, fp1, c);
        }
        else if (c == '}')
        {
          
            set_before_brace(fp, fp1, prev, c);
            
            tabs--;
            set_tabs(fp1);
            
            fputc(c, fp1);
          
            set_after_brace(fp, fp1, c);
        }
        
        
        //else if(c==' '||c=='\t'){}
        else                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    {
    fputc(c, fp1);
    }
    prev = c;
        
}
}
int main(){

    FILE *fp, *fp1;
    fp = fopen("testcase.c", "r");
    fp1 = fopen("output.c", "w");
    indentation(fp, fp1);
}