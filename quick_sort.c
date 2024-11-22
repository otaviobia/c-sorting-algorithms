#include <stdio.h>
#include <time.h>

unsigned long long comparacoes = 0;
unsigned long long movimentos = 0;

int mediana_de_3(int v[], int inicio, int fim) {
    int meio = (inicio + fim) / 2;

    int a = v[inicio];
    int b = v[meio];
    int c = v[fim];

    int indice_mediana = 0;

    if (a < b) {
        if (b < c) {
            indice_mediana = meio;
        } else {
            if (a < c) {
                indice_mediana = fim;
            } else {
                indice_mediana = inicio;
            }
        }
    } else {
        if (c < b) {
            indice_mediana = meio;
        } else {
            if (c < a) {
                indice_mediana = fim;
            } else {
                indice_mediana = inicio;
            }
        }
    }

    return indice_mediana;
}

void quick_sort(int v[], int inicio, int fim) {
    
    if (inicio < fim) {
        int pivo = v[mediana_de_3(v, inicio, fim)]; 
        int i, j; 
        int tmp; 

        i = inicio; 
        j = fim; 

        do {
            while(v[i] < pivo) 
            {
                comparacoes++;
                i++; 
            }
            while(v[j] > pivo) 
            {
                comparacoes++;
                j--; 
            }

            if (j >= i) {
                tmp = v[i]; 
                v[i] = v[j]; 
                v[j] = tmp;
                movimentos++;
                i++; 
                j--; 
            }
        } while(i<j); 

        quick_sort(v, inicio, j); 
        quick_sort(v, i, fim); 
    }
}

int main(void) {
    
    int tam;
    scanf("%d", &tam);

    int v[tam];
    for(int i = 0; i<tam; i++)
        scanf("%d", &v[i]);

    clock_t start = clock();
    quick_sort(v, 0, tam-1); 
    clock_t end = clock();

    for(int i = 0; i<tam; i++) 
        printf("%d ", v[i]); 

    printf("\nComparacoes: %llu\nMovimentos: %llu\n", comparacoes, movimentos);
    printf("Tempo: %.6fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0; 
}