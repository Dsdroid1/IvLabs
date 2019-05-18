//Assignment 2 by Dhruv Sharma
#include<stdio.h>
#include<conio.h>
int large(int A[],int current_index,int size);  //Gives the best possible step
int Can_Last_Be_Reached(int A[],int current_index,int n);//Checks if last element can be directly reached
int All_zero_correction(int A[],int current_index,int size);//Checks if not possible to reach the end due to some zeros
void display_path(int A[],int B[],int size);//To display the path,If not needed,comment out the fn call in last if-else.
//Best step is determined by max of A[i]+i,recursively
void main()
{	int A[100],B[100]={0}; //B is present only to store the path,if required.
	int n,i,steps=0,flag=1,current_index=0;
	clrscr();
	printf("Enter the size of the array:\n");
	scanf("%d",&n);
	printf("Enter the array elements:\n");//Scanning in A[]
	for(i=0;i<n;i++)
	{	scanf("%d",&A[i]);
	}
	if((A[0]==0)&&(n!=1))
	{     flag=0; //	printf("Not possible to reach end\n");
	}
	else if(n==1)
	{     steps=0;
	      i=0; 	
	}
	else
	{       B[0]=0;
		i=1;
		//  printf("%d(Position:0)->",A[0]);
		while(1)
		{       if((Can_Last_Be_Reached(A,current_index,n))==0)
			{       if(All_zero_correction(A,current_index,A[current_index])==1)
			       {	current_index=large(A,current_index,A[current_index]);
				    //	printf("%d(Position:%d)->",A[current_index],current_index);
					steps++;
					B[i]=current_index;
			       }
			       else
			       {	flag=0;
					break;
			       }
			}
			else
			{   //    printf("%d(Position:%d)\n",A[n-1],n-1);
				steps++;
				B[i]=n-1;
				break;
			}
			i++; //Storing path in B[],To display only if end reach is succesful.
		}
	 }
	 if(flag==1)
	 {      display_path(A,B,i);
		printf("\nThe minimum no.of of steps required are:%d",steps);
		getch();
	 }
	 else
	 {	printf("Not possible to reach the end");
		getch();
	 }

}


int large(int A[],int current_index,int size)   //Returns the index of the best possible largest step
{	int i=current_index+1,max=A[current_index+1]+current_index+1,index=current_index+1;     //size is value of element with current_index
	for(;i<=current_index+size;i++)
	{	if((max<A[i]+i)&&(A[i]!=0))
		{	max=A[i]+i;
			index=i;
		}
	}
	return index;
}

int Can_Last_Be_Reached(int A[],int current_index,int n)
{	if(A[current_index]>=n-1-current_index)
		return 1;
	else
		return 0;
}

int All_zero_correction(int A[],int current_index,int size) //If after a particular stage all possible steps result to zero,which is not last
{	int i,flag=0;
	for(i=current_index;i<=current_index+size;i++)
	{	if(A[i]!=0)
		{	flag=1;
			break;
		}
	}
	return flag;

}

void display_path(int A[],int B[],int size)
{	int i;
	for(i=0;i<size;i++)
	{	printf("%d(Position:%d)->",A[B[i]],B[i]);
	}
	printf("%d(Position:%d)",A[B[size]],B[size]);
}
