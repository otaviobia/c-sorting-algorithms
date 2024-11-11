#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *v, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        merge_sort(v, inicio, meio);
        merge_sort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

void merge(int *v, int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *left = (int*) malloc(n1 * sizeof(int));
    int *right = (int*) malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        left[i] = v[inicio + i];
    for (j = 0; j < n2; j++)
        right[j] = v[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            v[k] = left[i];
            i++;
        } else {
            v[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = right[j];
        j++;
        k++;
    }

    free(left);
    free(right);
}

void print_array(int *v, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main(void) {
    int v[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(v) / sizeof(v[0]);

    merge_sort(v, 0, size - 1);
    print_array(v, size);

    return 0;
}
