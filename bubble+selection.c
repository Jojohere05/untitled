#include<stdio.h>
void swap(int *a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partion(int arr[],int low,int high){
	int pivot=arr[high];
	int i=(low-1),j;
	for (j=low;j<high;j++){
		if (arr[j]<pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}swap(&arr[i+1],&arr[high]);
	return i+1;
}
void quicksort(int arr[],int low,int high){
	if(low<high){

	int pi=partion(arr,low,high);
	quicksort(arr,0,pi-1);
	quicksort(arr,pi+1,high);}
}
void insertionsort(int arr[],int n){
	int i,j;
	for (i=1;i<n;i++){
		int val=arr[i];
		int j=i-1;
		while (j>=0 && arr[j]>val){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=val;
	}
}
void selectionsort(int arr[],int n){
	int i,j;
	for (i=0;i<n-1;i++){
		int minindex=i;
		for (j=i+1;j<n;j++){
			if(arr[j]<arr[minindex]){
				minindex=j;
			}
		}
		int temp=arr[minindex];
		arr[minindex]=arr[i];
		arr[i]=temp;
	}
}
void bubblesort(int arr[],int n){
	int i,j;
	for (i=0;i<n-1;i++){
		for (j=0;j<n-1-i;j++){
			if (arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
void printarray(int arr[],int n){int i;
	for (i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){
	int n,i;
	printf("enter no of elements\n");
	scanf("%d",&n);
	int arr[n],arr1[n],arr2[n],arr3[n];/*
	for (i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("the unsorted array\n");
	printarray(arr,n);
	printf("the sorted array after bubble sort\n");
	bubblesort(arr,n);
	printarray(arr,n);
	for (i=0;i<n;i++){
		scanf("%d",&arr1[i]);
	}
	printf("the sorted array after selection sort\n");
	selectionsort(arr1,n);
	printarray(arr1,n);
	for (i=0;i<n;i++){
		scanf("%d",&arr2[i]);
	}
	printf("the sorted array after insertion sort\n");
	insertionsort(arr2,n);
	printarray(arr2,n);*/
	for (i=0;i<n;i++){
		scanf("%d",&arr3[i]);
	}
	printf("the sorted array after Quick sort\n");
	quicksort(arr3,0,n-1);
	printarray(arr3,n);
	return 0;
}
