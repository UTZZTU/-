#include <stdio.h>
#include <stdlib.h>
struct stu_node
{
	int sum;
	struct stu_node *next;
};
#define LEN sizeof(struct stu_node)
struct stu_node *creat(void)
{
	struct stu_node *p1=NULL;
	struct stu_node *head=NULL;
	int n;
	scanf("%d",&n);
	while(n!=0)
	{
		p1=(struct stu_node*)malloc(LEN);
		p1->sum=n;
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
		scanf("%d",&n);
	}
	return (head);
}
void list(struct stu_node *head)
{
	struct stu_node *p;
	p=head;
	printf("%d",p->sum);
	p=p->next;
	while(p!=NULL)
	{
		printf(" %d",p->sum);
		p=p->next;
	}
}
int main ()
{
	struct stu_node *head;
	head=creat();
	list(head);
	return 0;
}
