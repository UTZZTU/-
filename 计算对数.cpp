#include<stdio.h>
#include<string.h>
int push(char a[200],char b[100])
{
int i,j,len1,len2,n=0,m=0,p=0;
char s[100][200];
p=0;
for(i=0;i<100;i++)
{
for(j=0;j<200;j++)
 {
 s[i][j]=0;
}
}
len1=strlen(a);
len2=strlen(b);
for(i=len2-1;i>=0;i--)
{
for(j=m,n=len1-1;j<len1+m;j++,n--)
{
s[m][j]=(b[i]-'0')*(a[n]-'0');
 }
 m++;
}
for(i=0;i<m;i++)
{
 for(j=0;j<len1+m;j++)
{
 if(s[i][j]>=10)
{
s[i][j+1]=s[i][j+1]+(s[i][j]/10);
s[i][j]=s[i][j]%10;
 }
}
}
for(i=1;i<len2;i++)
{
for(j=0;j<len1+m;j++)
{
s[i][j]=s[i][j]+s[i-1][j];
 if(s[i][j]>9)
 {
s[i][j]=s[i][j]-10;
s[i][j+1]++;
}
}
}
for(i=len1+m;i>=0;i--)
{
if(s[len2-1][i]!=0)
{
for(j=i;j>=0;j--)
{
a[p]=s[len2-1][j]+'0';
p++;
}
 a[p]='\0';
break;
}
}
return p;
}
int main()
{
char a[200],b[100],c[100];
int i,len,k,l;
char n,m,t;
gets(a);
gets(c);
len=strlen(c);
t=c[0];
strcpy(b,a);
for(i=0;i<=20;i++)
{
if(i==0)
 {
 k=1;
 l=strlen(a);
 n='1';
 m=a[0];
 if((l>len||(l==len&&m>t))&&((k<len)||(k==len&&n<=t)))
 {
 printf("%d\n",i);
 break;
}
}
else
{
k=l;
l=push(a,b);
n=m;
m=a[0];
if((l>len||(l==len&&m>t))&&((k<len)||(k==len&&n<=t)))
{
printf("%d\n",i);
break;
 }
}
}
return 0;
}

