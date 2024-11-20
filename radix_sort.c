#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long comparacoes = 0;
unsigned long long movimentos = 0;

void count_sort(int *array, int n, int exp);
void radix_sort(int *array, int n);
void print_output(int *array, int n);

int main(void) {

    int tam;
    scanf("%d", &tam);

    int v[tam];
    for(int i = 0; i<tam; i++)
        scanf("%d", &v[i]);

    clock_t start = clock();
    radix_sort(v, tam); 
    clock_t end = clock();

    print_output(v, tam);

    printf("\nComparacoes: %llu\nMovimentos: %llu\n", comparacoes, movimentos);
    printf("Tempo: %.6fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

void count_sort(int *array, int n, int exp) {
    int *output = (int*) malloc(n * sizeof(int));
    int count[10] = {0};

    comparacoes+=n;
    for (int i = 0; i < n; i++) {
        int index = (array[i] / exp) % 10;
        count[index]++;
    }

    comparacoes+=9;
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        comparacoes++;
        int index = (array[i] / exp) % 10;
        output[count[index] - 1] = array[i];
        movimentos++;
        count[index]--;
    }
    comparacoes++;

    comparacoes+=n;
    for (int i = 0; i < n; i++) {
        movimentos++;
        array[i] = output[i];
    }

    free(output);
}

void radix_sort(int *array, int n) {
    int max = array[0];

    for (int i = 1; i < n; i++) {
        comparacoes+=2;
        if (array[i] > max) {
            movimentos++;
            max = array[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        comparacoes++;
        count_sort(array, n, exp);
    }
    comparacoes+=2;
}

void print_output(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
