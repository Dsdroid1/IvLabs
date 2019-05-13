#include<stdio.h>
#include<conio.h>
void main()
{	int n,m,i,j,temp,flag=0,cost=0;
	int len[100],price[100];
	float temp1;
	float ppul[100]; //An array to store the price per unit length
	clrscr();
	printf("\nEnter the length of rod in inches(n):");
	scanf("%d",&n);
	printf("\nEnter the no.of possible pieces(m):");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{	printf("\nEnter length of a piece and its cost resp.:");
		scanf("%d%d",&len[i],&price[i]);
		ppul[i]=(float)price[i]/len[i];
	}
	for(i=0;i<m-1;i++)           //Bubble sort
	{	for(j=0;j<m-i;j++)
		{	if(ppul[j]<ppul[j+1])
			{       flag=1;
				temp1=ppul[j];
				ppul[j]=ppul[j+1];
				ppul[j+1]=temp1;

				temp=price[j];
				price[j]=price[j+1];
				price[j+1]=temp;

				temp=len[j];
				len[j]=len[j+1];
				len[j+1]=temp;
			}
		}
			if(flag==0)     //To check if no swap occured,implying already sorted.
				break;
	}
	i=0;
	while(n>0&&i<m)
	{    	cost+=((int)(n/len[i]))*price[i];
		n=n%len[i];
		i++;
	}
	printf("\nThe maximum obtainable value is:%d",cost);
	getch();
}








