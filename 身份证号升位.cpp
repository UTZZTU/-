#include <stdio.h>
int main ()
{
	int t,i,j,sum,n,q;
	char c[15],w[22];
	scanf("%d",&t);
	getchar();
	for(i=1;i<=t;i++)
	{
		q=1;
		sum=0;
	    gets(c);
		for(j=0;j<6;j++)
		{
			w[q]=c[j];
			q++;
		}
		w[7]='1';
		w[8]='9';
		q=9;
		for(j;j<15;j++)
		{
			w[q]=c[j];
			q++;
		}
		w[q]='\0';
		sum+=(w[1]-'0')*7+(w[2]-'0')*9+(w[3]-'0')*10+(w[4]-'0')*5+(w[5]-'0')*8+(w[6]-'0')*4+(w[7]-'0')*2+(w[8]-'0')*1+(w[9]-'0')*6+(w[10]-'0')*3+(w[11]-'0')*7+(w[12]-'0')*9+(w[13]-'0')*10+(w[14]-'0')*5+(w[15]-'0')*8+(w[16]-'0')*4+(w[17]-'0')*2;
		n=sum%11;
		for(j=1;j<=17;j++)
		{
			printf("%c",w[j]);
		}
		if(n==0)
		printf("1");
		else if(n==1)
		printf("0");
		else if(n==2)
		printf("X");
		else if(n==3)
		printf("9");
		else if(n==4)
		printf("8");
		else if(n==5)
		printf("7");
		else if(n==6)
		printf("6");
		else if(n==7)
		printf("5");
		else if(n==8)
		printf("4");
		else if(n==9)
		printf("3");
		else if(n==10)
		printf("2");
        if(i!=t)
        printf("\n");
}
return 0;
}
