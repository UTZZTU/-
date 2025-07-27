#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct A
{
	char pnumber[4];
	char cnumber[20];
	int hour,min;
	struct A *next;
};
struct B
{
	char pnumber[4];
	char cnumber[20];
	int hour,min;
	struct B *next;
};
struct C
{
	char pnumber[4];
	char cnumber[20];
	int hour,min;
	struct C *next;
};
#define LENA sizeof(struct A)
#define LENB sizeof(struct B)
#define LENC sizeof(struct C)
struct A *creatA(void)
{
	struct A *p1=NULL,*p2=NULL;
	struct A *head=NULL;
	int i;
	for(i=1;i<=20;i++)
	{
		p1=(struct A*)malloc(LENA);
		p1->pnumber[0]='A';
		if(i<=9)
		{
			p1->pnumber[1]='0';
			p1->pnumber[2]=i+48;
		}
		else  if(i!=20)
		{
			p1->pnumber[1]='1';
			p1->pnumber[2]=i%10+48;
		}
		else
		{
			p1->pnumber[1]='2';
			p1->pnumber[2]='0';
		}
		p1->pnumber[3]='\0';
	    p1->cnumber[0]='0'; 
		if(head==NULL)
		{
			head=p1;
		}
		else  p2->next=p1;
		p2=p1;
	}
	p2->next=NULL;
	return head;
}
struct B *creatB(void)
{
	struct B *p1=NULL,*p2=NULL;
	struct B *head=NULL;
	int i;
	for(i=1;i<=15;i++)
	{
		p1=(struct B*)malloc(LENB);
		p1->pnumber[0]='B';
		if(i<=9)
		{
			p1->pnumber[1]='0';
			p1->pnumber[2]=i+48;
		}
		else  
		{
			p1->pnumber[1]='1';
			p1->pnumber[2]=i%10+48;
		}
		p1->pnumber[3]='\0';
		p1->cnumber[0]='0'; 
		if(head==NULL)
		{
			head=p1;
		}
		else  p2->next=p1;
		p2=p1;
	}
	p2->next=NULL;
	return head;
}
struct C *creatC(void)
{
	struct C *p1=NULL,*p2=NULL;
	struct C *head=NULL;
	int i;
	for(i=1;i<=10;i++)
	{
		p1=(struct C*)malloc(LENC);
		p1->pnumber[0]='C';
		if(i<=9)
		{
			p1->pnumber[1]='0';
			p1->pnumber[2]=i+48;
		}
		else  
		{
			p1->pnumber[1]='1';
			p1->pnumber[2]='0';
		}
		p1->pnumber[3]='\0';
		p1->cnumber[0]='0'; 
		if(head==NULL)
		{
			head=p1;
		}
		else  p2->next=p1;
		p2=p1;
	}
	p2->next=NULL;
	return head;
}
int main ()
{
	struct A *Ahead,*p1,*q1;
	struct B *Bhead,*p2,*q2;
	struct C *Chead,*p3,*q3;
	Chead=creatC();
	Ahead=creatA();
	Bhead=creatB();
	FILE*fp;
	char placenum[100],carnum[100];
	int xiaoshi,fenzhong,zd=0;
	if((fp=fopen("car.txt","r"))==NULL)
				 {
				 	fp=fopen("car.txt","w");
					fclose(fp);
					exit(0);
				 }
	 fp=fopen("car.txt","r");
	 while(fscanf(fp,"%s %s %d %d",placenum,carnum,&xiaoshi,&fenzhong)!=EOF)
	 {
	 		p1=Ahead;
	 		while(p1->next!=NULL)
	 		{
	 			if(strcmp(p1->pnumber,placenum)==0)
	 			{
	 				strcpy(p1->cnumber,carnum);
	 				p1->hour=xiaoshi;
	 				p1->min=fenzhong;
	 				zd=1;
				 }
				 p1=p1->next;
			 }
			 if(strcmp(p1->pnumber,placenum)==0)
	 			{
	 				strcpy(p1->cnumber,carnum);
	 				p1->hour=xiaoshi;
	 				p1->min=fenzhong;
	 				zd=1;
				 }
				 if(zd==0)
				 {
				 	p2=Bhead;
	 		while(p2->next!=NULL)
	 		{
	 			if(strcmp(p2->pnumber,placenum)==0)
	 			{
	 				strcpy(p2->cnumber,carnum);
	 				p2->hour=xiaoshi;
	 				p2->min=fenzhong;
	 				zd=1;
				 }
				 p2=p2->next;
			 }
			 if(strcmp(p2->pnumber,placenum)==0)
	 			{
	 				strcpy(p2->cnumber,carnum);
	 				p2->hour=xiaoshi;
	 				p2->min=fenzhong;
	 				zd=1;
				 }
				 if(zd==0)
				 {
				 	p3=Chead;
	 		while(p3->next!=NULL)
	 		{
	 			if(strcmp(p3->pnumber,placenum)==0)
	 			{
	 				strcpy(p3->cnumber,carnum);
	 				p3->hour=xiaoshi;
	 				p3->min=fenzhong;
				 }
				 p3=p3->next;
			 }
			 if(strcmp(p3->pnumber,placenum)==0)
	 			{
	 				strcpy(p3->cnumber,carnum);
	 				p3->hour=xiaoshi;
	 				p3->min=fenzhong;
				 }
				 }
		 }
	 }
	 fclose(fp);
	 p3=Chead;
	 		while(p3->next!=NULL)
	 		{
	 			if(p3->cnumber[0]!='0')
	 			{
	 				printf("%s %s %d %d\n",p3->pnumber,p3->cnumber,p3->hour,p3->min);
				 }
				 p3=p3->next;
			 }
			 if(p3->cnumber[0]!='0')
	 			{
	 				printf("%s %s %d %d",p3->pnumber,p3->cnumber,p3->hour,p3->min);
				 }
}
