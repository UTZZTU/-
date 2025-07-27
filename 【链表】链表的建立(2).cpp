#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu_node
{
	long long int number;
	char name[100];
	int num;
	struct stu_node *next;
};
#define LEN sizeof(struct stu_node)
struct stu_node *creat(void)
{
	struct stu_node *p1=NULL;
	struct stu_node *head=NULL;
	long long int n,num;
	char name[100];
	scanf("%lld",&n);
	while(n!=0)
	{
		scanf("%s",name);
		scanf("%d",&num);
		p1=(struct stu_node*)malloc(LEN);
		p1->number=n;strcpy(p1->name,name);
		p1->num=num;
		if(head==NULL)
		{
			head=p1;
			p1->next=NULL;
		}
		else  
		{
			p1->next=head;
		 	head=p1;
		}
		scanf("%lld",&n);
	}
	return head;
}
void list(struct stu_node*head)
{
	struct stu_node *p;
	int sum=0,n=0;
		p=head;
		while(p!=NULL)
		{
			printf("%lld %s %d\n",p->number,p->name,p->num);
			sum+=p->num;
			n++;
			p=p->next;
		}
		printf("%.2f\n",sum*1.0/n);
}
int main ()
{
   struct stu_node *head;
	char s[100];
	while(1)
	{
	head=creat();
	list(head);
	gets(s);
	}
	return 0;
}
