#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void binary_search(int arr[],int left,int right,int num,int n){
	bool flag=false;
	while(left<=right){
		int mid=left+(right-left)/2;
		if (arr[mid]==num){
			printf("%d found at %d",num,mid);flag=true;break;
		}
		else if(arr[mid]>num){
			right=mid-1;
		}
		else if(arr[mid]<num){
			left=mid+1;
		}	
	}
	if (flag==false){
		printf("no not in array");
	}
}
void linear_search(int arr[],int n,int num){int i;
	bool flag=false;
	for (i=0;i<n;i++){
		if (arr[i]==num){
			printf("element fount at %d",i);
			flag=true;
		}
		else{
			continue;
		}
	}
	if (flag==false){
		printf("element not found in arry");
	}
}
int main(){
	int n,i,num;
	printf("enter no of elements");
	scanf("%d",&n);
	int arr[n];
	for (i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("enter element to be searched for");
	scanf("%d",&num);
	linear_search(arr,n,num);
	binary_search(arr,0,n-1,num,n);
	return 0;
}
