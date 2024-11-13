#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max 10
#define infinity INT_MAX
int mindist(int dist[],int visited[],int n){
	int v;
	int min=infinity,minindex;
	for (v=0;v<n;v++){
		if (visited[v]==0 &&dist[v]<min){
			min=dist[v];
			minindex=v;
		}
	}return minindex;
}
void dijkshtra(int adj[max][max],int n,int src){
	int i,count,v;
	int dist[max];
	int visited[max]={0};
	visited[src]=1;
	for (i=0;i<n;i++){
		dist[i]=adj[src][i];
}
	dist[src]=0;
	
	for (count=1;count<n;count++){
		int w=mindist(dist,visited,n);
		visited[w]=1;
		for (v=0;v<n;v++){
			if(!visited[v]&&adj[w][v]!=infinity&&dist[w]!=infinity&&(dist[w]+adj[w][v]<dist[v])){
				dist[v]=adj[w][v]+dist[w];
			}
		}
	}
	printf("Shortest distances from source vertex %d:\n", src);
	for (i = 0; i < n; i++){
    if (dist[i] == infinity) {
        printf("Vertex %d is unreachable from the source.\n", i);
    } else {
        printf("Distance to vertex %d: %d\n", i, dist[i]);
    }
}		
}
int main(){
	int adj[max][max];
	int n,src,i,j;
	printf("enter the no of vertices\n");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&adj[i][j]);
			if (i!=j && adj[i][j]==0){
				adj[i][j]=infinity;
			}
		}
		}
	printf("enter the source vertex");
	scanf("%d",&src);
	dijkshtra(adj,n,src);
	return 0;
}
