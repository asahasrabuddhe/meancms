#include<stdio.h>
#include<stdbool.h>

bool iscoprime(int no1, int no2) 
{
	int temp;
    while( no2 != 0 )
	{
		temp = no1 % no2;
		no1 = no2;
		no2 = temp;
	}
	if (no1 == 1)
		return true;
	else
		return false;
} 

bool isvalueinarray(int val, int *arr, int size){
    int i;
    for (i = 0; i < size; i++) {
    	if (arr[i] == val)
        	return true;
    }
    return false;
}

int main() {
	int input[5] = {2, 3, 4, 5, 6};
	int input_size = 5;
	int co_prime = 2;
	int i,j,g = 0;
	int count = 0;
	int output[10][2];
	int output_size = 10;
	int op = -1;

	for( i = 0; i < input_size; i++ ) {
		for( j = i + 1; j < input_size; j++ ) {
			if( i == j ) {
				continue;
			} else {
				output[count][0] = input[i] * input[j];
//				printf("count = %d, output = %d\n", count+1, output[count][0]);
				count++;
			}
		}
	}

	for( i = 0; i < output_size; i++ ) {
//		printf( "b%d %d\n", output[i][0], output[i][1]);
		if( isvalueinarray( output[i][0], input, input_size) == false ) {
			output[i][1] = iscoprime( output[i][0], co_prime );
//			printf( "a%d %d\n", output[i][0], output[i][1]);
		}
	}
	
	for( i = 0; i < output_size; i++ ) {
//		printf("%d %d\n", output[i][0], output[i][1]);
		if( output[i][1] == true ) {
			if( op == -1)
				op = output[i][0];
			if( output[i][0] < op )
				op = output[i][0];
		}
	}

	printf("%d", op);

	return 0;
}