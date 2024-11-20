#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long comparacoes = 0;
unsigned long long movimentos = 0;

int find_max(int v[], int size) {
    int max_value = v[0];
    for (int i = 1; i < size; i++) {
        comparacoes+=2;
        if (v[i] > max_value)
            max_value = v[i];
    }
    comparacoes++;
    return max_value;
}

void count_sort(int v[], int size) {
    int max_value = find_max(v, size);
    int *count_array = (int*) calloc(max_value + 1, sizeof(int));

    if (count_array == NULL) {
        printf("Falha na alocação de memória para count_array\n");
        return;
    }

    comparacoes+=size;
    for (int i = 0; i < size; i++)
        count_array[v[i]]++;

    comparacoes+=max_value;
    for (int i = 1; i <= max_value; i++)
        count_array[i] += count_array[i - 1];

    int *output_array = (int*) malloc(size * sizeof(int));
    if (output_array == NULL) {
        printf("Falha na alocação de memória para output_array\n");
        free(count_array);
        return;
    }

    for (int i = size - 1; i >= 0; i--) {
        comparacoes++;
        output_array[count_array[v[i]] - 1] = v[i];
        count_array[v[i]]--;
        movimentos++;
    }
    comparacoes++;

    comparacoes+=size;
    for (int i = 0; i < size; i++) {
        movimentos++;
        v[i] = output_array[i];
    }

    free(count_array);
    free(output_array);
}

void print_output(int v[], int size) {
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
    count_sort(v, tam);
    clock_t end = clock();

    print_output(v, tam);

    printf("\nComparacoes: %llu\nMovimentos: %llu\n", comparacoes, movimentos);
    printf("Tempo: %fs\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    return 0;
}
