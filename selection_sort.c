#include <stdio.h>
#include <time.h>

unsigned long long comparacoes = 0;
unsigned long long movimentos = 0;

int *selectionSort(int v[], int tam) {
    int tmp, menor; 

    for(int i = 0; i<tam-1; i++) {
        menor = i; 
        comparacoes++;
        for(int j =i+1; j<tam; j++) {
            if(v[j] < v[menor]) {
                menor = j; 
            }
        }

        tmp = v[i]; 
        v[i] = v[menor]; 
        v[menor] = tmp;
        movimentos++;
    }

    return v; 
}

int main(void) {

    int tam;
    scanf("%d", &tam);

    int v[tam];
    for(int i = 0; i<tam; i++)
        scanf("%d", &v[i]);

    clock_t start = clock();
    selectionSort(v, tam);
    clock_t end = clock();

    for(int i = 0; i<tam; i++) 
        printf("%d ", v[i]); 

    printf("\nComparacoes: %llu\nMovimentos: %llu\n", comparacoes, movimentos);
    printf("Tempo: %.6fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0; 
}