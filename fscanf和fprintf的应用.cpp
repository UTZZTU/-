#include <stdio.h>
#include <stdlib.h>
int main ()
{
	FILE*fp;
	float total=0,price,p[3]={12.3,45.6,78.9};
	int i,num,n[3]={10,20,30};
	if((fp=fopen("list.dat","w"))==NULL)
	{
		printf("Can,t open file!\n");
		exit(0);
	}
	for(i=0;i<3;i++)
	{
		fprintf(fp,"%5.2f,%d\n",p[i],n[i]);
		total+=p[i]*n[i];
	}
	fprintf(fp,"总金额=%f\n",total);
	fclose(fp);
	if((fp=fopen("list.dat","r"))==NULL)
	{
		printf("Can,t open file!\n");
		exit(0);
	}
	for(i=0;i<3;i++)
	{
		fscanf(fp,"%f,%d",&price,&num);
		printf("%f,%3d\n",price,num);
	}
	fscanf(fp,"总金额=%f",&total);
	printf("总金额=%8.2f\n",total);
	fclose(fp);
}
