#include <stdio.h>
#include <stdlib.h>

void count_sort(int *array, int n, int exp);
void radix_sort(int *array, int n);
void print_output(int *array, int n);

int main(void) {
    int array[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(array) / sizeof(array[0]);

    radix_sort(array, n);
    print_output(array, n);

    return 0;
}

void count_sort(int *array, int n, int exp) {
    int *output = (int*) malloc(n * sizeof(int));
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int index = (array[i] / exp) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (array[i] / exp) % 10;
        output[count[index] - 1] = array[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }

    free(output);
}

void radix_sort(int *array, int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        count_sort(array, n, exp);
    }
}

void print_output(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
