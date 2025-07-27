#include <stdio.h>
int main ()
{
 char c[99];
 gets (c);
 for(int i=0;i<=99;i++)
 {
 	if(c[i]>='A'&&c[i]<='Z')
 	{
 		c[i]=(c[i]+4-'A')%26+'A';
	 }else if(c[i]>='a'&&c[i]<='z')
	 {
	 	c[i]=(c[i]+4-'a')%26+'a';
	 }
 }
 puts(c);
	return 0;
	
	
}
