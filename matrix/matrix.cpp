#include <stdlib.h>
#include <stdio.h>

void* mymalloc(unsigned int size)
{
	void* memory = malloc(size);
	if(memory == NULL)
	{
		printf("Blad alokacji pamieci - brak pamieci.\n");
		abort();
	}
	return memory;
}

double** matrix_alloc(int n)
{
    double** matrix = (double**)mymalloc(n*sizeof(double*));
    for(int i=0; i<n; i++)
    {
        matrix[i]= (double*)mymalloc(n*sizeof(double));
	}
    return matrix;
}

void matrix_free(double** matrix, int n)
{
    for(int i=0; i<n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

double det(double ** matrix, int n)
{
    double** minor;
    double sum=0.0;
    double sign=1.0;
    if(n==1) 
    {
    	return matrix[0][0];
   	}
    minor=matrix_alloc(n-1);
    for(int i=0;i<n;i++)
    {
        /* skopiuj odp. podmacierz do minor */
        for(int x=1; x<n; x++)
        {
            for(int y=0; y<n; y++)
            {
                if(y < i)
                {
                    minor[x-1][y] = matrix[x][y];
                }
                else if(y > i) 
                {
                    minor[x-1][y-1] = matrix[x][y];
                }
            }
        }

        sum+=sign*matrix[0][i]*det(minor,n-1);
        sign = -sign;
    }
    matrix_free(minor, n-1);
    return sum;
}

int main()
{
    int n;
    double** matrix;
    FILE * f = fopen("file.txt", "r");
    if (f == NULL)
	{
		printf("Error! Nie mozna otworzyc pliku.\n"); 
		return 1;
	}

	if(fscanf(f, "%d", &n) != 1 || n <= 0)
	{
		printf("Error! Niepoprawny rozmiar macierzy.\n");
		return 2;
	}
    matrix = (double**)mymalloc(n*sizeof(double*));
    for(int i=0; i<n; i++)
    {
        matrix[i]= (double*)mymalloc(n*sizeof(double));
        for(int j=0; j<n; j++)
        {
            if(fscanf(f, "%lf", &matrix[i][j]) != 1)
            {
				printf("Error! Nie udalo sie odczytac wartosci w pliku z macierza (kolumna %d wiersz %d)\n", i, j);
				return 3;
            }
        }
    }
    fclose(f);

    printf("Wyznacznik = %f\n", det(matrix, n));
    
    matrix_free(matrix, n);
	return 0;
}
