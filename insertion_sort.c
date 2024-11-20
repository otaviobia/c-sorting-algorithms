#include <stdio.h>
#include <time.h>

unsigned long long comparacoes = 0;
unsigned long long movimentos = 0;

void insertion_sort(int v[], int tam) {
    int tmp, j;

    for (int i = 1; i < tam; i++) {
        comparacoes++;
        tmp = v[i];
        j = i - 1;
        
        // Movendo os elementos maiores que tmp para frente
        while (j >= 0 && v[j] > tmp) {
            comparacoes++;
            movimentos++;
            v[j + 1] = v[j];
            j--;
        }
        comparacoes++;
        // Inserindo o elemento temporário na posição correta
        v[j + 1] = tmp;
    }
}

int main(void) {

    int tam;
    scanf("%d", &tam);

    int v[tam];
    for(int i = 0; i<tam; i++)
        scanf("%d", &v[i]);

    clock_t start = clock();
    insertion_sort(v, tam); 
    clock_t end = clock();

    for(int i = 0; i<tam; i++) 
        printf("%d ", v[i]); 

    printf("\nComparacoes: %llu\nMovimentos: %llu\n", comparacoes, movimentos);
    printf("Tempo: %.6fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0; 
}
