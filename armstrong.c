#include<stdio.h>
int main()
{
   int n1,n2,sum=0,r;

   //printf("\nEnter a number:");
   scanf("%d",&n1);

   n2 = n1;
 
   while (n1 != 0)
   {
      r = n1 % 10;
      sum = sum + (r*r*r);
      n1 = n1 / 10;
   }

   if(n2 == sum)
      printf("YES");
   else
      printf("NO");
   return(0);
}

