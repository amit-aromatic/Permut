// Program to generate all permutations

#include<conio.h>
#include<iostream.h>
#include<stdio.h>


#define MAX1 100

unsigned long fact(unsigned long);
unsigned long sigma_fact_1_to(unsigned long);

void main()
{
 unsigned long a[MAX1];
 unsigned long n,i,j,k,l,m,p,t[MAX1],t2,t3[MAX1][MAX1];
 FILE *fp,*fp2;

 clrscr();
input:
 clrscr();
 cout<<"ENTER AN INTEGER > 0 AND < 11 : ";
 cin>>n;

 if (n<=MAX1 );
 else goto input;


 for(i=0;i<n;i++)
  a[i]=i+1;

 fp=fopen("permut.rtf","w");
 fprintf(fp,"%d ",a[0]);
 fclose(fp);

 for(i=0;i<n-1;i++)
  {

   fp=fopen("permut.rtf","r");
   fp2=fopen("permut2.rtf","w");

      t2=a[i+1];

    for(j=0;j<fact(i+1);j++)
     {
      for(l=0;l<(i+1);l++)
       {
	fscanf(fp,"%d",&t[l]);
       }
	 fscanf(fp,"\n");

      for(p=0;p<(i+2);p++)
       {
	for(l=0,m=0;m<(i+2);)
	 {
	    if(p==m)
	     t3[p][m++]=t2;
	    else t3[p][m++]=t[l++];
	 }
       }

      for(p=0;p<(i+2);p++)
       {
	for(m=0;m<(i+2);m++)
	 fprintf(fp2,"%d ",t3[p][m]);
	fprintf(fp2,"\n");
       }
     }
   fclose(fp);
   fclose(fp2);
   remove("permut.rtf");
   rename("permut2.rtf","permut.rtf");
   clrscr();
   printf("Please Wait...");
   }

clrscr();

cout<<"finish\nSee file \"Permut.rtf\" for output.";
getch();
}

unsigned long fact(unsigned long n)
 {
  unsigned long i,p=1;

  if(p==0) return 1;

  for(i=1;i<=n;i++)
   p*=i;

  return p;
 }

unsigned long sigma_fact_1_to(unsigned long n)
 {
  unsigned long i,p=0;

  for(i=1;i<=n;i++)
   p+=fact(i);

  return p;
 }

