#include <stdio.h>
int main ()
{
	int a,b,c,d,e,q1,q2,q3,q4,q5;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	q1=a;q2=b;q3=c;q4=d;q5=e;
	q1=a/3;
	q2+=q1;
	q5+=q1;
	q2=q2/3;
	q1+=q2;
	q3+=q2;
	q3=q3/3;
	q2+=q3;
	q4+=q3;
	q4=q4/3;
	q3+=q4;
	q5+=q4;
	q5=q5/3;
	q4+=q5;
	q1+=q5;
	printf("%d %d %d %d %d",q1,q2,q3,q4,q5);
	return 0;
}
