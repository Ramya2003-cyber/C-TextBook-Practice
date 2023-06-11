#include<stdio.h>
void remove_comments(FILE *fp,FILE *fp1)
{
  
    int prev,c;
    printf("hello\n");
    while((c = fgetc(fp))!=EOF)
    {
        if(c=='\''|| c=='\"')
        {
            fputc(c, fp1);
            while((c=fgetc(fp))!='\'')
            fputc(c, fp1);
            //fputc(c,fp1);
        }
        
          if(c=='/')
        {
            prev=c;
            if((c=fgetc(fp))=='/')
            {
                prev=c;
                while((c=fgetc(fp))!='\n' && c!=EOF)
                {     
                    prev=c;              
                }
                fputc('\n',fp1);
            }
            else if(c=='*')
            {
                while(!((c=fgetc(fp))=='*' && (c=fgetc(fp))=='/') && c!=EOF)
                {
                }
                
            }
            else if(c==EOF)
            {
                break;
            }
            else{
                fputc(c, fp1);
            }
        }
        else 
        {
            printf("%c\n", c);
            fputc(c,fp1);
        }
        prev=c;
    }
    if(c==EOF)
    {
        printf("EOF");
    }
}
int main()
{
    FILE *fp,*fp1;
    fp=fopen("testcase1.txt","r");
    fp1=fopen("output.txt","w");
    remove_comments(fp,fp1);
}