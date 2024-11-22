#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long comparacoes = 0;
unsigned long long movimentos = 0;

void merge(int *v, int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *left = (int*) malloc(n1 * sizeof(int));
    int *right = (int*) malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
    {
        movimentos++;
        left[i] = v[inicio + i];
    }
    for (j = 0; j < n2; j++)
    {
        movimentos++;
        right[j] = v[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2) {
        comparacoes++;
        if (left[i] <= right[j]) {
            movimentos++; 
            v[k] = left[i];
            i++;
        } else {
            movimentos++; 
            v[k] = right[j];
            j++;
        }
        k++;
    }
 

    while (i < n1) {
        movimentos++;
        v[k] = left[i];
        i++;
        k++;
    }
    comparacoes++;

    while (j < n2) {
        movimentos++;
        v[k] = right[j];
        j++;
        k++;
    }

    free(left);
    free(right);
}

void merge_sort(int *v, int inicio, int fim) {
    if (inicio < fim) {
        comparacoes++;
        int meio = inicio + (fim - inicio) / 2;
        merge_sort(v, inicio, meio);
        merge_sort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

void print_array(int *v, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main(void) {
    int tam;
    scanf("%d", &tam);

    int v[tam];
    for(int i = 0; i<tam; i++)
        scanf("%d", &v[i]);

    clock_t start = clock();
    merge_sort(v, 0, tam - 1); 
    clock_t end = clock();

    print_array(v, tam);

    printf("\nComparacoes: %llu\nMovimentos: %llu\n", comparacoes, movimentos);
    printf("Tempo: %.6fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
