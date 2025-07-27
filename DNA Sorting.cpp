#include <stdio.h>

 #include <stdlib.h>

 #include <math.h>

 #include <string.h>

 int 
 main()

 {

     
 int 
 n,m,i,j,k,s[150]= {0};

     
 char 
 str[150][60],p[60];

     
 scanf
 (
 "%d%d"
 ,&n,&m);

     
 for
 (i=0; i<m; i++)

     
 {

         
 scanf
 (
 "%s"
 ,&str[i]);

         
 for
 (j=0; j<n-1; j++)

             
 for
 (k=j+1; k<n; k++)

                 
 if
 (str[i][k]<str[i][j])

                     
 s[i]++;

     
 }

     
 for
 (i=0; i<m-1; i++)

         
 for
 (j=i+1; j<m; j++)

             
 if
 (s[i]>s[j])

             
 {

                 
 strcpy
 (p,str[i]);

                 
 strcpy
 (str[i],str[j]);

                 
 strcpy
 (str[j],p);

                 
 k=s[i];

                 
 s[i]=s[j];

                 
 s[j]=k;

                 
 for
 (k=0; k<60; k++)

                     
 p[k]=0;

             
 }

     
 for
 (i=0; i<m; i++)

         
 printf
 (
 "%s\n"
 ,str[i]);

     
 return 
 0;

 }