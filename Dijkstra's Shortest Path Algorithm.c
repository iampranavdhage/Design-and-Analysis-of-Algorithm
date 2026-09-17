#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999
void dijkstra(int G[MAX][MAX], int n, int startnode) {
	
	// write your code here
	int distance[MAX];
	int visited[MAX];
	int parent[MAX];
	int i,j,count;
	int minDistance, nextNode;
	for(i=1;i<=n;i++){
		distance[i]=INFINITY;
		visited[i]=0;
		parent[i]=-1;
	}
	distance[startnode]=0;

	for(count=1;count<=n-1;count++){
		minDistance = INFINITY;
			nextNode =-1;
		for(i=1;i<=n;i++){
			if(!visited[i] && distance[i]<minDistance){
				minDistance = distance[i];
				nextNode = i;
			}
		}
		if(nextNode==-1)
			break;
		visited[nextNode]=1;
		for(j=1;j<=n;j++)
			{
				if(!visited[j] && G[nextNode][j]!=0 && distance[nextNode] + G[nextNode][j]< distance[j])
				{
					distance[j]= distance[nextNode] +G[nextNode][j];
					parent[j] =nextNode;
				}
			}
		
	}
printf("Node\tDistance\tPath\n");
	for(i=1;i<=n;i++)
		{
			if(i==startnode)
				continue;
		    if(distance[i]==INFINITY){
			    printf("%4d\t%8s\tNO PATH\n",i,"INF");
		}
			else{
				int path[MAX];
				int pathLength=0;
				int current=i;
				while(current !=-1){
					path[pathLength++] = current;
					current =parent[current];
				}
				printf("%4d\t%8d\t",i,distance[i]);
				for(j=0;j<pathLength;j++){
					if(j>0)
						printf("<-");
					printf("%d" ,path[j]);
				}
				printf("\n");
			}
			
		}
}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	printf("Enter the source :");
	scanf("%d", &s);
	dijkstra(graph, V, s); 
	return 0; 
} 
