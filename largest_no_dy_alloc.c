#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,num;
	float *data;
	printf("Enter the total number of elements\n");
	scanf("%d",&num);
	data = (float*)malloc(sizeof(float));
	if (data==NULL)
	{
		printf("memory not allocated\n");
		exit(0);
	}
	for(i=0;i<num;i++)
	{
		printf("Enter the numbers\n");
		scanf("%f",data+i);
	}
	for(i=0;i<num;i++)
	{
		if(*data<*(data+i))
		*data = *(data +1);
	}
	printf("Largest element is %1.2f",*data);
	free(data);
}

	
		
	

