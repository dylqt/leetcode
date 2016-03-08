#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
	// maintain a maximum be result, and init it to be 0;
	if (matrixRowSize == 0 || matrixColSize == 0)
		return 0;
	// memorize a array
	int **result = (int **)malloc(matrixRowSize * sizeof(int *));
	for (int i = 0; i < matrixRowSize; i++){
		result[i] = (int *)malloc(matrixColSize * sizeof(int));
	}
	int s_max = matrix[0][0] - '0';
	//find the max from first row and first col
	for (int i = 0; i < matrixRowSize; i++){
		result[i][0] = matrix[i][0] - '0';
		if (result[i][0] == 1)
			s_max = 1;
	}
	for (int i = 1; i < matrixColSize; i++){
		result[0][i] = matrix[0][i] - '0';
		if (result[0][i] == 1)
			s_max = 1;
	}
	// go over row form 1 to rowSize
	for (int row = 1; row < matrixRowSize; row++){
		// go over col form 1 to colSize
		for (int col = 1; col < matrixColSize; col++){
			// if this matrix[row][col] be 1
			if (matrix[row][col] == '1' && result[row - 1][col - 1] > 0){
				int check_num = sqrt(result[row - 1][col - 1]);
				// check matrix[row][col - sqrt(i)] to matrix[row][col - 1]
				// and check matrix[row - sqrt(i)] to maxtrix[row - 1][col]
				int i = 0;
				for (; i < check_num; i++){
					if (result[row][col - 1 - i] == 0 || result[row - 1 - i][col] == 0){
						break;
					}
				}
				// if one is 0 ,this one is 1
				// else be (i + 1)^2
				result[row][col] = (i + 1) * (i + 1);
				//max refresh
				if (s_max < result[row][col])
					s_max = result[row][col];
			}
			else{
				result[row][col] = matrix[row][col] - '0';
			}
		}
	}
	// return max
	return s_max;
}
int main()
{
	char *input[] = { "0001", "1101", "1111", "0111", "0111" };
	maximalSquare(input, 5, 4);
}