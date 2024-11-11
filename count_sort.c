#include <stdio.h>
#include <stdlib.h>

int find_max(int v[], int size) {
    int max_value = v[0];
    for (int i = 1; i < size; i++) {
        if (v[i] > max_value)
            max_value = v[i];
    }
    return max_value;
}

void count_sort(int v[], int size) {
    int max_value = find_max(v, size);
    int *count_array = (int*) calloc(max_value + 1, sizeof(int));

    if (count_array == NULL) {
        printf("Falha na alocação de memória para count_array\n");
        return;
    }

    for (int i = 0; i < size; i++)
        count_array[v[i]]++;

    for (int i = 1; i <= max_value; i++)
        count_array[i] += count_array[i - 1];

    int *output_array = (int*) malloc(size * sizeof(int));
    if (output_array == NULL) {
        printf("Falha na alocação de memória para output_array\n");
        free(count_array);
        return;
    }

    for (int i = size - 1; i >= 0; i--) {
        output_array[count_array[v[i]] - 1] = v[i];
        count_array[v[i]]--;
    }

    for (int i = 0; i < size; i++)
        v[i] = output_array[i];

    free(count_array);
    free(output_array);
}

void print_output(int v[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main(void) {
    int v[] = {4, 1, 2, 250, 90, 1200, 8000, 80};
    int size = sizeof(v) / sizeof(int);

    count_sort(v, size);
    print_output(v, size);

    return 0;
}
