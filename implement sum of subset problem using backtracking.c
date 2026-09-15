#include <stdio.h>
int n , target;
int a[100];
int subset[100];
int results[100][100];
int resultSize[100];
int count = 0;

void backtrack(int index , int sum , int size)
{
	if(sum == target)
	{
		for(int i = 0 ; i<size;i++)
			results[count][i] = subset[i];
		resultSize[count] = size;
		count++;
		return;
	}
	if (index == n || sum > target)
		return;
	subset[size] = a[index];
	backtrack(index+1,sum +a[index],size+1);

	backtrack(index+1,sum,size);
}

int main()
{
	scanf("%d",&n);
	for(int i = 0 ; i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&target);
	backtrack(0,0,0);
	if(count==0)
	{
		printf("-1\n");
	}
	else{
		for(int i = count-1 ; i>=0;i--)
			{
				for(int j = 0 ; j<resultSize[i];j++){
					if(j>0)
						printf(" ");
					printf("%d", results[i][j]);
					
				}
				printf(" \n");
			}
		
	}
	return 0 ;
}
