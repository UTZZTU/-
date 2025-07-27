#include <stdio.h>
#include <math.h>
int main ()
{
	int a,b,c,t,s,i,r;
    char q[4];
    int w[30];
	w[0]=2;
	for(i=1;i<=27;i++)
	{
		w[i]=w[i-1]*2; 
	 } 
    while(gets(q)!=NULL)
    {
    a=q[0]-'0';
    b=q[1]-'0';
    c=q[3]-'0';
    if(a==0&&b==0&&c==0)
    break;
    else
    {
    	t=(a*10+b)*pow(10,c);
        for(r=0;r<=27;r++)
        	if(w[r]>=t)
        	break;
		if(w[r]==t)
		printf("1\n");
		else
		printf("%d\n",(t-w[r-1])*2+1);
	}
}
	return 0;
 } 
