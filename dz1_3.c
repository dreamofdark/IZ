#include <stdio.h>
#include <stdlib.h> 

int* find_maximum(size_t n, int* array, const size_t m);
void print(const size_t count, int* array);
int* read(size_t* N, size_t* M);

int main() {

	size_t N = 0, M = 0;
	int* numbers = read(&N,&M);

	if (numbers == NULL) {
		printf("%s\n", "[error]");
		return 0;
	}

	int *maximum = find_maximum(N, numbers, M);
	print(M, maximum);

	free(numbers);
	free(maximum);

	return 0;
}

int* find_maximum(size_t n, int* array, const size_t m) {

	int *maximum = malloc(m * sizeof(int));

	for (size_t j = 0; j < m; ++j) {
		maximum[j] = array[0];
		size_t max_index = 0;
		for (size_t i = 1; i < n; i++) {
			if (maximum[j] < array[i]) {
				max_index = i;
				maximum[j] = array[i];
			}
		}
		n--;
		for (size_t i = max_index; i < n; i++)
			array[i] = array[i+1];
	}
	return maximum;
}

void print(const size_t count, int *array) {
	for (size_t i = 0; i < count; i++)
		printf ("%d ", array[i]);
	printf ("\n");	
}

int* read(size_t* N, size_t* M) {
	if ( scanf("%zu", N) == 0)
		return NULL;
	if (*N <= 0)
		return NULL;

	int* numbers = malloc( (*N) * sizeof(int));
	if (!numbers) 
		return NULL;

	size_t count = 0;
	while (count < (*N) && scanf("%d", &numbers[count]) == 1)
		count++;

	if (count != (*N)) {
		free(numbers);
		return NULL;
	}

	if (scanf("%zu", M) == 0)
		return NULL;

	if (*M > *N) { 
		free(numbers);
		return NULL;
	}

	return numbers;
}




