#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu_node
{
	char name[100];
	struct stu_node *next;
};
#define LEN sizeof(struct stu_node)
struct stu_node *creat(void)
{
	struct stu_node *p1=NULL,*p2=NULL;
	struct stu_node *head=NULL;
	char s[100];
	gets(s);
	while(s[0]!='#')
	{
		p1=(struct stu_node*)malloc(LEN);
		strcpy(p1->name,s);
		if(head==NULL)
		{
			head=p1;
		}
		else  p2->next=p1;
		p2=p1;
		gets(s);
	}
	p2->next=NULL;
	return head;
}
void list(struct stu_node *head)
{
	int n=0;
	struct stu_node *p;
	p=head;
	while(p!=NULL)
	{
		puts(p->name);
		p=p->next;
		n++;
	}
	printf("%d\n",n);
}
struct stu_node *del(struct stu_node *head,struct stu_node *q)
{
	struct stu_node *p1,*p2=NULL;
		p1=head;
		while(strcmp(p1->name,q->name)!=0&&(p1->next!=NULL))
		{
			p2=p1;
			p1=p1->next;
		}
		if(strcmp(p1->name,q->name)==0)
		{
			if(p1==head)
			head=p1->next;
			else
			p2->next=p1->next;
			free(p1);
		}
		return head;
}
void liste(struct stu_node *head)
{
	int n=0;
	struct stu_node *p;
	p=head;
	while(p!=NULL)
	{
		puts(p->name);
		p=p->next;
		n++;
	}
	printf("%d",n);
}
int main ()
{
	struct stu_node *head,*q;
	q=(struct stu_node*)malloc(LEN);
	head=creat();
	gets(q->name);
	list(head);
    head=del(head,q);
    liste(head);
    return 0;
}
