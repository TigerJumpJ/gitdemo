#include<stdio.h>
#include<stdlib.h>
#define N 3
#define M 12500
struct node
{	
	int Data;
	struct node *Link;	
 } *H;
void delete_same(struct node **H)
{
	struct node *p,*x;
	p=*H;
	while(p!=0)    //��ѭ�� 
	{
		//printf("p=%d\n",p->Data);
		x=p;	//x����������ͬ����������ִ��ɾ�� 
		while(x->Link!=0)	
		{
			//printf("Сѭ��������Ϊ: %d\n",x->Link->Data);
		 	if(x->Link!=0 && x->Link->Data==p->Data) x->Link=x->Link->Link;  //���x����β��  and x����һ����p��ͬ��ɾ��x����һ�� 
			else if(x->Link->Data!=p->Data) x=x->Link;				//���x����һ����p����ͬ���ƶ�x 
		}
		p=p->Link;
	} 
}
int main(){
	int b,i;
	int A[10]={1,1,1,7,9,22,33,44,22,22};
	struct node *p;
	H=(struct node *)malloc(sizeof(struct node));
	H->Data=A[0];H->Link=0;
	p=H;
	for(i=1;i<10;i++){
		p->Link=(struct node*)malloc(sizeof(struct node));
		p=p->Link;
		p->Data=A[i];
		p->Link=0; } 
	p=H;
	delete_same(&H);
	printf("\n");
	while(p!=0){
		printf("%d  ",p->Data);
		p=p->Link;		
	} 	 	
}
