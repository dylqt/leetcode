#include <stdio.h>
#include <stdlib.h>
int uniquePaths(int m, int n) {
	int *v = (int *)malloc(n * sizeof(int));
	v[0] = 1;
	for (int i = 1; i < m; ++i){
		for (int j = 1; j < n; ++j){
			v[j] += v[j - 1];
			printf("%d ", v[j]);
		}
		printf("\n");
	}
	printf("%d\n", v[n - 1]);
	return v[n - 1];
}

int main()
{
	int i = uniquePaths(1, 2);
}