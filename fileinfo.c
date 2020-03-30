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
	while(p!=0)    //大循环 
	{
		//printf("p=%d\n",p->Data);
		x=p;	//x用来遍历相同的数，并且执行删除 
		while(x->Link!=0)	
		{
			//printf("小循环遍历的为: %d\n",x->Link->Data);
		 	if(x->Link!=0 && x->Link->Data==p->Data) x->Link=x->Link->Link;  //如果x不是尾巴  and x的下一个和p相同，删除x的下一个 
			else if(x->Link->Data!=p->Data) x=x->Link;				//如果x的下一个和p不相同，移动x 
		}
		p=p->Link;
	} 
}

