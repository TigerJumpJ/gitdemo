#include<stdio.h>
#include<stdlib.h>
#define N 3
#define M 12500
struct node
{	
	int Data;
	struct node *Link;	
 } *H;
void sum_triple(int A[][N],int B[][N],int C[][N])
{
	int i=0,j=0,k=0,z;
	while(i<6 && j<5)
	{
		//printf("i=%d   ",i);
		//printf("j=%d  ",j);
			if(A[i][0]==B[j][0])   //行号相等的时候 
			{
				
				if(A[i][1]<B[j][1])  //A和B的行号相当，A列号小于B列号 
				{
					C[k][0]=A[i][0];
					C[k][1]=A[i][1];
					C[k++][2]=A[i++][2]; 
					//printf("a进入\n");
				}
				else if(A[i][1]>B[j][1])  //A列号大于B的列号 
				{	
					C[k][0]=B[j][0];
					C[k][1]=B[j][1];
					C[k++][2]=B[j++][2];
					//printf("b进入\n");		 
				}
				else				   //A列号与B的列号相等的时候 
				{	
					z=A[i][2]+B[j][2];
					if(z!=0)
					{
						C[k][0]=B[j][0];
						C[k][1]=B[j][1];
						C[k++][2]=z;
						j++;i++;
						//printf("a+b进入  ");
						//printf("z=%d\n",z);	
					}
				}
			}
			else if(A[i][0]<B[j][0])  //当A的行号小于B的行号时 
			{
				C[k][0]=A[i][0];
				C[k][1]=A[i][1];
				C[k++][2]=A[i++][2]; 
				//printf("a进入  \n");
			}
			else						//当A的行号大于B的行号时
			{
				C[k][0]=B[j][0];
				C[k][1]=B[j][1];
				C[k++][2]=B[j++][2]; 	
				//printf("b进入 \n");
			}
	}
}
int main()
{
	int a[6][N]={{1,1,1},{1,3,3},{2,1,2},{2,2,1},{2,3,4},{3,3,1}};
	int b[5][N]={{1,1,2},{1,2,1},{2,1,1},{3,1,1},{3,3,2}};
	int C[M][N];   
	sum_triple(a,b,C);
	int k=0;
	for(k;k<8;k++)
	{
		printf("(%d,%d,%d)",C[k][0],C[k][1],C[k][2]);
		printf("\n");
	}
	return 0;
}
