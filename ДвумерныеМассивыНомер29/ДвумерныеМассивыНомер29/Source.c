#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void result(int(**a), int* b, int* x, int n) //Функция умножения матрицы на решение, поиск вектора
{
	for (int i = 0; i < n; i++)
	{
		b[i] = 0;
		for (int j = 0; j < n; j++)
			b[i] += a[i][j] * x[j];
		printf("%d ", b[i]);
	}
}

//Заполнение матрицы и решения рандомными элементами. Поиск вектора(умножение матрицы на решение) через функцию
int main()
{
	srand(time((NULL)));
	int n = 0;
	int** a = NULL, * x = NULL, * b = NULL;
	scanf_s("%d", &n);
	a = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		a[i] = (int*)malloc(sizeof(int*) * n);
	x = (int*)malloc(sizeof(int*) * n);
	b = (int*)malloc(sizeof(int*) * n);;

	printf("Matrix (random enter)");
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 11 - 5;
			printf("%4d ", a[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		x[i] = rand() % 11 - 5;
	}

	printf("\nSolution (random enter) \n");
	for (int i = 0; i < n; i++)
		printf("%d ", x[i]);

	printf("\nResult: Vector \n");
	result(a, b, x, n);

	printf("\nResult: Matrix with vector \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d ", a[i][j]);
		}
		printf(" | %d", b[i]);
		printf("\n");
	}
	for (int i = 0; i < n; i++)
	{
		free(a[i]);
	}
	free(a);
	return 0;
}