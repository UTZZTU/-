#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu_node
{
	char name[100000];
	struct stu_node *next;
};
#define LEN sizeof(struct stu_node)
struct stu_node *creat(void)
{
	struct stu_node *p1=NULL,*p2=NULL;
	struct stu_node *head=NULL;
	char name[100000];
	gets(name);
	while(name[0]!='#')
	{
		p1=(struct stu_node*)malloc(LEN);
		strcpy(p1->name,name);
		if(head==NULL)
		{
			head=p1;
		}
		else  p2->next=p1;
		p2=p1;
		gets(name);
	}
	p2->next=NULL;
	return head;
}
void list(struct stu_node*head)
{
	struct stu_node *p;
	if(head==NULL)
	{
		printf("¿ÕÁ´±í");
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		{
			printf("%s\n",p->name);
			p=p->next;
		}
			printf("%s",p->name);
	}
}
int main ()
{
	struct stu_node *head;
	head=creat();
	list(head);
	return 0;
}

