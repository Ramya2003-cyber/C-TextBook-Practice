    #include<stdio.h>
    int MAXLINE=5;
    void print_file(char *file)
    {
    FILE *fp;
    fp=fopen(file,"r");
    static int line=1,page=0;
    int c;
    printf("\n-----NEW FILE------\n");
    printf("TITLE:%s\n",file);
    page++;
    printf("\nPage-%d-----------------\n", page);
    while ((c=fgetc(fp))!=EOF)
    {

        if (c == '\n')
            line++;
        if(line%MAXLINE==0)
        {  line++; 
            page++;    
            printf("\nPage-%d\n",page);
        }
        printf("%c",c);
        
    }
    
    }
    int main(int argc,char *argv[])
    {
    while(argc--!=1)
    {
        print_file(*++argv);
    }
    }
