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
			if(A[i][0]==B[j][0])   //�к���ȵ�ʱ�� 
			{
				
				if(A[i][1]<B[j][1])  //A��B���к��൱��A�к�С��B�к� 
				{
					C[k][0]=A[i][0];
					C[k][1]=A[i][1];
					C[k++][2]=A[i++][2]; 
					//printf("a����\n");
				}
				else if(A[i][1]>B[j][1])  //A�кŴ���B���к� 
				{	
					C[k][0]=B[j][0];
					C[k][1]=B[j][1];
					C[k++][2]=B[j++][2];
					//printf("b����\n");		 
				}
				else				   //A�к���B���к���ȵ�ʱ�� 
				{	
					z=A[i][2]+B[j][2];
					if(z!=0)
					{
						C[k][0]=B[j][0];
						C[k][1]=B[j][1];
						C[k++][2]=z;
						j++;i++;
						//printf("a+b����  ");
						//printf("z=%d\n",z);	
					}
				}
			}
			else if(A[i][0]<B[j][0])  //��A���к�С��B���к�ʱ 
			{
				C[k][0]=A[i][0];
				C[k][1]=A[i][1];
				C[k++][2]=A[i++][2]; 
				//printf("a����  \n");
			}
			else						//��A���кŴ���B���к�ʱ
			{
				C[k][0]=B[j][0];
				C[k][1]=B[j][1];
				C[k++][2]=B[j++][2]; 	
				//printf("b���� \n");
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
