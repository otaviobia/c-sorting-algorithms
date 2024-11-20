#include <stdio.h>
#include <time.h>

unsigned long long comparacoes = 0;
unsigned long long movimentos = 0;

void contagem_de_menores(int v[], int tam); 

int main(void) {

    int tam;
    scanf("%d", &tam);

    int v[tam];
    for(int i = 0; i<tam; i++)
        scanf("%d", &v[i]);

    clock_t start = clock();
    contagem_de_menores(v, tam);
    clock_t end = clock();

    for(int i = 0; i<tam; i++) 
        printf("%d ", v[i]); 

    printf("\nComparacoes: %llu\nMovimentos: %llu\n", comparacoes, movimentos);
    printf("Tempo: %.6fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0; 
}

void contagem_de_menores(int v[], int tam) {
    int A[tam]; 
    int B[tam]; 

    for(int i = 0; i<tam; i++) {
        comparacoes++;
        A[i] = 0; 
    }
    comparacoes++;

    for(int i = 1; i<tam; i++) {
        comparacoes++;
        for(int j = i-1; j>=0; j--) {
            comparacoes+=2;
            if(v[i] < v[j]) {
                A[j]++; 
            }else 
                A[i]++; 
        }
        comparacoes++;
    }
    comparacoes++;

    for(int i = 0; i<tam; i++) {
        comparacoes++;
        B[A[i]] = v[i];
        movimentos++;
    }
    comparacoes++;

    for (int i=0; i<tam; i++) {
        comparacoes++;
        v[i]=B[i];
        movimentos++;
    }
    comparacoes++;
}