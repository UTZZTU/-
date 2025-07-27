#include <stdio.h>
int main ()
{
	int s,n,c[8],i,a,b[8],m,q,r;
	while(scanf("%d%d",&s,&n)!=EOF)
	{
		i=0;
		if(s==0&&n==0)
		break;
		if(n==0)
		{
			printf(" ");
			for(q=1;q<=s;q++)
			{
				printf("-");
			}
			printf(" ");
			printf("\n");
			for(q=1;q<=s;q++)
			{
				printf("|");
				for(r=1;r<=s;r++)
				{
					printf(" ");
				}
				printf("|");
				if(q!=s)
				printf("\n");
			}
			printf("\n");
			printf(" ");
			for(q=1;q<=s;q++)
			{
				printf(" ");
			}
			printf(" ");
			printf("\n");
			for(q=1;q<=s;q++)
			{
				printf("|");
				for(r=1;r<=s;r++)
				{
					printf(" ");
				}
				printf("|");
				if(q!=s)
				printf("\n");
			}
			printf("\n");
			printf(" ");
			for(q=1;q<=s;q++)
			{
				printf("-");
			}
			printf(" ");
			printf("\n");
			printf("\n");
		}
		else
		{
			while(n!=0)
			{
				c[i]=n%10;
				n=n/10;
				i++;
			}
			m=i-1;
			for(a=0;a<i;a++)
			{
				b[a]=c[m];
				m--;
			}
			for(a=0;a<i;a++)
			{
				 if(b[a]==1)
				{
					printf(" ");
					for(q=1;q<=s;q++)
					printf(" ");
					printf(" ");
				}
				else if(b[a]==4)
				{
					printf(" ");
					for(q=1;q<=s;q++)
					{
						printf(" ");
					}
					printf(" ");
				}
				else 
				{
					printf(" ");
					for(q=1;q<=s;q++)
					{
						printf("-");
					}
					printf(" ");
				}
				if(a!=i-1)
				printf(" ");
			}
			printf("\n");
			for(q=1;q<=s;q++)
			{
				for(a=0;a<i;a++)
				{
					if(b[a]==1)
					{
						printf(" ");
						for(r=1;r<=s;r++)
						{
							printf(" ");
						}
						printf("|");
					}
					else if(b[a]==2||b[a]==3||b[a]==7)
					{
						printf(" ");
						for(r=1;r<=s;r++)
						{
							printf(" ");
						}
						printf("|");
					}
					else if(b[a]==5||b[a]==6)
					{
						printf("|");
						for(r=1;r<=s;r++)
						{
							printf(" ");
						}
						printf(" ");
					}
					else 
					{
						printf("|");
						for(r=1;r<=s;r++)
						{
							printf(" ");
						}
						printf("|");
					}
					if(a!=i-1)
					printf(" ");
				}
				if(q!=s)
				printf("\n");
			}
				printf("\n");
				for(a=0;a<i;a++)
			{
				 if(b[a]==1)
				{
					printf(" ");
					for(q=1;q<=s;q++)
					{
						printf(" ");
					}
					printf(" ");
				}
				else if(b[a]==7||b[a]==0)
				{
					printf(" ");
					for(q=1;q<=s;q++)
					{
						printf(" ");
					}
					printf(" ");
				}
				else 
				{
					printf(" ");
					for(q=1;q<=s;q++)
					{
						printf("-");
					}
					printf(" ");
				}
				if(a!=i-1)
				printf(" ");
			}
			printf("\n");
			for(q=1;q<=s;q++)
			{
				for(a=0;a<i;a++)
				{
					if(b[a]==1)
					{
						printf(" ");
						for(r=1;r<=s;r++)
						{
							printf(" ");
						}
						printf("|");
					}
					else if(b[a]==2)
					{
						printf("|");
						for(r=1;r<=s;r++)
						{
							printf(" ");
						}
						printf(" ");
					}
					else if(b[a]==3||b[a]==4||b[a]==5||b[a]==7||b[a]==9)
					{
						printf(" ");
						for(r=1;r<=s;r++)
						{
							printf(" ");
						}
						printf("|");
					}
					else 
					{
						printf("|");
						for(r=1;r<=s;r++)
						{
							printf(" ");
						}
						printf("|");
					}
					if(a!=i-1)
					printf(" ");
				}
				if(q!=s)
				printf("\n");
			}
				printf("\n");
				for(a=0;a<i;a++)
			{
				 if(b[a]==1)
				{
					printf(" ");
					for(q=1;q<=s;q++)
					{
						printf(" ");
					}
					printf(" ");
				}
				else if(b[a]==4||b[a]==7)
				{
					printf(" ");
					for(q=1;q<=s;q++)
					{
						printf(" ");
					}
					printf(" ");
				}
				else 
				{
					printf(" ");
					for(q=1;q<=s;q++)
					{
						printf("-");
					}
					printf(" ");
				}
				if(a!=i-1)
				printf(" ");
			}
			printf("\n");
			printf("\n");
			}
	}
return 0;
}
