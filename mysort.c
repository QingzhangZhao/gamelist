#include"mysort.h"
void mergeSort(int a[],int left,int right)
{
	int i;
	if(left < right)
	{
		i = (left+right)/2;
		mergeSort(a,left,i);
		mergeSort(a,i+1,right);
		merge(a,left,right);
	}
}

void merge(int a[],int left,int right)
{
	int begin1 = left;
	int mid = (left+right)/2 ;
	int begin2 = mid+1;
	int k=0;
	int newArrayLen = right-left+1;
	int *b = (int*)malloc(newArrayLen*sizeof(int));
	while(begin1<=mid && begin2<=right)
	{
		if(a[begin1]<=a[begin2])
			b[k++] = a[begin1++];
		else
			b[k++] = a[begin2++];
	}
	while(begin1<=mid)
		b[k++] = a[begin1++];
	while(begin2<=right)
		b[k++] = a[begin2++];
	copyArray(b,a,newArrayLen,left);
	free(b);
}

void copyArray(int source[], int dest[],int len,int first)
{
	int i;
	int j=first;
	for(i=0;i<len;i++)
	{
		dest[j] = source[i];
		j++;
	}
		
}
//int main ()
//{
//	int a[] = {5, 18, 151, 138, 160, 63, 174, 169, 79, 200};
//	int len = sizeof(a)/sizeof(int);
//	mergeSort(a,0,len-1);	
//	int i;
//	for (i=0;i<len;i++)
//		printf("%d\n",a[i]);
//return 0;
//}
