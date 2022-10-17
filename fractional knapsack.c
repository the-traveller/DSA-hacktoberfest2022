include<stdio.h>
#include<stdlib.h>
typedef struct list {
	int profit;
	int weight;
	float ratio;
}list;
void bubbleSort(list*array,int n){
	for (int i =0;i<n-1;i++){
		for (int j=0;j<n-i-1;j++){
			if (array[j].ratio < array[j+1].ratio){
				list temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
}
float*knapsack(list*array,int n,int capacity){
	float*result=(float*)malloc(n*sizeof(float));
	for (int i=0;i<n;i++){
		if (capacity<=array[i].weight) result[i]=1.0;
		else result[i]=array[i].weight/capacity;
		capacity -= array[i].weight*result[i] ;
	}
	return result;
}

int main(){
	//input section
	int n;
	printf("Enter the number of objects: ");
	scanf("%d",&n);
	list *array=(list*)malloc(n *sizeof(list));
	for(int i=0;i<n;i++){
		printf("Enter the profit and weight for item number %d",i+1);
		scanf("%d%d",&array[i].profit,&array[i].weight);
		float ratio=array[i].profit/array[i].weight;
  		array[i].ratio=ratio;
	}

	int capacity;
	printf("Enter the capacity of knapsack: ");
	scanf("%d",&capacity);

	//sorting
	bubbleSort(array,n);	
	//knapsack call
	float * result=knapsack(array,n,capacity);
	for(int i=0;i<n;i++)		printf("%f",result[i]);


	return 0;
}
