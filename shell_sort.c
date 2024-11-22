#include <stdio.h>
#include <time.h> 

unsigned long long comparacoes = 0;
unsigned long long movimentos = 0;

void shell_sort(int *v, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = v[i];
            int j;
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
                comparacoes++; 
            }
            v[j] = temp;
            movimentos++;  
        }
    }
}

void print_array(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int tam;
    scanf("%d", &tam);

    int v[tam];
    for(int i = 0; i<tam; i++)
        scanf("%d", &v[i]);

    clock_t start = clock();
    shell_sort(v, tam);
    clock_t end = clock();

    printf("\nComparacoes: %llu\nMovimentos: %llu\n", comparacoes, movimentos);
    printf("Tempo: %.6fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;

}
