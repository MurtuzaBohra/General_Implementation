/*
program will take side margines and file as input and will show the formatted text in terminal as output, INDEPENDENT OF WINDOW SIZE OF TERMINAL
*/
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

void print_on_screen(char string[],int c_s,int c,int size,int left_margin)
 {
   int n=1,j,i,t=c-c_s;

   for(j=0;j<left_margin;j++)
    printf(" ");

   while(t>0)
   {
     n++;
     t=t-c_s;
   }
   t=t+c_s;
 
   for(i=0;size>0;i++)
    {
      if(string[i]==' ')
       {  
        
        for(j=0;j<n;j++)
         {
		   printf(" ");
		   size--;
		 }
        if(t>0)
         {
           printf(" ");
           t--;
           size--;
         }
       }
      else
        {
         printf("%c",string[i]);
         size--;
        }
    }
  printf("\n");
 }


void que2(int size_of_line, char nm[],int left_margin)
 {
   int count_space,count,i=0;
   char a,temp[15],string[size_of_line];
   std::fstream f;
   f.open(nm);

   while(!f.eof())
   {
     count_space=0;
     for(;i<size_of_line;i++)
      {
        if(!f.eof())
        {
         a=f.get();
         string[i]=a;
         
         if(a==' ')
           count_space++;
        }
       else
        break;
      }

     a=f.get();
    
     if(a==' ' || f.eof())
      {
        if(a==' ')
        {
         print_on_screen(string,count_space,0,size_of_line,left_margin);
         i=0;
        }
        else
        {
          count=size_of_line - i;
          print_on_screen(string,count_space,count,size_of_line,left_margin);
        }
      }
     else
      {
        count=1;
        for(;string[i-1]!=' ';i--)
         {
           count++;
           temp[count-2]=string[i-1];
         }
        print_on_screen(string,count_space,count,size_of_line,left_margin);
        for(i=0;i<count-1;i++)
         string[i]=temp[count-2-i];
        string[i]=a;

        i=count-1;
       }
     }
    f.close();
 }




char aaa()
{

	char buf[8];
	char cmd[]="echo -e '\033[6n'";
	struct termios save,raw;
	tcgetattr(0,&save);
	cfmakeraw(&raw); tcsetattr(0,TCSANOW,&raw);
	if (isatty(fileno(stdin))) 
	{
		write(1,cmd,sizeof(cmd));
		read (0 ,buf ,sizeof(buf));

		/* It doesn't work!!?
		sscanf(buf,"%d",curline);
		printf("\n\rCurrent Line: %d\n\r" , curline);
		

		printf("\n\rCurrent Line: %c%c\n\r" , buf[2] ,buf[3] );*/
	}
	tcsetattr(0,TCSANOW,&save);
	return buf[2];
}

int aaaa()
{
  char a;
  int count=1;
  int i,q=1;
 system("clear");
while(q)
 {
  for(i=1;i<=count;i++)
   printf(" ");
  printf("\n");
  a=aaa();
  printf("%d\n",a);
  if(a>'2')
   q=0;
  else
   count++;
  system("clear");
 }
return(count);
}



int main()
{
 char nm[20];
 int n,left_margin,right_margin,size_of_line;
 n=aaaa();
 
 /*printf("%d \n",n);*/
 printf("enter left magine  and right margin of winidow\n");
 scanf("%d%d",&left_margin,&right_margin);
 
 size_of_line = n-left_margin-right_margin;
 
 printf("enter the name of the file to be operated \n");
 scanf("%s",nm);
 
 que2(size_of_line,nm,left_margin);

}
