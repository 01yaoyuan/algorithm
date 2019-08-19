#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
typedef struct {
	int length;
	int *p;
}SqList;
void CreateSqList(SqList *L,int n)
{
	int i,j;
	L->length=n;
	L->p=(int *)malloc(n*sizeof(int));
	for(i=0;i<L->length;i++)
	scanf("%d",&(L->p[i]));
	
}
void CreateSqList1(SqList *L,int n)
{
	int i,j;
	L->length=n;
	L->p=(int *)malloc(n*sizeof(int));
	for(i=1;i<=L->length;i++)
	scanf("%d",&(L->p[i]));
	
}
void Destroy(SqList *L)
{	L->length=0;
	free(L);
	
}
void Print1(SqList L)
{	int i;
	for(i=1;i<=L.length;i++)
	printf("%d ",L.p[i]);
}
void Print(SqList L)
{	int i;
	for(i=0;i<L.length;i++)
	printf("%d ",L.p[i]);
}
void input(int a[],int n)
{
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
}
void output(int a[],int n)
{
	for(int i=1;i<=n;i++)
	printf("%d ",a[i]);
	printf("\n");
}
void Swap(SqList *L,int i,int j)
{
	int temp=L->p[j];
	L->p[j]=L->p[i];
	L->p[i]=temp;
}
int  Partition(SqList *L,int low,int high)
{	int Pivot;
	Pivot=L->p[low];
	while(low<high)
	{
		while(low<high && L->p[high]>=Pivot)
		high--;
		Swap(L,low,high);
		while(low<high && L->p[low]<=Pivot)
		low++;
		Swap(L,low,high);
	}
	return low;
}
void Sort(SqList *L,int low,int high)
{
	int pivot;//定义一个中枢位置；
	if(low<high)
	{
		pivot=Partition(L,low,high);
		Sort(L,low,pivot-1);
		Sort(L,pivot+1,high);
	 } 
}
void Quicksort(SqList *L)
{	
	Sort(L,0,L->length-1);
}

void QuickSort(int p[],int low,int high)
{
	int i,j,term;//定义term作为中间枢纽；
	i=low,j=high;
	if(low<high)
	{term=p[low];
		while(i<j)
		{
			while(i<j&&p[j]>=term)
				j--;
			if(i<j)
			{
				p[i]=p[j];
				i++;		
			} 
			while(i<j&&p[i]<term)
				i++;
			if(i<j)
			{
				p[j]=p[i];
				j--;	
			}
			
		}
		p[i]=term;
		QuickSort(p,low,i-1);
		QuickSort(p,i+1,high);
		
	 } 
	
}//两种版本的快排；
void SelectSort(SqList *L) 
{
	int i,j,min;
	for(i=0;i<L->length;i++)
	{
		min=i;
		for(j=i+1;j<L->length;j++)
		{
			if(L->p[j]<L->p[min])
				min=j;
			
			
		}
		if(min!=i)
		Swap(L,i,min);
	}
}//简单选择排序；
/*void InsertSort(SqList *L)
{
	int i,j,temp;
	 
	for(i=1;i<L->length;i++)
	{
			if(L->p[i]<L->p[i-1])
		{
			temp=L->p[i];
			for(j=i-1;L->p[j]>temp;j--)
				L->p[j+1]=L->p[j];
			L->p[j]=temp;
				
		}
	 } 
 } 
*/

void InsertSort(int a[],int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		if(a[i]<a[i-1])
		{
			a[0]=a[i]; 
			for(j=i-1;a[j]>a[0];j--)
				a[j+1]=a[j];
			a[j+1]=a[0];
		}
	}
}
void Insert(int a[],int gap,int i)
{
	int insert=a[i],j;
	for(j=i-gap;j>=0&&insert<a[j];j-=gap)
	a[j+gap]=a[j];
	a[j+gap]=insert;
}
void ShellSort(int a[],int n)
{	int i,j,k,N,gap;
	N=n;
	for(gap=N/2;gap>0;gap/=2)
		for(i=gap;i<N;i++)
		{
			Insert(a,gap,i);
		}
}
void HeapAdjust(SqList *L,int s,int m)
 {
 	int i,j,temp;
 	temp=L->p[s];
 	for(j=2*s;j<=m;j*=2)
 	{
 		if(j<m&&L->p[j]<L->p[j+1])
 		j++;
 		if(temp>=L->p[j])
 		break;
 		L->p[s]=L->p[j];
 		s=j;
	 }
	 L->p[s]=temp;
 }
void HeapSort(SqList *L)
{
	int i,j;
	for(i=L->length/2;i>0;i--)
	{
		HeapAdjust(L,i,L->length);
	 } 
	 for(i=L->length;i>1;i--)
	 {
	 	Swap(L,1,i);
	 	HeapAdjust(L,1,i-1);
	 }
 } 
 
