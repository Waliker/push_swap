#include <stdlib.h>
#include <stdio.h>
#include "libft/ft_printf/libftprintf.h"

void QuickSort(int A[],int start,int end, int *count);

int Partition(int A[],int start,int end, int *count);

int main()
{
	int A[1000],n,i,count;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("\nEnter the elements: ");
	count = 0;
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	QuickSort(A,0,n-1, &count);
	printf("The sorted list is :  ");
	for(i=0;i<n;i++)
		printf("%d  ",A[i]);
	printf("\nNombre de coups : %d\n", count);
	return 0;
}

void QuickSort(int A[],int start,int end, int *count)
{
	int pIndex;
	if(start<end)
	{
		pIndex=Partition(A,start,end, count);
		QuickSort(A,start,pIndex-1, count);
		QuickSort(A,pIndex+1,end, count);
	}
}

int Partition(int A[],int start,int end, int *count)
{
	int pivot,i,pIndex,temp,temp2;
	pivot=A[end];
	ft_printf("Pivot : %d\n", pivot);
	i = start;
		ft_printf("tableau a sort : ");
	while (i < end)
	{
		ft_printf("%d ", A[i]);
		i++;
	}
	ft_printf("\n");
	pIndex=start;
	for(i=start;i<end;i++)
	{
		if(A[i]<=pivot)
		{
			temp=A[i];
			A[i]=A[pIndex];
			A[pIndex]=temp;
			pIndex=pIndex+1;
			(*count)++;
		}
	}
	temp2=A[pIndex];
	A[pIndex]=A[end];
	A[end]=temp2;
	(*count++);
	return pIndex;
}
